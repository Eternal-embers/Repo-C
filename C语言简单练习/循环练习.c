/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>

int main(){
	int i = 1,s = 3,cnt = 1;
	printf("初始i = %d,s = %d\n",i,s);
	do{
		printf("\n第%d次循环\n",cnt++);
		s += i++;
		printf("执行s+=i++后，i = %d,s = %d\n",i,s);
		if(s % 7 == 0) continue;
		else i++;
  		printf("执行i++后，i = %d,s = %d\n",i,s);
	}while(s < 15);
	printf("\n最终结果：i = %d,s = %d\n",i,s);
	return 0;
}

