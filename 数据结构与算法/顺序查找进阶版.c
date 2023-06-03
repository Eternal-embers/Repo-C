#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	int *data;
	int length;
	int num;
}List;

List *initList(int length){
	List *list = (List *)malloc(sizeof(List));
	list->data = (int *)malloc(sizeof(int) * length);
	list->num = 1;
	return list;
}

void printList(List *list){
	int i;
	for(i = 0;i < list->num;i++){
		printf("%d ",list->data[i]);
	}
	putchar('\n');
}

void listAdd(List *list,int data){
	list->data[list->num++] = data;
}

int search(List *list,int key){
	int i;
	list->data[0] = key;
	for(i = list->num - 1;list->data[i] != key;i--)
		continue;
	return i;
}//如果查找成功返回大于0的数,否则返回0

int main(){
	List *list = initList(10);
	listAdd(list,13);
	listAdd(list,23);
	listAdd(list,43);
	listAdd(list,45);
	listAdd(list,28);
	printList(list);
	printf("%d\n",search(list,13));
	printf("%d\n",search(list,24));
}
