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

/*
void Insertion_Sort(int arr[],int n){
	int i,j,temp;
	for(i = 1;i < n;i++){
		temp = arr[i];
		for(j = i - 1;j >= 0;j--){
			if(temp < arr[j]) arr[j + 1] = arr[j];
			else break;
		}
		arr[j + 1] = temp;
	}
}
*/

void Insertion_Sort(int arr[],int n){
	int i,j,low,high,mid,temp;
	for(i = 1;i < n;i++){
		low = 0;
		high = i - 1;
		temp = arr[i];
		while(low <= high) {
			mid = (low + high) / 2;
			if(temp < arr[mid]) high = mid - 1;
			else low = mid + 1;
		}
		for(j = i - 1;j >= high + 1;j--){
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = temp;
	}
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	Insertion_Sort(arr,N);
	showArray(arr,N);
	return 0;
}
