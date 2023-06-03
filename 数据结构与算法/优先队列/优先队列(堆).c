#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

typedef struct Heap{
	int capacity;//容量
	int size;
	int *data;
}Heap;

/* 初始化堆 */
Heap* initHeap(int capacity){
	Heap *H = (Heap *)malloc(sizeof(Heap));
	H->capacity = capacity;
	H->size = 0;
	H->data = (int *)malloc(sizeof(int) * (capacity + 1));
	H->data[0] = -INF;
	return H;
}

void traverseHeap(Heap *H){
	int i;
	for(i = 1;i <= H->size;i++){
		printf("%d ",H->data[i]);
	}
	putchar('\n');
}

_Bool isFull(Heap *H){
	return H->size == H->capacity + 1;
}

void insert(int data,Heap *H){
	int i;
	if(isFull(H)){
		printf("优先队列已满！\n");
		return;
	}
	/* 上滤,在根节点插入 */
	for(i = ++H->size;H->data[i / 2] > data;i /= 2){
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = data;
}

_Bool isEmpty(Heap *H){
    return H->size == 0;
}

int deleteMin(Heap *H){
	int i,child;
	int min,last;
	if(isEmpty(H)) {
		printf("优先队列为空！\n");
		return;
	}
	min = H->data[1];
	last = H->data[H->size--];
	for(i = 1;i * 2 <= H->size;i = child){
		child = i * 2;//获取左孩子
		/* 比较出左右孩子的较小者 */
		if(child != H->size && H->data[child + 1] < H->data[child])
			child++;
		/* 如果last大于左右孩子，下滤 */
		if(last > H->data[child])
			H->data[i] = H->data[child];
		else break;//last符合插入条件
	}
	H->data[i] = last;//将last插入
	return min;
}

int find(Heap *H,int key){
	int i;
	for(i = 1;i <= H->size;i++){
		if(H->data[i] == key) return i;
	}
	return 0;
}

Heap *buildHeap(int* data,int length){
	Heap *H = initHeap(length);
	int i;
	for(i = 0;i < length;i++){
  		insert(data[i],H);
	}
	return H;
}

void decreaseKey(int key,int alter,Heap *H){
	int index = find(H,key);
	if(index == 0) {
		printf("优先队列中不存在%d！\n",key);
		return;
	}
	H->data[index] -= alter;//降低关键字的值
	/* 上滤 */
	int i;
	int data = H->data[index];
	for(i = index;H->data[i / 2] > data;i /= 2){
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = data;
}

void increaseKey(int key,int alter,Heap *H){
	int index = find(H,key);
	if(index == 0) {
		printf("优先队列中不存在%d！\n",key);
		return;
	}
	H->data[index] += alter;//增加关键字的值
	/* 下滤 */
	int i;
	int data = H->data[index];
	int child;
	for(i = index,child = i * 2;i * 2 <= H->size;i = child){
		if(H->data[child + 1] < H->data[child])
			child++;
		if(H->data[child] < data) {
			H->data[i] = H->data[child];
		}
		else break;
	}
 	H->data[i] = data;
}

void deleteKey(Heap *H,int key){
	if(find(H,key) == 0) {
		printf("优先队列中不存在%d",key);
		return;
	}
	decreaseKey(key,INF,H);
	deleteMin(H);
}

int main(){
	int arr[10] = {13,24,31,10,19,75,44,25,17,63};
	Heap *H = buildHeap(arr,10);
	printf("创建优先队列：");
	traverseHeap(H);
	deleteMin(H);
	printf("删除最小元后：");
 	traverseHeap(H);
 	printf("将关键字24降低12：");
 	decreaseKey(24,12,H);
 	traverseHeap(H);
	printf("将关键字17增加18：");
  	increaseKey(17,18,H);
   	traverseHeap(H);
   	printf("删除关键字31：");
   	deleteKey(H,31);
   	traverseHeap(H);
	return 0;
}

