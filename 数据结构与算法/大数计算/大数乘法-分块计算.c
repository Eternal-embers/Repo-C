/*
	Name:大数乘法
	Copyright:劣等生
	Author:劣等生
	Date:23/03/23 20:34
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
#define base 1000
int getBit(int x){
	int count = 0;
	while(x > 0){
		x/= base;
		count++;
	}
	return count;
}

void bigNumberMultiply(int x1,int x2){
	int bit1,bit2,bit;//分别记录x1和x2以及x1*x2的在base进制的情况下的位数
	int i,j;
	bit1 = getBit(x1);
	bit2 = getBit(x2);
	//printf("bit1 = %d,bit2 = %d\n",bit1,bit2);
	bit = bit1 + bit2;
	int a[bit1],b[bit2],res[bit];
	for(i = 0;i < bit;i++)
		res[i] = 0;
	for(i = 0;i < bit1;i++){
		a[i] = x1 % base;
		x1 /= base;
	}
	for(i = 0;i < bit2;i++){
		b[i] = x2 % base;
		x2 /= base;
	}
	for(i = 0;i < bit1;i++)
		for(j = 0;j < bit2;j++){
			res[i + j] += a[i] * b[j];
		}
	//进位
	for(i = 0;i < bit;i++)
		if(res[i] >= base) {
			res[i + 1] += res[i]/base;
			res[i] %= base;
		}
	if(res[bit - 1] > 0) {
		printf("%d,",res[bit - 1]);
		if(bit - 2 > 0)printf("%03d,",res[bit - 2]);
	}
	else{
		printf("%d,",res[bit - 2]);
	}
	i = bit - 3;
	while(i > 0){
		printf("%03d,",res[i]);
		i--;
	}
	printf("%03d",res[0]);
	printf("\n");
}

int main(){
	int x1,x2;
	scanf("%d%d",&x1,&x2);
	bigNumberMultiply(x1,x2);
	return 0;
}

