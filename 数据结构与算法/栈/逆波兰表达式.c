/*
	Name:�沨�����ʽ
	Copyright:�ӵ���
	Author:�ӵ���
	Date:2023/06/23 11:06
	Description:�沨�����ʽ��ʵ��
*/

/*
	API�ͼ���
	double atof(const char *str)�Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ double �ͣ���
	int atoi(const char *str)�Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ���
	char *strtok(char *str, const char *delim)�ֽ��ַ��� str Ϊһ���ַ�����delim Ϊ�ָ�����
	char *strstr(const char *haystack, const char *needle)���ַ��� haystack �в��ҵ�һ�γ����ַ��� needle���������ս����ַ�����λ�á�
    ��ȡ�ַ������ȣ�sizeof(str)��getLength(str)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"antiPolish.h"

/* �������ʽ�е������������� */
double PI = 3.141592653589793;
double e = 2.718281828459045;
char oprt[10] = {'+','-','*','/','%','^','(',')','[',']'};//�����
char* func[12]= {
	"sqrt"  , "log"  ,"log10" ,"sin","cos","tan",
	"arccos","arcsin","arctan","ch","sh","th",
};//����



/* - - - - - - - - - - -�����ʵ��- - - - - - - - - - - */
/* �������� */
struct Node *createList(){
	struct Node *stack = (struct Node *)malloc(sizeof(struct Node));
    stack->data = (struct item *)malloc(sizeof(struct item));
    struct item *item = stack->data;
	item->element = (int *)malloc(sizeof(int));//ͷ�ڵ��е����������洢ջ��Ԫ�صĸ���
	*(int *)(item->element) = 0;//��ʼ��ջ�нڵ���Ϊ0
	item->type = 0;
	stack->next = NULL;
	return stack;
}

/* �ͷŽڵ� */
void freeNode(struct Node *node) {
    if (node != NULL) {
        free(node->data);
        free(node->next);
        free(node);
    }
}

void cleanList(struct Node *list){
	if(list != NULL){
		struct Node *node = list;
		while(node){
			struct Node *next = node->next;
			free(node->data->element);
			free(node->data);
			free(node->next);
			free(node);
			node = next;
		}
	}
}

/* ��ӡ������ */
void printItem(struct item *data){
	switch(data->type){
		case 'c':{
			printf("%c",*(char *)data->element);
			break;
		}
		case 'i':{
			printf("%d",*(int *)data->element);
			break;
		}
		case 'd':{
			printf("%lf",*(double *)data->element);
			break;
		}
		case 'f':{
			printf("%s",data->element);
			break;
		}
	}
}

/*
    ͷ�巨��������ջ�в���ڵ�
	stackָ��ָ��ջ��ͷ�ڵ㣬elementΪ����ջ�е�Ԫ�أ�type��ʶ����
*/
struct Node *push(struct Node *stack,void *element,char type){
	/* �����ڵ� */
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = (struct item *)malloc(sizeof(struct item));
	node->next = NULL;//nextָ���ÿ�
	struct item *item = node->data;//��ȡ������
	item->element = element;//������Ԫ��
	item->type = type;//����������
	/* ���� */
	node->next = stack->next;
	stack->next = node;
	/* ջ�Ľڵ�����һ */
	*(int *)(stack->data->element)++;
	printf("%d\n",*(int *)(stack->data->element));
 	return node;//���ز���Ľڵ�
}

/*
	���뵽����β��
	listָ��ָ��ջ��ͷ�ڵ㣬elementΪ����ջ�е�Ԫ�أ�type��ʶ����
 */
struct Node *insert(struct Node *list,void *element,char type){
	/* �����ڵ� */
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = (struct item *)malloc(sizeof(struct item));
	node->next = NULL;//nextָ���ÿ�
	struct item *item = node->data;//��ȡ������
	item->element = element;//������Ԫ��
	item->type = type;//����������
	/* ���� */
	while(list->next)
		list = list->next;
	node->next = list->next;
	list->next = node;
	*(int *)(list->data->element)++;
	return node;
}

struct item *pop(struct Node *stack){
	if(stack->next == NULL) return NULL;
	else{
		/* ��ȡɾ���ڵ�������� */
		struct item* item = stack->next->data;
		/* ��ջ��Ԫ�ش�ջ��ɾ�� */
		struct Node *node = stack->next;
		stack->next = node->next;
		/* �ͷŽڵ� */
		freeNode(node);
		/* ջ�Ľڵ�����һ */
        *(int *)(stack->data->element)--;
		/* ���ص����ڵ�������� */
		return item;
	}
}

/* ��ȡջ��Ԫ�� */
struct item *top(struct Node *stack){
	if(stack->next != NULL) return stack->next->data;
}

/* ����ջ */
void traverseList(struct Node *list){
	if(list->next != NULL){
		struct Node *node = list->next;
		while(node){
			printItem(node->data);
			putchar(' ');
			node = node->next;
		}
	}
	else
		printf("NULL");
}

/* ��ȡ�ַ������Ӵ�����ȡ����start��end-1 */
char *subString(char *str,int start,int end){
	if(start < 0 || end > strlen(str)){
		printf("����Խ��!");
		return NULL;
	}
	else {
		char *sub = (char *)malloc(sizeof(char) * (end - start + 1));
		int i;
		for(i = start;i < end;i++)
			sub[i] = str[i];
		sub[end] = '\0';
		return sub;
	}
}

int getType(char ch){
	if(ch >= '0' && ch <= '9') return 1;//����
	else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^') return 2;//�����
	else return 3;//����
}

/* ���ַ�����ʼ��Ϊ���������� */
struct Node *toDataItem(char caculation[]){
 	struct Node *list = createList();//��������������
	int length = strlen(caculation);
	char *pt = caculation;
	int i;
	for(i = 0;i < length;i++){
		/* ���� */
		switch(getType(pt[i])){
			case 1:{
				int flag = 0;//flagΪ0��ʾ������Ϊ������flagΪ1��ʾ������Ϊ������
				int start = i;
				int end = i + 1;
				for(end = i + 1;end < length;end++){
					if(pt[end] == '.') flag = 1;//����С����˵��Ϊ������
					else if(getType(pt[end]) == 1){}
					else break;//���ֲ������Ĳ����˳�ѭ��
				}
				i = end;
				/* ��ȡ���ֲ��� */
				char *str = subString(pt,start,end);
				/* ����ڵ� */
				if(flag == 0){
					int num = atoi(str);
					insert(list,&num,'i');
				}
				else{
					double num = atof(str);
					insert(list,&num,'d');
				}
				break;
			}
			/* ����� */
			case 2:{
				int j;
				for(j = 0;j < 10;j++){
					if(pt[i] == oprt[j]) break;
				}
				char* ch = (char *)malloc(sizeof(char));
				*ch = pt[i];
				if(j < 10) insert(list,&ch,'c');
				break;
			}
			/* ���� */
			case 3:{
				if(pt[i] == 'l' && pt[i + 1] == 'o' && pt[i + 2] =='g'){
					if(pt[i + 3] == '('){
						int start = i + 4;
						int end;
						for(end = i + 4;i < length;i++)
							if(pt[end] == ')') break;
						struct Node *subList = toDataItem(subString(pt,start,end));//�Ժ����Ĳ���������ֵ
						double value = log(antiPolish(subList));
						insert(list,&value,'d');
					}
					else if(pt[i + 3] == '1' && pt[i + 4] == '0'){
					   	int start = i + 4;
						int end;
						for(end = i + 4;i < length;i++)
							if(pt[end] == ')') break;
						struct Node *subList = toDataItem(subString(pt,start,end));
					}
				}
				break;
			}
		}
	}
}

/* ��������ʽ,������ʽ����Ϊֵ */
double antiPolish(struct Node *list){

}

int main() {

	struct Node *stack = createList();
	int a = 100;
	char b = '+';
	double c = 3.14;
	char d[6] = "hello";;
	push(stack,&a,'i');
	push(stack,&b,'c');
	push(stack,&c,'d');
	push(stack,&d,'s');
	printf("%d\n",*(int *)stack->data->element);
 	traverseList(stack);
 	putchar('\n');


	/*
	printf("%.15f\n",PI);
	printf("%.15f\n",e);
	int i;
	for(i = 0;i < 10;i++)
		printf("%c ",oprt[i]);
	putchar('\n');
	for(i = 0;i < 12;i++){
		printf("%s ",func[i]);
	}
	*/

	return 0;

}

