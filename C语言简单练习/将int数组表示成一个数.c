/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
int toNumber(int* arr, int len) {
	int res = 0;
	int i;
  	for(i = 0; i < len;i++) {
	res += arr[i];
	res *= 10;
	}
  	return res;
}
int main(){
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d",toNumber(arr,10));
	return 0;
}

