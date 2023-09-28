/*
	Name: 顺序表的插入
	Copyright: 赖清文
	Date: 09/13 12:25
	Description: 向有序顺序表中插入元素使得顺序表仍然保持有序
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAXSIZE 100
#define ElemType int

typedef struct table{
	ElemType *element;
	int length;
}elem,*List;

void traverseList(List list){
	int i;
	for(i = 0;i < list->length;i++)
		printf("%d ",list->element[i]);
	putchar('\n');
}

List initList(ElemType arr[],int length){
	int i;
	List list = (List)malloc(sizeof(List));
	list->element = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);//为顺序表申请空间
	memset(list->element,0,sizeof(list->element));//初始化顺序表元素都为0
	if(arr != NULL){
		for(i = 0;i < length;i++)
			list->element[i] = arr[i];
		list->length = length;//设置顺序表初始化后的长度
	}
	else{
		list->length = 0;//此时顺序表为空
	}
	return list;
}

//sequence标识顺序表的有序顺序，sequence为1为从小到大，sequence为0为从大到小
int insert(List list,ElemType element,_Bool sequence){
    if(list){//顺序表不为空
		int i;
		if(sequence){//从小到大
			for(i = list->length - 1;i >= 0;i--)
				if(list->element[i] > element) list->element[i + 1] = list->element[i];//向后挪位
				else break;
		}
		else{//从大到小
			for(i = list->length - 1;i >= 0;i--)
				if(list->element[i] < element) list->element[i + 1] = list->element[i];//向后挪位
				else break;
		}
		list->element[i + 1] = element;//插入元素
		list->length++;//顺序表长度加一
		return 1;//插入成功
	}
	return 0;//顺序表为空，插入失败
}

int main(){
	int arr[5] = {1,3,5,7,9};
	List list = initList(arr,5);
	printf("顺序表初始化：\n");
 	traverseList(list);
 	printf("依次向顺序表插入2、8、0：\n");
 	//依次插入2、8、0
 	insert(list,2,1);
 	traverseList(list);
 	insert(list,8,1);
 	traverseList(list);
	insert(list,0,1);
 	traverseList(list);
	return 0;
}





