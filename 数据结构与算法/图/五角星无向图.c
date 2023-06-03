#include<stdio.h>
#include<memory.h>
#define N 5
int main()
{
	int a[N][N] = {
	{0,0,1,1,0},
	{0,0,0,1,1},
	{1,0,0,0,1},
	{1,1,0,0,0},
	{0,1,1,0,0}
	};
	int deg_2[N][N] = {0};
	int deg_3[N][N] = {0};
	memset(deg_2,0,sizeof(deg_2));
	memset(deg_3,0,sizeof(deg_3));
	int i,j,k;
	for(i = 0;i<N;i++)
		for(j = 0;j<N;j++)
			for(k = 0;k<N;k++)
				if(a[i][k]*a[k][j]>0) deg_2[i][j]++;//如果v[i]到v[j]存在长度为2的通路
   for(i = 0;i<N;i++)
		for(j = 0;j<N;j++)
			for(k = 0;k<N;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j] += deg_2[i][k];//如果v[i]到v[j]存在长度为3的通路
   for(i = 0;i<N;i++){
		printf("\t");
		for(j = 0;j<N;j++)
			printf("%d",deg_2[i][j]);
        printf("\n");
	}
	printf("- - - - - - - - - - - - - - - - \n");
	for(i = 0;i<N;i++){
		printf("\t");
		for(j = 0;j<N;j++)
			printf("%d",deg_3[i][j]);
		printf("\n");
	}

}
