#include<stdio.h>
#define N 20
char *s_gets(char *st,int n);
int main()
{
	char first[N];
	char last[N];
	char formal[2*N+10];
	double prize;
	puts("Enter your first name:");
	s_gets(first,N);
	puts("Enter your last name:");
	s_gets(last,N);
	puts("Enter your prize money:");
	scanf("%lf",&prize);
	sprintf(formal,"%s %s:$%6.2f\n",last,first,prize);
	//sprintf()函数获取输入，并将其格式化为标准形式，然后将格式化后的字符串存储在formal中 
	puts(formal);
	return 0;
}
char *s_gets(char *st,int n){
	char *ret_val;
	int i = 0;
	ret_val = fgets(st,n,stdin);
	if(ret_val){
		while(st[i]!='\n' && st[i]!='\0')
		i++;
		if(st[i]=='\n') st[i] = '\0';
		else 
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
