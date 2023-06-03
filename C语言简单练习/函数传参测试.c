#include<stdio.h>

void sort(int arr[]) {
	printf("%d\n",arr);
	int i;
	for(i = 0;i < 5;i++){
		printf("%d ",arr[i]);
	}
	putchar('\n');
}

int main(){
	int arr[5] = {1,2,3,4,5};
	printf("%d\n",arr);
	sort(arr);
	return 0;
}

