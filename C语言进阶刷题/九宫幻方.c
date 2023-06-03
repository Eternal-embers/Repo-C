#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arr[8][9]={ 
                  {4,9,2,3,5,7,8,1,6},
                  {4,3,8,9,5,1,2,7,6},
                  {2,9,4,7,5,3,6,1,8},
                  {2,7,6,9,5,1,4,3,8},
                  {8,1,6,3,5,7,4,9,2},
                  {8,3,4,1,5,9,6,7,2},
                  {6,1,8,7,5,3,2,9,4},
                  {6,7,2,1,5,9,8,3,4}
                };
  int i,j,k,ans = 0,a[9];
  for(i = 0;i<9;i++) 
  scanf("%d",&a[i]);
  for(i = 0;i<8;i++){
    for(j = 0;j<9;j++){
      if(a[j]>0 && a[j]!=arr[i][j])break;
    }
    if(j==9){
      for(k = 0;k<9;k++){
        a[k] = arr[i][k];
      }
      ans++;
    }
  }
  if(ans==1)
  for(i = 0;i<9;i++){
    if(i%3==0) printf("\n");
    printf("%d ",a[i]);
  }
    else printf("Too Many");
  return 0;
}
