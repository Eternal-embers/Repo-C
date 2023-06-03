#include<stdio.h>
int main()
{
	FILE *fp;
	int i,j;
	char c;
	fp = fopen("D:\\data\\letter.txt","r");
	for(i = 0;i<30;i++){
		printf("{\"");
		for(j = 0;j<50;j++)
		{
		fscanf(fp,"%c",&c);
		printf("%c",c);
		}
		printf("\"},");
		fscanf(fp,"%c",&c);
		printf("%c",c);
	}
	return 0;
}
