/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>

long exchange(long *xp,long y){
	long x = *xp;
	*xp = y;
	return x;
}

int main(){
	long xp = 1;
	long y = 0;
	exchange(&xp,y);
	return 0;
}

