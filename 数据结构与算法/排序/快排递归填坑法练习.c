#include<stdio.h>
void quickSort(int arr[],int left,int right){
    if(left < right){
        int i = left;
        int j = right;
        int pivot = left;
        int index = arr[pivot];
        while(i < j){
            while(i < j && arr[j] >= index)
                j--;
            if(i < j) arr[i++] = arr[j];
            while(i < j && arr[i] < index)
                i++;
            if(i < j) arr[j--] = arr[i];
        }
        arr[j] = index;
        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);
    }
}//Ìî¿Ó·¨¿ìËÙÅÅÐò
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
