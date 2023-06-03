#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,t,count = 0;
	for(i = 2;i<=100;i++){
		for(j = 2;j<sqrt(i);j++){//如果i能被2-sqrt(i)以内的一个整数整除，那么它是合数，否则为素数
			if(i%j==0) break;//如果被整除，退出循环
		}
		if(j>sqrt(i))//如果i不被2-sqrt(i)以内的一个整数整除则为素数
		{
			printf("%d\t",i);
			count++;
			if(count%5==0)  printf("\n");//每输出五个素数后换行
		}
	}
}
