#include<iostream>

using namespace std;

//����x�ڶ������еĵ�kλ����
x >> k & 1;

/*
	����x�ڶ������е����һλ1
	-x = ~x + 1��-x��x�Ĳ���
*/
int lowbit(int x){
	return x & -x;
}
