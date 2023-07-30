/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>

int main(){
	int iX,iY,iM,iN;
	iX = 10;
	iY = 20;
	iM = iX++;//先赋值再执行iX = iX + 1
	iN = ++iY;//先执行iY = iY + 1再赋值给iN
	printf("iX=%d,iY=%d,iM=%d,iN=%d\n",iX,iY,iM,iN);
	iM = iX--;//先赋值再执行iX = iX - 1
	iN = --iY;//先执行iY = iY - 1再赋值给iN
	printf("iX=%d,iY=%d,iM=%d,iN=%d\n",iX,iY,iM,iN);
	return 0;
}

