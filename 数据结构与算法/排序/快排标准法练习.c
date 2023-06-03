#include<stdio.h>
void quickSort(int arr[],int left,int right){
    if(left < right){
        int i = left;
        int j = right;
        int pivot = left;
        int temp;
        while(i < j){
            while(arr[i] <= arr[pivot] && i < right)
                i++;
            while(arr[j] > arr[pivot])
                j--;
            if(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);
    }
}
int main(){
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i = 0;i < N;i++)
        scanf("%d",&arr[i]);
    quickSort(arr,0,N-1);
    for(i = 0;i < N;i++)
        printf("%d ",arr[i]);
    putchar('\n');
    for(i = N-1;i >= 0;i--)
        printf("%d ",arr[i]);
    return 0;
}
