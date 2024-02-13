#include<iostream>

using namespace std;

const int N = 100010;

int stk[N], top;

//²åÈë
stk[top++] = x;

//µ¯³ö
top--;

//È¡Õ»¶¥
stk[top - 1]

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool isEmpty(){
	return top > 0;
}
