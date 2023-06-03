#include<stdio.h>
#include<math.h>
#define N 20
int main()
{
	int i,width;
    double x=1,arr[20];
    scanf("%d",&width);
    for(i=1;i<=20;i++)
    {
    	arr[i]=log(x);//lnx
    	x++;
	}
	for(i=1;i<=20;i++)
	printf("ln%-i=%-.*f\n",i,width,arr[i]);
	return 0;
}
