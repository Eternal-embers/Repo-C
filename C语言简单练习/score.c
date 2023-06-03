#include<stdio.h>
#include<string.h>

int main(){
	FILE* fp = fopen("D:\\file.txt","r");
	char s[11];
	char name[11];
	int i,score = -1,flag = 0;
	gets(s);
	for(i = 0;i < 10;i++){
		fscanf(fp,"%10s%d",name,&score);
		if(strcmp(s,name) == 0) {
			flag = 1;
			printf("%s %d",name,score);
			break;
		}
	}
	if(flag == 0) printf("这个人不存在");
	return 0;
}

