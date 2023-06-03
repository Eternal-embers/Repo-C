#include<stdio.h>
#include<stdlib.h>
int main(){
	int hour,minute,second;
	scanf("%d:%d:%d",&hour,&minute,&second);
	printf("%d:%02d:%02d",hour,minute,second);
	return 0;
}
