#include<stdio.h>
#include<time.h>
#define N 30
void fillArray(int arr[],int n){
	int i = 0;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}
void showArray(int arr[],int n){
	int i = 0;
	for(i = 0;i<n;i++)
		printf("%3d ",arr[i]);
	printf("\n");
}
void qsort(int arr[],int left,int right){
	int i,j,pivot;
	int temp;
	if(left<right){
		pivot = left;
		i = left;
		j = right;
		while(i<j){
			while(arr[i]<=arr[pivot] && i<right)
				i++;
			while(arr[j]>arr[pivot])
				j--;
			if(i<j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		qsort(arr,left,j-1);
   		qsort(arr,j+1,right);
   }
}

int main(){
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	qsort(arr,0,N);
	showArray(arr,N);
	return 0;
}
