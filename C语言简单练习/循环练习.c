/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>

int main(){
	int i = 1,s = 3,cnt = 1;
	printf("��ʼi = %d,s = %d\n",i,s);
	do{
		printf("\n��%d��ѭ��\n",cnt++);
		s += i++;
		printf("ִ��s+=i++��i = %d,s = %d\n",i,s);
		if(s % 7 == 0) continue;
		else i++;
  		printf("ִ��i++��i = %d,s = %d\n",i,s);
	}while(s < 15);
	printf("\n���ս����i = %d,s = %d\n",i,s);
	return 0;
}

