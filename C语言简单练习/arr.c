#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	fp = fopen("D:\\data\\arr.txt","r");
	int i,num;
	for(i = 1;i<=100;i++){
		fscanf(fp,"%d",&num);
		if(i%10==0)printf("%d,\n               ",num);
			else printf("%d,",num);
	} 
	return 0;
}
