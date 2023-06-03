/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:26/03/23 15:42
	Description:比对两篇文章中的不同之处
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define std "D:\\劣等生\\Documents\\平衡二叉树--Up_TyrantLucifer.c"
#define ero "D:\\劣等生\\Documents\\平衡二叉树-AVL树.c"
#define LEN 100000
void check(FILE *fp1,FILE *fp2){
	char stdAtc[LEN];//标准文件，也就是用来做参考的文件
	char eroAtc[LEN];//有错误的文件，也就是和标准文件进行比对，找出哪里有不同的地方
	char ch;
	int i,j;
	for(i = 0;!feof(fp1);i++){
		stdAtc[i] = fgetc(fp1);
	}
	stdAtc[i] = '\0';
	for(i = 0;!feof(fp2);i++){
		eroAtc[i] = fgetc(fp2);
	}
	eroAtc[i] = '\0';
	//比对
	int LEN1 = strlen(stdAtc);
	_Bool flag1,flag2;
	int LEN2 = strlen(eroAtc);
	for(i = 0,j = 0;i < LEN1 && j < LEN2;){
		flag1 = 0,flag2 = 0;
		if(eroAtc[i] == ' ' || eroAtc[i] == '\n' || eroAtc[i] == '\t') {
			i++;
			printf("%c",eroAtc[i]);
		}
			else flag1 = 1;
	    if(stdAtc[j] == ' ' || stdAtc[j] == '\n' || stdAtc[i] == '\t') {
	    	j++;
		}
			else flag2 = 1;
		if(flag1 && flag2){//如果eroAtc[i]和stdAtc[i]都不为空格或\n、\r
			i++;
			j++;
			if(eroAtc[i] == stdAtc[j]) printf("%c",eroAtc[i]);//比对成功
				else printf("?");//比对不成功
		}
	}
	fclose(fp1);
	fclose(fp2);
}
int main(){
	FILE *fp1,*fp2;
	fp1 = fopen(std,"r");
	fp2 = fopen(ero,"r");
	check(fp1,fp2);
	return 0;
}

