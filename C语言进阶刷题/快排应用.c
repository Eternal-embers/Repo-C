#include <stdio.h>
#include <stdlib.h>
void quickSort(int arr[],int left,int right){
  if(left < right){
  	int i,j,pivot,temp;
  	i = left;
  	j = right;
  	pivot = left;
	while(i < j){
    	while(arr[i] <= arr[pivot] && i < right)
      		i++;
    	while(arr[j] > arr[pivot])
      		j--;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
 	}
	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;
  	quickSort(arr,left,j-1);//基准值左边
  	quickSort(arr,j+1,right);//基准值右边
  }
}
int main(int argc, char *argv[])
{
  int L,N,M,i,ans;
  scanf("%d%d%d",&L,&N,&M);
  int D[N+2],jump[N+2];
  D[0] = 0,D[N+1] = L;
  jump[N+1] = 0;
  for(i = 1;i < N+1;i++)
	scanf("%d",&D[i]);
  quickSort(D,0,N+1);
  for(i = 0;i < N + 1;i++)
    jump[i] = (i + M + 1) < (N + 1) ? D[i+M+1]-D[i] : D[N+1]-D[i];
  for(i = 1,ans = jump[0];i < N+2;i++)
	if(ans < jump[i]) ans = jump[i];
  printf("%d",ans);
  return 0;
}
