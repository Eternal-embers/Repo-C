#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
 ջ�����׺���ʽ
 ������һ����������ʱ�����������ŵ������У�����ǲ�������ѹ���������ջ�У�������'('Ҳ����ѹ��ջ��
 �������')'����ôһֱ��ջԪ�ص�����ֱ���������')'��Ӧ��'('Ϊֹ
 ��������κ�(+��-��*��/��,��ô���Ǵ�ջ�е���ջԪ��ֱ���������ȼ����͵�Ԫ��Ϊֹ
 �������ڴ���'('��ʱ�򣬷������Ǿ�����ջ������')'
 �������ֲ�����'+'�����ȼ���ͣ�'('�����ȼ���ߣ�����ջ����Ԫ�صĹ������ʱ�������ٽ�������ѹ��ջ��
 ������������ĩβ�����ǽ�ջԪ�ص���ֱ����ջ��Ϊ��ջ��������д�������
*/

int operatorvalue[7] = {37,40,41,42,43,45,47};//����*-+/()��ASCII�룬�����ж�����ʽ��ɨ����ַ��Ƿ��Ƿ���
typedef struct stack{
	char data;
	struct stack* next;
}stack,*listStack;

listStack initstack(){
	listStack s = (struct stack*)malloc(sizeof(struct stack));
	s->data = '#';
	s->next = NULL;
	return s;
}//��ʼ��ջ

void push(listStack s,char c){
	stack *node = (stack *)malloc(sizeof(struct stack));
	node->data = c;
	node->next = s->next;
	s->next = node;
}//��ջ

char pop(listStack s){
 	stack *node = s->next;
	char data = node->data;
	s->next = s->next->next;
	free(node);
	return data;
}//��ջ

char top(listStack s){
	if(s->next!=NULL) return s->next->data;
}//��ȡջ��Ԫ��

int priority(char c){
	if(c=='+' || c=='-') return 1;
	else if(c=='*' || c=='/' || c=='%') return 2;
	else return 3;
}//return�����־����������ȼ�

int numORoperator(char c){
	int i;
	for(i = 0;i < 7;i++){
		if(operatorvalue[i] == c) return 1;//�����
	}
	return 0;//����
}//�ж��ַ������ֻ��������

void antiPolish(listStack p,char arr[]){
	int i;
	for(i = 0;i < strlen(arr);i++){//�����ַ����е������ַ�
		//- - - - -����������- - - - -
        if(numORoperator(arr[i])){

        	if(p->next == NULL){//�������ջΪ�գ�ֱ����ջ
        		push(p,arr[i]);
			}

				else if(arr[i]==')'){
					//�������ջ��Ϊ�գ�����ɨ�赽��')'�����ǵ��沨�����ʽ����Ҫ')'��
					//���Բ�Ҫ��ջ��'('��ջֻ����Ϊ����Ҫ����Ϊһ������
					while(top(p) != '(')//���ջ������'('����ô��һֱ��ջ
					{
						char c = pop(p);
						printf("%c",c);
					}
					pop(p);//��ջ�����ǵ��沨�����ʽ����Ҫ(),�����ѭ����������Ϊջ��Ϊ(
				}

					//����ǳ�')'��Ĳ���������ջ�е���ջԪ��ֱ���������ȼ����͵�Ԫ��Ϊֹ
					else {
						int topPriority = priority(top(p));//��ȡջ��Ԫ�����ȼ�
						int arrPriority = priority(arr[i]);//��ȡɨ��Ԫ�����ȼ�
						//���ɨ��Ԫ�����ȼ�����ջ�����ȼ�������ջ��Ԫ��Ϊ(,��ɨ��Ԫ����ջ
						if(arrPriority > topPriority || top(p) == '('){
                	    	push(p,arr[i]);
						}
							//�������ظ��ж�ջ����ɨ��������ȼ�
							else {
								while(arrPriority <= topPriority && top(p)!='('){
									if(p->next == NULL) break;
									char c = pop(p);
									printf("%c",c);
									topPriority = priority(top(p));
								}
								push(p,arr[i]);//���ڻ����ɨ����ķ��Ŷ���ջ���ˣ���ɨ�����ջ
							}
					}
		}
		//- - - - -���������- - - - -
		else {
			printf("%c",arr[i]);//ֱ�����
		}
	}
	while(p->next){//������ջ��ʣ��Ԫ�س�ջ
		printf("%c",pop(p));
	}
}

//�����׺���ʽ�Ĳ��裺
//�������룬���Ϊ����ֱ�����
//���Ϊ����������ջ��Ԫ�رȽϣ��������Ĳ��������ȼ�����ѹջ������һֱ����ջԪ��ֱ���������ȼ���С�Ĳ�����
//�������������ջ�е�'(',һֱѹջֱ����ȡ��')'
//ջ�в��������ȼ���'-' = '+' < '*' = '/' < '('
int main(){
	listStack p = initstack();
	int temp = 0;
	char arr[255];
	printf("��������׺���ʽ:");
	scanf("%s",arr);
	printf("�沨�����ʽΪ:");
	antiPolish(p,arr);
	return 0;
}
