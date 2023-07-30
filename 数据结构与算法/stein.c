/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<math.h>

long long stein(long long a,long long b){
	if(!a)
        return b;
    if(!b)
        return a;
    if(!(a & 1) && !(b & 1))//a和b为偶数
        return stein(a >> 1, b >> 1) << 1;
    else if(!(a & 1))//a为偶数
        return stein(a >> 1, b);
    else if(!(b & 1))//b为偶数
        return stein(a, b >> 1);
    return stein(abs(a - b), a < b ? a : b);//a和b为奇数
}

int main(){
	printf("%d",stein(108,36));
	return 0;
}

