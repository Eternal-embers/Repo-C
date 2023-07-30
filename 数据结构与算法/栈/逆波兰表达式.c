/*
	Name:逆波兰表达式
	Copyright:劣等生
	Author:劣等生
	Date:2023/06/23 11:06
	Description:逆波兰表达式的实现
*/

/*
	API和技巧
	double atof(const char *str)把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
	int atoi(const char *str)把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
	char *strtok(char *str, const char *delim)分解字符串 str 为一组字符串，delim 为分隔符。
	char *strstr(const char *haystack, const char *needle)在字符串 haystack 中查找第一次出现字符串 needle（不包含空结束字符）的位置。
    获取字符串长度：sizeof(str)、getLength(str)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"antiPolish.h"

/* 定义计算式中的所有数据类型 */
double PI = 3.141592653589793;
double e = 2.718281828459045;
char oprt[10] = {'+','-','*','/','%','^','(',')','[',']'};//运算符
char* func[12]= {
	"sqrt"  , "log"  ,"log10" ,"sin","cos","tan",
	"arccos","arcsin","arctan","ch","sh","th",
};//函数



/* - - - - - - - - - - -链表的实现- - - - - - - - - - - */
/* 创建链表 */
struct Node *createList(){
	struct Node *stack = (struct Node *)malloc(sizeof(struct Node));
    stack->data = (struct item *)malloc(sizeof(struct item));
    struct item *item = stack->data;
	item->element = (int *)malloc(sizeof(int));//头节点中的数据用来存储栈中元素的个数
	*(int *)(item->element) = 0;//初始化栈中节点数为0
	item->type = 0;
	stack->next = NULL;
	return stack;
}

/* 释放节点 */
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

/* 打印数据项 */
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
    头插法，用于向栈中插入节点
	stack指针指向栈的头节点，element为放入栈中的元素，type标识类型
*/
struct Node *push(struct Node *stack,void *element,char type){
	/* 创建节点 */
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = (struct item *)malloc(sizeof(struct item));
	node->next = NULL;//next指针置空
	struct item *item = node->data;//获取数据项
	item->element = element;//数据项元素
	item->type = type;//数据项类型
	/* 插入 */
	node->next = stack->next;
	stack->next = node;
	/* 栈的节点数加一 */
	*(int *)(stack->data->element)++;
	printf("%d\n",*(int *)(stack->data->element));
 	return node;//返回插入的节点
}

/*
	插入到链表尾部
	list指针指向栈的头节点，element为放入栈中的元素，type标识类型
 */
struct Node *insert(struct Node *list,void *element,char type){
	/* 创建节点 */
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = (struct item *)malloc(sizeof(struct item));
	node->next = NULL;//next指针置空
	struct item *item = node->data;//获取数据项
	item->element = element;//数据项元素
	item->type = type;//数据项类型
	/* 插入 */
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
		/* 获取删除节点的数据项 */
		struct item* item = stack->next->data;
		/* 将栈顶元素从栈中删除 */
		struct Node *node = stack->next;
		stack->next = node->next;
		/* 释放节点 */
		freeNode(node);
		/* 栈的节点数减一 */
        *(int *)(stack->data->element)--;
		/* 返回弹出节点的数据项 */
		return item;
	}
}

/* 获取栈顶元素 */
struct item *top(struct Node *stack){
	if(stack->next != NULL) return stack->next->data;
}

/* 遍历栈 */
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

/* 获取字符串的子串，截取索引start到end-1 */
char *subString(char *str,int start,int end){
	if(start < 0 || end > strlen(str)){
		printf("数组越界!");
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
	if(ch >= '0' && ch <= '9') return 1;//数字
	else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^') return 2;//运算符
	else return 3;//函数
}

/* 将字符串初始化为数据项链表 */
struct Node *toDataItem(char caculation[]){
 	struct Node *list = createList();//创建数据项链表
	int length = strlen(caculation);
	char *pt = caculation;
	int i;
	for(i = 0;i < length;i++){
		/* 数字 */
		switch(getType(pt[i])){
			case 1:{
				int flag = 0;//flag为0表示数据项为整数，flag为1表示数据项为浮点数
				int start = i;
				int end = i + 1;
				for(end = i + 1;end < length;end++){
					if(pt[end] == '.') flag = 1;//出现小数点说明为浮点数
					else if(getType(pt[end]) == 1){}
					else break;//出现不是数的部分退出循环
				}
				i = end;
				/* 截取数字部分 */
				char *str = subString(pt,start,end);
				/* 插入节点 */
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
			/* 运算符 */
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
			/* 函数 */
			case 3:{
				if(pt[i] == 'l' && pt[i + 1] == 'o' && pt[i + 2] =='g'){
					if(pt[i + 3] == '('){
						int start = i + 4;
						int end;
						for(end = i + 4;i < length;i++)
							if(pt[end] == ')') break;
						struct Node *subList = toDataItem(subString(pt,start,end));//对函数的参数进行求值
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

/* 解析计算式,将计算式解析为值 */
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

