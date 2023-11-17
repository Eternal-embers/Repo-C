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
}//��ȡ���λ��digit

int getbit(int num,int digit){
	int i = 0;
	while(i++ < digit)
		num /= 10;
	return num % 10;
}//��ȡnum����digitλ���λ������λ�ϵ�����

void radix(int *p,int digit,int len){
	int bucket[10][len];//����0~9��Ͱ
	int b[10] = {0};//�洢0~9��Ͱ�и��ж��ٸ���Чֵ
	int i,j,index;
	for(i = 0;i < len;i++){
		index = getbit(p[i],digit);//��ȡp[i]��digit+1λ������
		bucket[index][b[index]] = p[i];//��p[i]����digit��Ͱ��
		b[index]++;
	}
	int k = 0;
	for(i = 0;i < 10;i++){
  		j = 0;
		while(j < b[i]){
			p[k++] = bucket[i][j];
   			j++;
		}
	}//������digit+1λ�ϵ����ֽ���Ͱ�����õ�����������װ��arr������
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
