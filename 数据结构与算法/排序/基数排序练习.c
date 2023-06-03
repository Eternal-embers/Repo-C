#include<stdio.h>
#define LEN 30
void initialize(int *p,int len){
	int i;
	srand(time(NULL));
	for(i = 0;i < len;i++){
		p[i] = rand() % 1000 + 1;
	}
}

int maxDgt(int *p,int len){
	int max = 0,i;
	for(i = 0;i < len;i++){
		if(max < p[i]) max = p[i];
	}
	int cnt = 0;
	while(max){
		cnt++;
		max /= 10;
	}
	return cnt;
}

int getBit(int num,int dgt){
	int i = 0;
	while(i < dgt){
		num /= 10;
		i++;
	}
	return num % 10;
}

int radix(int *p,int len,int dgt){
	int bucket[10][len];
	int num[10] = {0};
	int i,j;
	for(i = 0;i < len;i++){
		int index = getBit(p[i],dgt);
		bucket[index][num[index]] = p[i];
		num[index]++;
	}
	int k = 0;
	for(i = 0;i < 10;i++){
		j = 0;
		while(j < num[i]){
			p[k++] = bucket[i][j];
			j++;
		}
	}
}

int radixSort(int *p,int len){
	int times,i;
	times = maxDgt(p,len);
	for(i = 0;i < times;i++)
		radix(p,len,i);
}

int main(){
	int arr[LEN] = {0};
	int i;
	initialize(arr,LEN);
	radixSort(arr,LEN);
	for(i = 0;i < LEN;i++)
		printf("%d ",arr[i]);
	putchar('\n');
	return 0;
}
