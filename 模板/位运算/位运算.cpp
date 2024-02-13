#include<iostream>

using namespace std;

//返回x在二进制中的第k位数字
x >> k & 1;

/*
	返回x在二进制中的最后一位1
	-x = ~x + 1，-x是x的补码
*/
int lowbit(int x){
	return x & -x;
}
