#include<stdio.h>
#define N 10
int main()
{
	int a[N],i,num;
	int *left,*right;
	scanf("%d",&num);
	for(i = 0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(left = &a[0],right = &a[1];left < &a[N-1];right++)
	{
		printf("%d %d\n",*left,*right);
		if(right==&a[N-1]) {
			left++;
			right = left;
			continue;
		}
		if(*left+*right==num) break;
	}
	printf("%d %d",*left,*right);
	return 0;
}
