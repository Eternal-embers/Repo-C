/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN 30
typedef struct List{
	int *data;
	int length;
	int size;//当前的线性表中的元素个数
}List;

List *initList(int length){
	List *list = (List *)malloc(sizeof(List));
	list->length = length;
	list->data = (int *)malloc(sizeof(int) * length);
	list->size = 0;
}

void listAdd(int data,List *list){
	if(list->size == 0){
		list->data[list->size++] = data;
	 	return;
	}
	int i;
	for(i = 0;i < list->size - 1;i++)
		if(list->data[i] == data) return;
	list->data[list->size] = data;
	//插入到合适的位置中
	for(i = list->size - 1;i >= 0;i--){
		if(list->data[i] > data) list->data[i+1] = list->data[i];
			else break;
	}
	list->data[i+1] = data;
	list->size++;
}

void printList(List *list){
	int i;
	for(i = 0;i < list->size;i++){
		printf("%d ",list->data[i]);
	}
	putchar('\n');
}

int binarySearch(int key,List *list){
	int start,end,mid;
	start = 0,end = list->size - 1;
	while(start <= end){
		mid = (start + end)/2;
		if(list->data[mid] < key){
			start = mid + 1;
		}
		else if(list->data[mid] > key){
			end = mid - 1;
		}
		else if(list->data[mid] == key) return mid;
	}
	return -1;
}

int binarySearchRecursion(int key,int start,int end,List *list){
	if(start > end) return -1;
	int mid = (start + end)/2;
	if(list->data[mid] < key) binarySearchRecursion(key,mid + 1,end,list);
	else if(list->data[mid] > key) binarySearchRecursion(key,start,mid - 1,list);
	else if(list->data[mid] == key) return mid;
}
void createData(int *arr,int length){
	int i;
	srand(time(NULL));
	for(i = 0;i < length;i++){
		arr[i] = rand() % (length * 5);
	}
}
int main(){
	List *L = initList(LEN);
	int arr[LEN - 1] = {0};
	createData(arr,LEN - 1);
	int i;
	for(i = 0;i < LEN - 1;i++)
		listAdd(arr[i],L);
	printList(L);
	printf("data %d in %d\n",L->data[L->size-3],binarySearch(L->data[L->size-3],L));
	printf("data %d in %d\n",L->data[L->size-5],binarySearch(L->data[L->size-5],L));
	printf("data %d in %d\n",L->data[L->size-7],binarySearch(L->data[L->size-7],L));
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("data %d in %d\n",L->data[L->size-3],binarySearchRecursion(L->data[L->size-3],0,L->size-1,L));
	printf("data %d in %d\n",L->data[L->size-5],binarySearchRecursion(L->data[L->size-5],0,L->size-1,L));
	printf("data %d in %d\n",L->data[L->size-7],binarySearchRecursion(L->data[L->size-7],0,L->size-1,L));
	return 0;
}

