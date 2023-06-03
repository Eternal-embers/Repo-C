#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	char file_addr[50];
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("文件名格式:\n\n");
	printf("创建文本文件:filename.txt\n\n");
	printf("创建二进制文件:filename\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("绝对路径格式(以建立二进制文件举例):\n\n");
	printf("在某盘根目录建立文件:盘符\\\\filename					例如：D:\\\\file\n\n");
	printf("在某盘目录下的子目录中建立文件:盘符\\\\文件夹名\\\\...\\\\filename		例如：D:\\\\folder\\\\data\\\\filename\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf(">>>使用前请仔细读取帮助信息,回车开始创建文件");
	system("pause>NULL");
	while(getchar()!='\n')
		continue;
	printf("请输入要创建的文件的路径(#结束创建):\n>>");
	scanf("%s",file_addr);
	while(file_addr[0]!='#'){
	fp = fopen(file_addr,"w");
	fclose(fp);
	printf("创建\"%s\"成功\n",file_addr);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	while(getchar()!='\n')
		continue;
	printf("请输入要创建的文件的路径(#结束创建):\n>>");
	scanf("%s",file_addr);
	}
	return 0;
}
