#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++){
		if(i+j<10)printf("if(a=='%d'&& b=='%d')return '%d';\n",i,j,i+j);
		else printf("if(a=='%d'&& b=='%d'){flag = 1;return '%d';}\n",i,j,(i+j)%10);
		}
	return 0;
}
