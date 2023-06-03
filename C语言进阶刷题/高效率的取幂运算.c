#include<stdio.h>
long long Pow(long x,long N){
	if(N==0) return 1;
	if(N==1) return x;
	if(N % 2 == 0) return Pow(x*x,N/2);
	else return Pow(x*x,N/2)*x;
}
int main(){
    printf("%ld",Pow(3,6));
	return 0;
}
