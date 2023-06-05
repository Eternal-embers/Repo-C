#include<stdio.h>
#include<stdlib.h>

char *toString(int *arr,int length){
   char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
   char *str = (char *)malloc(sizeof(char) * (length + 1));
   int i;
   for(i = 0;i < length;i++){
		str[i] = num[arr[i]];
   }
   str[i] = '\0';
   return str;
}//将int数组转换成字符数组

int main(){
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	char str[10] = "0123456789";
	printf("arr数组是否等于str数组？%s\n",strcmp(toString(arr,10),str) == 0 ? "是" : "否");
	return 0;
}

