#include <stdio.h> 
#include <memory.h> 
#define MAX_NUM 100 
int D[MAX_NUM + 10][MAX_NUM + 10]; 
int N; 
int aMaxSum[MAX_NUM + 10][MAX_NUM + 10]; 
int main() 
{ 
int i, j; 
scanf("%d", & N); 
for( i = 1; i <= N; i ++ ) 
for( j = 1; j <= i; j ++ ) 
scanf("%d", &D[i][j]); 
for( j = 1; j<= N; j ++ ) //给当i=N时，以amaxsum=D[N][j]进行初始化;
aMaxSum[N][j] = D[N][j]; 
for( i = N ; i > 1 ; i -- ) 
for( j = 1; j < i ; j ++ ) { 
if( aMaxSum[i][j] > aMaxSum[i][j+1] ) 
aMaxSum[i-1][j] = aMaxSum[i][j] + D[i-1][j]; 
else 
aMaxSum[i-1][j] = aMaxSum[i][j+1] + D[i-1][j]; 
}
printf("%d", aMaxSum[1][1]); 
return 0;
} 
