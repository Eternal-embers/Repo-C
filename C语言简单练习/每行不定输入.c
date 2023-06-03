#include<stdio.h>
#include<stdlib.h>
int main(){
	int arr[10] = {0},i,temp,count = 0;
	char ch = 0;
	while(count<3){
			scanf("%d%c",&temp,&ch);
			if(ch=='\n')count++;
			arr[temp] = temp;
	}
	for(i = 0;i < 10;i++)
	printf("%d ",arr[i]);
	return 0;
}
