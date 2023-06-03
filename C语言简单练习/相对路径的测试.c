#include<stdio.h>
int main()
{
	FILE *fp = fopen("相对路径创建文件.txt","w");
	fclose(fp);
	return 0;
}
