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
	list->num = 0;
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
	for(i = 0;i < list->num;i++){
		if(list->data[i] == key) return key;
	}
	return -1;
}

int main(){
	List *list = initList(10);
	listAdd(list,29);
	listAdd(list,12);
	listAdd(list,32);
	listAdd(list,34);
	listAdd(list,57);
 	printList(list);
 	printf("%d\n",search(list,32));
 	printf("%d\n",search(list,23));
	return 0;
}

