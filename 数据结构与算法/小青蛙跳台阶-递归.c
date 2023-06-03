#include<stdio.h>
#include<memory.h>
unsigned long long arr[100]; 
unsigned long long f(int n){
	if(n<=2) return n;
	if(arr[n-1]==0) arr[n-1] = f(n-1);
	if(arr[n-2]==0) arr[n-2] = f(n-2);
	return arr[n-1]+arr[n-2];
}
int main()
{
	memset(arr,0,sizeof(arr));
	arr[1] = 1;
	arr[2] = 2;
	printf("%llu\n",f(50));
	printf("%llu",arr[18]+arr[19]);
	return 0;
}
