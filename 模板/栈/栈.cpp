#include<iostream>

using namespace std;

const int N = 100010;

int stk[N], top;

//����
stk[top++] = x;

//����
top--;

//ȡջ��
stk[top - 1]

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(){
	return top > 0;
}
