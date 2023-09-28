/*
	Name: ˳���Ĳ���
	Copyright: ������
	Date: 09/13 12:25
	Description: ������˳����в���Ԫ��ʹ��˳�����Ȼ��������
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
	list->element = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);//Ϊ˳�������ռ�
	memset(list->element,0,sizeof(list->element));//��ʼ��˳���Ԫ�ض�Ϊ0
	if(arr != NULL){
		for(i = 0;i < length;i++)
			list->element[i] = arr[i];
		list->length = length;//����˳����ʼ����ĳ���
	}
	else{
		list->length = 0;//��ʱ˳���Ϊ��
	}
	return list;
}

//sequence��ʶ˳��������˳��sequenceΪ1Ϊ��С����sequenceΪ0Ϊ�Ӵ�С
int insert(List list,ElemType element,_Bool sequence){
    if(list){//˳���Ϊ��
		int i;
		if(sequence){//��С����
			for(i = list->length - 1;i >= 0;i--)
				if(list->element[i] > element) list->element[i + 1] = list->element[i];//���Ųλ
				else break;
		}
		else{//�Ӵ�С
			for(i = list->length - 1;i >= 0;i--)
				if(list->element[i] < element) list->element[i + 1] = list->element[i];//���Ųλ
				else break;
		}
		list->element[i + 1] = element;//����Ԫ��
		list->length++;//˳����ȼ�һ
		return 1;//����ɹ�
	}
	return 0;//˳���Ϊ�գ�����ʧ��
}

int main(){
	int arr[5] = {1,3,5,7,9};
	List list = initList(arr,5);
	printf("˳����ʼ����\n");
 	traverseList(list);
 	printf("������˳������2��8��0��\n");
 	//���β���2��8��0
 	insert(list,2,1);
 	traverseList(list);
 	insert(list,8,1);
 	traverseList(list);
	insert(list,0,1);
 	traverseList(list);
	return 0;
}





