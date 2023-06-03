#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	int *data;
	int length;
	int num;
}List;

List *initList(int length){
	List *list = (List *)malloc(sizeof(list));
	list->data = (int *)malloc(sizeof(int) * length);
	list->length = length;
	list->num = 0;
	return list;
}

void listAdd(List* list,int data){
	list->data[list->num++] = data;
}

int binarySearch(List *list,int key){
	//ÅÅĞò
	int i,j,temp;
	for(i = 1;i < list->num;i++){
		temp = list->data[i];
		for(j = i - 1;j >= 0;j--){
			if(temp < list->data[j])
				list->data[j + 1] = list->data[j];
			else break;
		}
		list->data[j + 1] = temp;
	}
	int left,right,mid;
	left = 0;
	right = list->num;
	mid = (left + right) / 2;
	while(left < right){
		if(key < list->data[mid])
			right = mid - 1;
		else if(key > list->data[mid])
			left = mid + 1;
		else return mid;
		mid = (left + right) / 2;
	}
	return -1;
}

int main(){
	List *list = initList(10);
	listAdd(list,89);
	listAdd(list,13);
	listAdd(list,7);
	listAdd(list,25);
	listAdd(list,46);
	listAdd(list,10);
	listAdd(list,30);
	listAdd(list,58);
	listAdd(list,61);
	listAdd(list,74);
	printf("%d\n",binarySearch(list,25));
	printf("%d\n",binarySearch(list,42));
	return 0;
}

