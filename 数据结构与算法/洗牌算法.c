#include<stdio.h>
#include<time.h>
#define LEN 30
void createData(int arr[],int len){
	int i;
	srand(time(NULL));
	for(i = 0;i < len;i++){
		arr[i] = rand() % (len*2) + 1;
	}
}

void show(int arr[],int len){
	int i;
	for(i = 0;i < len;i++){
		printf("%3d ",arr[i]);
		if((i + 1) % 30 == 0) putchar('\n');
	}
	putchar('\n');
}

void swap(int *a,int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int arr[LEN] = {0};
	int i,j;
	//createData(arr,LEN);
	for(i = 0;i < LEN;i++){
		arr[i] = i;
	}
	show(arr,LEN);
	srand(time(NULL));
	for(i = LEN - 1;i > 0;i--){
		j = rand() % i;//从前面i-1个数中任选一个与arr[i]交换
		swap(&arr[i],&arr[j]);
	}
	show(arr,LEN);
	return 0;
}
