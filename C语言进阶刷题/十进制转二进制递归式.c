#include<stdio.h>

int conversion(int num){
	if(num < 2) return num;
	else return conversion(num / 2) * 10 + num % 2;
}

int main(){
	printf("%d",conversion(1000));
	return 0;
}

