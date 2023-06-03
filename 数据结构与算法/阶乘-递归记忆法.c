#include<stdio.h>
#include<memory.h>
unsigned long long arr[50];
unsigned long long f(int n){
	if(n<=2) return n;
	if(arr[n]!=0) {
		printf("arr[%d] = %llu\n",n,arr[n]);
		return arr[n];
	}
	else {
		arr[n] = n*f(n-1);
		return arr[n];
	}
}//×î´ó¼ÆËãf(43) 
int main()
{
	memset(arr,0,sizeof(arr));
	arr[0] = 0;
	arr[1] = 1;
	printf("%llu",f(43));
	return 0;
}
