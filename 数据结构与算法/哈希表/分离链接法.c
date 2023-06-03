/*
    分离链接法，对key进行hash，如果计算得到的hash位置为空，直接将key存入
    如果计算所得的hash位置有数据，将其插入到该数据的后面，由此形成了链表
    在分离链接法中，hash值相同的字符串会放在同一张表中
*/
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
}HashTable;

/* 对字符串进行哈希，返回一个哈希值 */
int hash(const char *key,int tableSize){
	unsigned int hashVal = 0;
	while(*key != '\0'){
		hashVal = (hashVal << 5) + *key++;
	}
	return hashVal % tableSize;
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
	return table;
}

/* 释放哈希表 */
void destroyTable(HashTable *table){
	Node *list = table->list;
	int i;
	for(i = 0;i < table->tableSize;i++){
		Node* node_t = &list[i];
		while(node_t != NULL){
            /* 释放节点的key */
            if(node_t->size > 0) {
            	free(node_t->key);
			}
			node_t = node_t->next;
		}
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
	Node* pos = &(table->list)[hash(key,table->tableSize)];//获取key在hash表的位置
	/* 遍历pos位置所在的表 */
	Node* node_t = pos;
 	while(node_t->key != NULL){
		if(strcmp(node_t->key,key) == 0) return pos;
		node_t = node_t->next;
	}
	return NULL;
}

/* 将key插入到哈希表中 */
void insert(HashTable *table,char *key){
	Node *pos = find(table,key);//查找key
	if(pos == NULL) {//没有找到key
  		Node *pos = &(table->list)[hash(key,table->tableSize)];
		if(pos->next == NULL){
			pos->key = (char *)malloc(sizeof(char) * getLength(key));//申请存储key的空间
            strcpy(pos->key,key);
            pos->size = getLength(key);
		}
		else{
			Node *newCell = (Node *)malloc(sizeof(Node));
			newCell->size = getLength(key);
			newCell->key = (char *)malloc(sizeof(char) * newCell->size);//申请存储key的空间
			strcpy(newCell->key,key);//复制key
			/* 头插法 */
			newCell->next = pos->next;
			pos->next = newCell;
		}
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
		Node* node_t = node;
		if(node->size > 0){
			while(node_t != NULL){
				printf("%s\n",node_t->key);
				node_t = node_t->next;
			}
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
	traverseTable(table);
	printf("检索hello,world：%s\n",retrieve(find(table,"hello,world")));
	printf("检索PHP：%s\n",retrieve(find(table,"PHP")));
 	destroyTable(table);
	return 0;
}

