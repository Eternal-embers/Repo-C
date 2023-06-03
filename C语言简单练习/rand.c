#include<stdio.h>
#include<time.h>
int rand (int seed){
 unsigned int next = seed * 1103515245 + 12345;
 return (unsigned int)(next/65536)%32768;
}
int main()
{
	int arr[100] = {0};
	int i,seed;
	for(i = 1;i<=10000;i++)
	{
		seed = rand(i) % 100;
		printf("seed=%d--%d\t",i,seed);
		arr[seed]++;
		if(i%5==0)printf("\n");
	}
	for(i = 0;i<100;i++){
		printf("arr[%d]=%.2f%%\n",i,arr[i]/100.0);
	}
	return 0;
}
