#include<stdio.h>
#include<memory.h>
int main()
{
	int a[6][6] = {
	{0,1,1,0,0,1},
	{1,0,1,1,1,1},
	{1,1,0,1,1,1},
	{1,1,1,0,1,1},
	{1,1,1,1,0,1},
	{1,1,1,1,1,0},
	};
	int deg_2[6][6];
	int deg_3[6][6];
	int triangleNum = 0;
	int i,j,k;
	memset(deg_2,0,sizeof(deg_2));
	memset(deg_3,0,sizeof(deg_3));
	for(i = 0;i<6;i++)
		for(j = 0;j<6;j++)
			for(k = 0;k<6;k++)
				if(a[i][k]*a[k][i]>0) deg_2[i][j]++;
	for(i = 0;i<6;i++)
		for(j = 0;j<6;j++)
			for(k = 0;k<6;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j]+=deg_2[i][j];
	for(i = 0;i<6;i++)
		triangleNum += deg_3[i][i];
	printf("%d",triangleNum/3);
	return 0;
}
