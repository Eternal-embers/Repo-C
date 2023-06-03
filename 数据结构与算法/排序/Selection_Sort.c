#include<stdio.h>
#include<stdlib.h>
#define N 10000

void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand() % 1000 + 1;
}
void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %4d  ",arr[i]);
		if((i+1)%10==0) putchar('\n');
	}
	printf("\n");
}

void Selection_Sort(int arr[],int n){
	int i,j,k;
	for(i = 0;i < n;i++){
		k = i;
		for(j = i + 1;j < n;j++){
			if(arr[k] > arr[j]) {
				k = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
	
	/*
	//—°‘Ò≈≈–Ú”≈ªØ
	int left = 0;
	int right = n - 1;
	while(left < right){
		int min = left;
		int max = right;
		int i;
		for(i = left;i <= right;i++){
			if(arr[i] < arr[min]) min = i;
			if(arr[i] > arr[max]) max = i;
		}
		int temp;
		if(max != right){
			temp = arr[right];
			arr[right] = arr[max];
			arr[max] = temp;
		}
		if(min == right) min = max;
		if(min != left){
			temp = arr[left];
			arr[left] = arr[min];
			arr[min] = temp;
		}
		left++;
		right--;
	}
	*/
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	//showArray(arr,N);
	Selection_Sort(arr,N);
	//showArray(arr,N);
	return 0;
}
