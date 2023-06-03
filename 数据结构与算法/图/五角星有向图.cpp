#include<stdio.h>
int main()
{
	int a[5][5] = {
	{0,1,1,0,1},
	{0,0,0,1,0},
	{0,1,0,1,1},
	{1,0,0,0,1},
	{0,1,0,0,0}
	};
	int deg_2[5][5] = {0};//通路数为2
	int deg_3[5][5] = {0};//通路数为3
	int i,j,k;
	for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			for(k = 0;k<5;k++)
				if(a[i][k]*a[k][j]>0) deg_2[i][j]++;//如果v[i]到v[j]存在长度为2的通路
	for(i = 0;i < 5;i++){
		printf("\t");
		for(j = 0;j < 5;j++)
			printf("%d ",deg_2[i][j]);
	printf("\n");
	}
	printf("- - - - - - - - - - - - - -\n");
	for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			for(k = 0;k< 5;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j] += deg_2[i][k];//如果v[i]到v[j]存在长度为3的通路
	for(i = 0;i < 5;i++){
		printf("\t");
		for(j = 0;j < 5;j++)
			printf("%d ",deg_3[i][j]);
	printf("\n");
	}
	return 0;
}
