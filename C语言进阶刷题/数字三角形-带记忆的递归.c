#include <stdio.h> 
#include <memory.h> 
#define MAX_NUM 100 
int D[MAX_NUM + 10][MAX_NUM + 10]; 
int N; 
 int aMaxSum[MAX_NUM + 10][MAX_NUM + 10]; 
 int MaxSum( int r, int j) 
 { 
 if( r == N ) 
 return D[r][j]; 
 if( aMaxSum[r+1][j] == -1 )//如果没有计算过 
 aMaxSum[r+1][j] = MaxSum(r+1, j); 
 if( aMaxSum[r+1][j+1] == -1) //如果没有计算过 
 aMaxSum[r+1][j+1] = MaxSum(r+1, j+1); 
 if( aMaxSum[r+1][j] > aMaxSum[r+1][j+1] ) 
return aMaxSum[r+1][j] +D[r][j]; 
 return aMaxSum[r+1][j+1] + D[r][j]; 
} 
int main() 
{ 
int m; 
scanf("%d", & N); 
//将 aMaxSum全部置成-1, 表示开始所有的 MaxSum(r, j)都没有算过 
memset(aMaxSum, -1, sizeof(aMaxSum)); 
for( int i = 1; i <= N; i ++ ) 
for( int j = 1; j <= i; j ++ ) 
scanf("%d", & D[i][j]); 
printf("%d", MaxSum(1, 1)); 
return 0;
} 
