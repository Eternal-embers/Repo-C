#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
 栈计算后缀表达式
 当读到一个操作数的时候，立即把它放到输入中，如果是操作符则压入操作作符栈中，当遇到'('也将其压入栈中
 如果遇到')'，那么一直将栈元素弹出，直到遇到与此')'对应的'('为止
 如果见到任何(+、-、*、/）,那么我们从栈中弹出栈元素直到发现优先级更低的元素为止
 除非是在处理'('的时候，否则我们绝不从栈中移走')'
 对于这种操作，'+'的优先级最低，'('的优先级最高，当从栈弹出元素的工作完成时，我们再将操作符压入栈中
 如果读到输入的末尾，我们将栈元素弹出直到该栈变为空栈，将符号写到输出中
*/

int operatorvalue[7] = {37,40,41,42,43,45,47};//这是*-+/()的ASCII码，用于判断运算式中扫描的字符是否是符号
typedef struct stack{
	char data;
	struct stack* next;
}stack,*listStack;

listStack initstack(){
	listStack s = (struct stack*)malloc(sizeof(struct stack));
	s->data = '#';
	s->next = NULL;
	return s;
}//初始化栈

void push(listStack s,char c){
	stack *node = (stack *)malloc(sizeof(struct stack));
	node->data = c;
	node->next = s->next;
	s->next = node;
}//入栈

char pop(listStack s){
 	stack *node = s->next;
	char data = node->data;
	s->next = s->next->next;
	free(node);
	return data;
}//出栈

char top(listStack s){
	if(s->next!=NULL) return s->next->data;
}//获取栈顶元素

int priority(char c){
	if(c=='+' || c=='-') return 1;
	else if(c=='*' || c=='/' || c=='%') return 2;
	else return 3;
}//return的数字就是运算优先级

int numORoperator(char c){
	int i;
	for(i = 0;i < 7;i++){
		if(operatorvalue[i] == c) return 1;//运算符
	}
	return 0;//数字
}//判断字符是数字还是运算符

void antiPolish(listStack p,char arr[]){
	int i;
	for(i = 0;i < strlen(arr);i++){//遍历字符串中的所有字符
		//- - - - -如果是运算符- - - - -
        if(numORoperator(arr[i])){

        	if(p->next == NULL){//如果符号栈为空，直接入栈
        		push(p,arr[i]);
			}

				else if(arr[i]==')'){
					//如果符号栈不为空，并且扫描到了')'，我们的逆波兰表达式不需要')'，
					//所以不要入栈，'('入栈只是因为我们要当它为一个界限
					while(top(p) != '(')//如果栈顶不是'('，那么就一直出栈
					{
						char c = pop(p);
						printf("%c",c);
					}
					pop(p);//出栈，我们的逆波兰表达式不需要(),上面的循环结束条件为栈顶为(
				}

					//如果是除')'外的操作符，从栈中弹出栈元素直到发现优先级更低的元素为止
					else {
						int topPriority = priority(top(p));//获取栈顶元素优先级
						int arrPriority = priority(arr[i]);//获取扫描元素优先级
						//如果扫描元素优先级高于栈顶优先级，或者栈顶元素为(,则扫描元素入栈
						if(arrPriority > topPriority || top(p) == '('){
                	    	push(p,arr[i]);
						}
							//这里是重复判断栈顶和扫描符的优先级
							else {
								while(arrPriority <= topPriority && top(p)!='('){
									if(p->next == NULL) break;
									char c = pop(p);
									printf("%c",c);
									topPriority = priority(top(p));
								}
								push(p,arr[i]);//高于或等于扫描符的符号都出栈完了，让扫描符入栈
							}
					}
		}
		//- - - - -如果是数字- - - - -
		else {
			printf("%c",arr[i]);//直接输出
		}
	}
	while(p->next){//将符号栈中剩余元素出栈
		printf("%c",pop(p));
	}
}

//计算后缀表达式的步骤：
//读入输入，如果为数字直接输出
//如果为操作符，与栈顶元素比较，如果读入的操作符优先级大则压栈，否则一直弹出栈元素直到遇到优先级更小的操作符
//特殊情况：对于栈中的'(',一直压栈直到读取到')'
//栈中操作符优先级：'-' = '+' < '*' = '/' < '('
int main(){
	listStack p = initstack();
	int temp = 0;
	char arr[255];
	printf("请输入中缀表达式:");
	scanf("%s",arr);
	printf("逆波兰表达式为:");
	antiPolish(p,arr);
	return 0;
}
