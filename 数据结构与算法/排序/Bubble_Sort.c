#include<stdio.h>
#include<stdlib.h>
#define N 30

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

void Bubble_Sort(int arr[],int n){
 	int i,j;
	for(i = 0;i < n;i++){
		for(j = 0;j < n - i - 1;j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	Bubble_Sort(arr,N);
	showArray(arr,N);
	return 0;
}
