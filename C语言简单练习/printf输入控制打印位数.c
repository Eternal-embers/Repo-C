#include<stdio.h>
#include<math.h>
#define N 20
int main()
{
	int i,width;
	double n=2;
	scanf("%d",&width);
	for(i=2;i<=N;i++)
	{
		printf("sqrt(%d)=%-.*f\n",i,width,sqrt(n));
		n++; 
	}
	return 0;
}

