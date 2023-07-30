/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
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
    if(!(a & 1) && !(b & 1))//a��bΪż��
        return stein(a >> 1, b >> 1) << 1;
    else if(!(a & 1))//aΪż��
        return stein(a >> 1, b);
    else if(!(b & 1))//bΪż��
        return stein(a, b >> 1);
    return stein(abs(a - b), a < b ? a : b);//a��bΪ����
}

int main(){
	printf("%d",stein(108,36));
	return 0;
}

