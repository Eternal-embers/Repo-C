/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>

int main(){
	int iX,iY,iM,iN;
	iX = 10;
	iY = 20;
	iM = iX++;//�ȸ�ֵ��ִ��iX = iX + 1
	iN = ++iY;//��ִ��iY = iY + 1�ٸ�ֵ��iN
	printf("iX=%d,iY=%d,iM=%d,iN=%d\n",iX,iY,iM,iN);
	iM = iX--;//�ȸ�ֵ��ִ��iX = iX - 1
	iN = --iY;//��ִ��iY = iY - 1�ٸ�ֵ��iN
	printf("iX=%d,iY=%d,iM=%d,iN=%d\n",iX,iY,iM,iN);
	return 0;
}

