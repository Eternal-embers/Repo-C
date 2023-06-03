#include<stdio.h>
#define N 5
int main()
{ 
int i,num,arr[N];
for(i=0;i<N;i++){
	scanf("%d",&num);
	arr[i]=num;
    }
    for(i=0;i<N;i++)
    printf("%d ",arr[i]);
    return 0;
}
