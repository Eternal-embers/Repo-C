#include<stdio.h>
int main()
{
	int a = 2019,b = 324,i;
	for(i=1;a!=b;i++){
	if(a>b) a-=b;
	else b-=a;
	}
	printf("%d",i);
	return 0;
}
