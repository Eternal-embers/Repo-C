#include<stdio.h>
int main(){
	char s[30][60],ch;
	char *p = &s[0][0];
	FILE *fp = fopen("D:\\data\\Êý×Ö¾ØÕó.txt","r");
	int i,j;
	i = 0;
	while(!feof(fp)) {
		ch = fgetc(fp);
		if(ch=='1' || ch=='0') p[i++] = ch;
	}
	for(i = 0;i < 30;i++) {
		for(j = 0;j < 60;j++)
			printf("%c",s[i][j]);
		putchar('\n');
	}
	return 0;
}
