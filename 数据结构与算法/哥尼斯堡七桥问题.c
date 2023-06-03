#include<stdio.h>
int main()
{
	int a[4][4] = {
	{0,2,0,1},
	{2,0,2,1},
	{0,2,0,1},
	{1,1,1,0},
	};
	int deg_2[4][4] = {0};
	int deg_3[4][4] = {0};
	int deg_4[4][4] = {0};
	int deg_5[4][4] = {0};
	int deg_6[4][4] = {0};
	int deg_7[4][4] = {0};
	int i,j,k,n;
	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(a[i][k]*a[k][j]>0) deg_2[i][j]++;
	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(deg_2[i][k]*a[k][j]>0) deg_3[i][j]+=deg_2[i][k];
	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(deg_3[i][k]*a[k][j]>0) deg_4[i][j]+=deg_3[i][k];
   	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(deg_4[i][k]*a[k][j]>0) deg_5[i][j]+=deg_4[i][k];
   	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(deg_5[i][k]*a[k][j]>0) deg_6[i][j]+=deg_5[i][k];
	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			for(k = 0;k<4;k++)
				if(deg_6[i][k]*a[k][j]>0) deg_7[i][j]+=deg_6[i][k];
	printf("deg_2\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_2[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	printf("deg_3\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_3[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	printf("deg_4\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_4[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	printf("deg_5\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_5[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	printf("deg_6\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_6[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	printf("deg_7\n");
	for(i = 0;i<4;i++){
		printf("\t");
		for(j = 0;j<4;j++)
			printf("%d ",deg_7[i][j]);
		printf("\n");
	}
	printf("- - - - - - - - - - - - \n");
	for(i = 0;i<4;i++)
		for(j = 0;j<4;j++)
			n+=a[i][j]+deg_2[i][j]+deg_3[i][j]+deg_4[i][j]+deg_5[i][j]+deg_6[i][j]+deg_7[i][j];
	printf("%d",n);
	return 0;
}
