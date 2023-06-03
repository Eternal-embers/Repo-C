/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:23/03/23 21:57
	Description:大数计算，转10的n次方的计算
*/
#include<stdio.h>
#include<memory.h>
#define base 1000
/*最大能计算的乘积结果为85,070,591,730,234,615,828,950,163,710,522,949,636，结果33位以下的基本都能计算*/
void bigNumberMultiply(long long x1,long long x2){
	int bit1,bit2,bit;//分别记录x1和x2以及x1*x2的在base进制的情况下的位数
	int i,j,count,flag;
	unsigned long long num1,num2;
	if(x1 > 0 && x2 > 0 || x1 < 0 && x2 > 0) flag = 1;
		else flag = 0;
	if(x1 < 0) x1 = -x1;
	if(x2 < 0) x2 = -x2;
	num1 = x1,num2 = x2;
	
	/* 计算x1在以base进制下的位数*/
	for(count = 0,num1 = x1;num1 > 0;count++){
		num1 /= base;
	}
	bit1 = count;
	/* 计算x2在以base进制下的位数*/
	for(count = 0,num2 = x2;num2 > 0;count++){
		num2 /= base;
	}
	bit2 = count;
	/*计算x1*x2的结果在base进制下的位数*/
	bit = bit1 + bit2;
	
	/*计算x1和x2在base进制下各位上的数字*/
	int n1[bit1],n2[bit2],res[bit];
	memset(res,0,sizeof(res));
	num1 = x1,num2 = x2;
	for(i = 0;i < bit1;i++){
		n1[i] = num1 % base;
		num1 /= base;
	}//x1
	for(i = 0;i < bit2;i++){
		n2[i] = num2 % base;
		num2 /= base;
	}//x2
	for(i = 0;i < bit1;i++){
		for(j = 0;j < bit2;j++){
			res[i + j] += n1[i] * n2[j];
		}
	}//res
		
	/*对res各位上的数字进位*/
	for(i = 0;i < bit;i++){
		if(res[i] >= base) {
			res[i + 1] += res[i]/base;
			res[i] %= base;
		}
	}

	/*对结果进行输出，从个位开始，每输出三位数字就用逗号隔开*/
	if(flag == 0) printf("-");//如果结果为负数，输出负数符号
	if(res[bit - 1] > 0) {
		printf("%d,",res[bit - 1]);
		printf("%03d,",res[bit - 2]);
	}
	else{
		printf("%d,",res[bit - 2]);
	}
	i = bit - 3;
	while(i > 0){
		printf("%03d,",res[i]);
		i--;
	}
	//由于数字最后不要有逗号，所以res[0]单独输出
	printf("%03d",res[0]);
	printf("\n");
}

int main(){
	long long x1,x2;
	printf("x1 = ");
	scanf("%lld",&x1);
	printf("x2 = ");
	scanf("%lld",&x2);
	bigNumberMultiply(x1,x2);
	return 0;
}


