/*
    优先队列的实现
    对于任意节点i，其父亲在i/2处，左孩子在2i处，右孩子在2i+1处
*/
#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

/* 二叉堆 */
struct Heap{
	int capacity;//容量
	int size;//记录二叉堆最后一个元素的索引
	int *data;//一维数组表示二叉堆
};
typedef struct Heap priorityQueue;

/* 创建优先队列 */
priorityQueue *createQueue(int capacity){
 	priorityQueue *Q = (priorityQueue *)malloc(sizeof(priorityQueue));
 	Q->capacity = capacity;
 	Q->data = (int *)malloc(sizeof(int) * capacity + 1);//Q->data[0]用于存放标识，所以多申请一个空间
	Q->data[0] = -INF;//定义一个标识用于终止上滤
	Q->size = 0;
	return Q;
}

/* 插入 */
void insert(priorityQueue *Q,int data){
	if(Q->size == Q->capacity) {
		printf("优先队列已满！\n");
		return;
	}
	/* 上滤,插入法 */
	int i;
	for(i = ++Q->size;data < Q->data[i / 2];i /= 2 ){
		Q->data[i] = Q->data[i / 2];
	}
	Q->data[i] = data;//插入
}

/* 初始化优先队列 */
void initQueue(priorityQueue *Q,int data[],int length){
	int i;
	for(i = 0;i < length;i++){
  		insert(Q,data[i]);//将data[i]插入到优先队列中
	}
}

/* 遍历优先队列 */
void traverseQueue(priorityQueue *Q){
	int i;
	for(i = 1;i <= Q->size;i++){
		printf("%d(%d) ",Q->data[i],Q->data[i / 2]);
	}
	putchar('\n');
}

/* 删除最小元  */
void deleteMin(priorityQueue *Q){
	if(Q->size == 0) {
		printf("优先队列为空！");
		return;
	}
	int last = Q->data[Q->size--];//获取队列最后一个数据
	/* 删除最小元后出现空位，将下面的节点向上移动，last如果符合空位条件，直接将last放到空位上 */
	/* 下滤 */
	int i,child;
	for(i = 1;i * 2 <= Q->size;i = child){
		/* 获取左右孩子中更小的那个 */
		child = 2 * i;
		if(Q->data[child + 1] < Q->data[child])
			child++;
		/* 判断last是否符合空位 */
		if(last < Q->data[child])//如果last比左右孩子都小
			break;
		else
			Q->data[i] = Q->data[child];//较小的孩子上移到其父亲的位置
	}
	Q->data[i] = last;
}

/* 查找关键字 */
int find(priorityQueue *Q,int key){
	int i;
	for(i = 1;i <= Q->size;i++){
		if(Q->data[i] == key) return i;
	}
	return 0;
}

/* 提高关键字的值 */
void increaseKey(priorityQueue *Q,int alter,int key){
	int index = find(Q,key);
	if(index == 0){
		printf("优先队列中不存在%d关键字\n",key);
		return;
	}
	else {
		/* 下滤 */
		int i,child;
		key += alter;//提高关键字的值
		Q->data[index] = key;
		for(i = index;i * 2 <= Q->size;i = child){
			/* 获取左右孩子中的更小的那个 */
			child = i * 2;
			if(Q->data[child + 1] < Q->data[child])
				child++;
			if(key < Q->data[child])
				break;
			else
				Q->data[i] = Q->data[child];//向前复制
		}
		Q->data[i] = key;//插入
	}
}

/* 降低关键字的值 */
void decreaseKey(priorityQueue *Q,int alter,int key){
	int index = find(Q,key);
	if(index == 0){
		printf("优先队列中不存在%d关键字\n",key);
		return;
	}
	else {
		/* 上滤 */
		int i;
		key -= alter;//降低关键字的值
		for(i = index;key < Q->data[i / 2];i /= 2) {
			Q->data[i] = Q->data[i / 2];//向后复制
		}
		Q->data[i] = key;
	}
}

void deleteKey(priorityQueue *Q,int key){
	decreaseKey(Q,INF,key);
	deleteMin(Q);
}

int main(){
	int arr[10] = {78,34,12,10,56,39,77,24,9,57};
 	priorityQueue *Q = createQueue(10);
 	printf("注：遍历中每一项数据后面的括号内的数据为它们的父亲\n");
 	printf("遍历优先队列：");
  	initQueue(Q,arr,10);
   	traverseQueue(Q);
   	printf("删除最小元后：");
   	deleteMin(Q);
   	traverseQueue(Q);
   	printf("将10升高成30：");
   	increaseKey(Q,20,10);
   	traverseQueue(Q);
   	printf("将56降低成20：");
   	decreaseKey(Q,36,56);
   	traverseQueue(Q);
   	printf("删除77后：");
   	deleteKey(Q,77);
   	traverseQueue(Q);
	return 0;
}

