#include<stdio.h>
int main()
{
	int i,j,count = 0;
	for(i=2;i<=2019;i++){
		j=2;
		while(j<i){
		if(i%j==0)break;
		j++;
		}
		if(j==i){
			printf("%4d,",i);
			count++;
			if(count%10==0)printf("\n                  ");
		}
	}
	printf("%d",count);
	return 0;
}
