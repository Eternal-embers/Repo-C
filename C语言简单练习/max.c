
#include<stdio.h>

int max(int x,int y){
	return x > y ? x : y;
}

int main(){
	int x = 0,y = 0;
	scanf("%d%d",&x,&y);
	printf("x = %d\ny = %d\n",x,y);
	printf("%d",max(x,y));
	return 0;
}

