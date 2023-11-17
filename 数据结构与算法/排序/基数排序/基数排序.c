#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN 40

void initialize(int *p,int len){
	int i;
	srand(time(NULL));
	for(i = 0;i < len;i++){
		p[i] = rand() % 1000 + 1;
	}
}
int maxDgt(int *p,int len){
	int i,max = p[0];
	for(i = 0;i < len;i++)
		if(max < p[i]) max = p[i];
	int bit = 0;
	while(max){
		max /= 10;
		bit++;
	}
	return bit;
}//获取最大位数digit

int getbit(int num,int digit){
	int i = 0;
	while(i++ < digit)
		num /= 10;
	return num % 10;
}//获取num丢弃digit位最低位后的最低位上的数字

void radix(int *p,int digit,int len){
	int bucket[10][len];//开辟0~9的桶
	int b[10] = {0};//存储0~9的桶中各有多少个有效值
	int i,j,index;
	for(i = 0;i < len;i++){
		index = getbit(p[i],digit);//获取p[i]第digit+1位的数字
		bucket[index][b[index]] = p[i];//将p[i]放入digit的桶中
		b[index]++;
	}
	int k = 0;
	for(i = 0;i < 10;i++){
  		j = 0;
		while(j < b[i]){
			p[k++] = bucket[i][j];
   			j++;
		}
	}//将按第digit+1位上的数字进行桶排序后得到的数列重新装入arr数组中
}

void radixSort(int *p,int len){
	int i;
	int times = maxDgt(p,len);
	for(i = 0;i < times;i++)
		radix(p,i,len);
}

int main(){
	int arr[LEN] = {0};
	int i;
	initialize(arr,LEN);
	for(i = 0;i < LEN;i++)
		printf("%d ",arr[i]);
	putchar('\n');
	radixSort(arr,LEN);
	for(i = 0;i < LEN;i++)
		printf("%d ",arr[i]);
	putchar('\n');
	return 0;
}
