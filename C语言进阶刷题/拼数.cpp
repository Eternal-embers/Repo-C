/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1,const void * p2){
	int a = p1 ? *((int *)p1) : 0;
	int b = p2 ? *((int *)p2) : 0;
	int d1 = 1,d2 = 1;
	int m = a,n = b;
	while(m){
		m /= 10;
		d1 *= 10;
	}
	while(n){
		n /= 10;
		d2 *= 10;
	}
	return  a * d2 + b - b * d1 + a < 0;
}

int main(){
	int num[20],i,j,n;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
		scanf("%d",&num[i]);
	/*
	//插入排序,从大到小
	for(i = 1;i < n;i++){
		int temp = num[i];
		for(j = i - 1;j >= 0;j--){
			if(compare(temp,num[j])) num[j + 1] = num[j];//向后复制
			else break;
		}
		num[j + 1] = temp;
	}
	*/
	qsort(&num,n,sizeof(int),compare);
	for(i = 0;i < n;i++){
		printf("%d",num[i]);
	}
	return 0;
}

