#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char file_addr[50],ch;
	start:
	printf("请输入要查看的代码文本地址:\n>>");
	scanf("%s",file_addr);
	if( (fp = fopen(file_addr,"r"))==NULL ) {
		printf("\n- - - - -\"%s\"无法打开- - - - -",file_addr);
		system("pause>NULL");
		system("cls");
		goto start;
	}
	ch = fgetc(fp);
	while(!feof(fp)) {
		printf("%c",ch);
		ch = fgetc(fp);
	}
	return 0;
}
