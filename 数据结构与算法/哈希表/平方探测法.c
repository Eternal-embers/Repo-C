#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	char* key;
	int size;//key的大小
	struct Node *next;
}Node;


typedef struct HashTable{
	struct Node *list;
	int tableSize;
	int size;
}HashTable;

/* 对字符串进行哈希，返回一个哈希值 */
int hash(const char *key,int tableSize){
	unsigned int hashVal = 0;
	while(*key != '\0'){
		hashVal = (hashVal << 5) + *key++;
	}
	return hashVal % tableSize;
}

int reHash(int hash,HashTable *table){
	int i,index;
	index = hash;
	for(i = 1;(table->list)[index].key != NULL;i++){
		index += i * i;
		if(index >= table->tableSize){
			index %= table->tableSize;
		}
	}
	return index;
}

/* 初始化哈希表 */
HashTable *initTable(int tableSize){
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	table->list = (Node *)malloc(sizeof(Node) * tableSize);
	int i;
	for(i = 0;i < tableSize;i++){
		(table->list)[i].key = NULL;
		(table->list)[i].size = 0;
		(table->list)[i].next = NULL;
	}
	table->tableSize = tableSize;
	table->size = 0;
	return table;
}

/* 释放哈希表 */
void destroyTable(HashTable *table){
	Node *list = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
			Node* node_t = &list[i];
            /* 释放节点的key */
			Node *next = node_t->next;
            free(node_t->key);
			node_t = node_t->next;
	}
	free(list);
	free(table);
}

/* 获取字符串的长度 */
int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

/* 查找key是否在哈希表中，如果不在返回NULL */
Node *find(HashTable* table,char *key){
	Node *pos = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
		if(pos->key != NULL && strcmp(pos->key,key) == 0) return pos;
		pos = &(table->list)[i];
	}
	return NULL;
}

/* 将key插入到哈希表中 */
void insert(HashTable *table,char *key){
	if(table->size > table->tableSize * 0.5) printf("哈希表空间不足！\n");
	Node *pos = find(table,key);//查找key
	if(pos == NULL) {//没有找到key
		int index = hash(key,table->tableSize);
  		Node *pos = &(table->list)[index];
		if(pos->key != NULL) pos = &(table->list)[reHash(index,table)];
		/* 插入key */
		pos->key = (char *)malloc(sizeof(char) * getLength(key));//申请存储key的空间
        strcpy(pos->key,key);
        pos->size = getLength(key);
        table->size++;
	}
	else
		return;//如果key已经存在哈希表中，则不需要再次插入key
}

/* 遍历哈希表 */
void traverseTable(HashTable *table){
	int i;
	Node *list = table->list;
	for(i = 0;i < table->tableSize;i++){
		Node *node = &list[i];
		if(node->size > 0){
			printf("%s\n",node->key);
		}
	}
}

/* 检索 */
char* retrieve(Node *node){
	return node->key;
}

int main(){
	HashTable* table = initTable(10);
	insert(table,"C++");
	insert(table,"Python");
	insert(table,"Java");
	insert(table,"PHP");
	insert(table,"Rust");
	insert(table,"hello,world");
	insert(table,"recursive");
	insert(table,"caculate");
	insert(table,"nice");
	traverseTable(table);
	printf("检索hello,world：%s\n",retrieve(find(table,"hello,world")));
	printf("检索PHP：%s\n",retrieve(find(table,"PHP")));
 	destroyTable(table);
	return 0;
}

