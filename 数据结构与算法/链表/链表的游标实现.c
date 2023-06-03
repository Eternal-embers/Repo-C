#include<stdio.h>
#include<time.h>
#define MAXSIZE 200
#define dataType int
#define list int
#define node int
#define null 0
struct Space{
	int data;
	int next;//每一个next指向一个地址
}space[MAXSIZE];

void showSpace(){
	int i;
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("space:\n");
	for(i = null;i < MAXSIZE;i++){
		printf("%3d->%3d  ",i,space[i].next);
		if((i+1)%10 == null) putchar('\n');
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void initCursorSpace(){
	int i;
	for(i = null;i < MAXSIZE;i++){
		space[i].data = null;
		space[i].next = i + 1;
	}
	space[MAXSIZE-1].next = null;
	space[MAXSIZE-1].data = 0;
}//游标null等价于空指针，初始化空间以用于实现链表的游标实现

int spaceAlloc(){
	int p;
	p = space[null].next;//申请游标
	space[null].next = space[p].next;//游标null指向下次申请的游标
	printf(">> 分配地址%d成功，下次分配地址为%d\n",p,space[null].next);
	return p;
}//游标分配,实现malloc(),和链表很相似，通过游标null来分配空间

void spaceFree(int p){
	printf("<< 原地址%d，释放后指向%d,下次分配地址%d\n",p,space[null].next,p);
	space[p].next = space[null].next;//p游标指向的空间列入未申请的空间中
	space[null].next = p;//将要释放的空间插入到未申请的空间的头部，即null号游标所指的下次用来分配的空间
}//实现free(),头插法，将要free的游标所指空间插入到未申请的空间的头部

list createList(){
	if(isFull()) return null;
	list L = spaceAlloc();
	space[L].data = null;
	space[L].next = null;
	return L;
}

int isEmpty(list L){
	return space[L].next == null;
}

int isLast(node p,list L){
	return space[p].next == null;
}

int isFull(){
	return space[null].next == null;
}
node find(dataType data,list L){
	int p;
	p = space[L].next;
	while(p && space[p].data != data)
		p = space[p].next;
	return p;
}

node getPre(dataType data,list L){
	node t = L;
	while(t!=null){
		if(space[space[t].next].data == data)
			break;
		t = space[t].next;
	}
	return t;
}

void deleteNode(dataType data,list L){
	node p,t;
	p = getPre(data,L);
	if(p == null) {
		printf("删除结点失败，所要删除的数据%d\n",data);
		return;
	}
	printf("删除结点，地址%d,数据%d\n",space[space[p].next].next,space[space[p].next].data);
	if(!isLast(p,L)){
		t = space[p].next;
		space[p].next = space[t].next;
		spaceFree(t);
		space[L].data--;
	}
}

node insert(dataType data,list L,node p){
	node t;
	t = spaceAlloc();
	if(t == null) {
		printf("Out of space!!!\n");
		return null;
	}
	space[t].data = data;
	space[t].next = space[p].next;
	space[p].next = t;
	space[L].data++;
	printf("插入结点，地址%d,数据%d\n",p,space[p].data);
	return space[p].next;
}

void traverseList(list L){
	int cnt = null;
	node p = space[L].next;
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("链表中共有%d个结点:\n",space[L].data);
	while(p != null){
		printf("%3d(%d) -> ",space[p].data,p);
		p = space[p].next;
		cnt++;
		if(cnt % 10 == null) putchar('\n');
	}
	printf("NULL\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

int main(){
	void showSpace();
	void initCursorSpace();
	int cursorAlloc();
	void spaceFree(int p);
	list createList();
	int isEmpty(list L);
	int isLast(node p,list L);
	int isFull();
	node find(dataType data,list L);
	node getPre(node p,list L);
	void deleteNode(dataType data,list L);
	node insert(dataType data,list L,node p);
	void traverseList(list L);
	
 	initCursorSpace();
 	int i,d = null;
 	int Delete[20];
	list L = createList();
	node p;
	showSpace();
	printf("isEmpty(L):%s\n",isEmpty(L) ? "true" : "false");
	printf("isLast(L):%s\n",isLast(L,L) ? "true" : "false");
	insert(999,L,L);
	p = L;
	srand(time(NULL));
    for(i = null;i < 15;i++){
		p = insert(rand() % 1000,L,p);
		if(i % 3 == null) Delete[d++] = p;
	}
	insert(998,L,p);
	insert(997,L,find(998,L));
	insert(996,L,find(999,L));
	insert(995,L,find(999,L));
	insert(994,L,find(997,L));
	traverseList(L);
	srand((time_t)rand());
	for(i = null;i < d;i++){
		deleteNode(space[Delete[i]].data,L);
 	}
 	deleteNode(100,L);
 	deleteNode(200,L);
 	deleteNode(300,L);
 	deleteNode(400,L);
 	deleteNode(500,L);
 	deleteNode(600,L);
 	deleteNode(999,L);
 	for(i = null;i < 15;i++){
		p = insert(rand() % 1000,L,p);
		insert(rand() % 1000,L,p);
		if(i % 3 == null) Delete[d++] = p;
	}
	printf("isFull():%s\n",isFull(L) ? "true" : "false");
	traverseList(L);
	showSpace();
	return null;
}
