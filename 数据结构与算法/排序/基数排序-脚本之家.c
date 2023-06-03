#include<stdio.h>
#include"bucket_function.h"
int main(){
	int Array[10] = {73,23,45,24,12,74,87,96,68,8};
	int i;
	RadixSort(Array,10);
	for(i = 0;i < 10;i++)
		printf("%d ",Array[i]);
	return 0;
}
