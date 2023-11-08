#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	char s[20];
	scanf("%d",&n);
	//fflush(stdin);
	//getchar();
	/*
	char ch;
	while((ch = getchar()) != '\n'){}
	*/
	char buffer[100];
	fgets(buffer, sizeof(buffer), stdin);
	gets(s);
	printf("%s",s);
	system("pause>NULL");
	return 0;
}

