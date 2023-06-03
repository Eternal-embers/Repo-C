/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
#define NUM 10

typedef struct HashList{
	int num;
	char *data;
}HashList;

HashList *initList() {
	HashList *list = (HashList *)malloc(sizeof(HashList));
	list->num = 0;
	list->data = (char *)malloc(sizeof(char)*NUM);
	int i;
	for(i = 0;i < NUM;i++){
		list->data[i] == 0;
	}
	return list;
}

int hash(int data){
	return data % NUM;
}

void put(HashList *list,char data){
	int index = hash(data);
	if(list->data[index] != 0) {
		int count = 0;
		while(list->data[index] == 0){
			index = hash(hash(data) + count);
			count++;
		}
	}
	list->data[index] = data;
}

int main(){
	HashList* list = initList();
	put(list,'A');
	put(list,'F');
	printf("%c\n",list->data[5]);
	printf("%c\n",list->data[0]);
	return 0;
}

