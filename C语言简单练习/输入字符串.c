#include<stdio.h>
#include<stdlib.h>
int put1(const char  *string){
	int count = 0; 
	while(*string != '\0'){
	putchar(*string++);//先输出*string再string++；
	count++;
	}
	printf("\n");//不想换行可以省略 
	return count;//如果字符串中有换行符也会统计在字符串数量里面 
}
int main()
{
	int ch_num;
	char str1[30],str2[30];
	gets(str1);//读入整行输入，遇到\n结束输入 ，自动舍弃\n 
	printf("%s\n",str1);//遇到空格,\t,\n,\v结束输出，一般只能输出一个单词 
	puts(str1);//自动输出完字符串末尾后再输出\n 
	fgets(str2,30,stdin);//fgets保留输入中的换行符 
	fputs(str2,stdout);//fputs不在输出中添加换行符 
	ch_num = put1(str1);
	printf("%d\n",ch_num);
	return 0;
}
