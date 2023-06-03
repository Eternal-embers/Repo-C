 #include <stdio.h>
 #define MAX_NUM 100 
 int D[MAX_NUM + 10][MAX_NUM + 10]; 
 int N; 
 int MaxSum( int r, int j) 
 { 
 if( r == N ) 
 return D[r][j]; 
int nSum1 = MaxSum(r+1, j); 
int nSum2 = MaxSum(r+1, j+1); 
if( nSum1 > nSum2 ) 
return nSum1+D[r][j]; 
return nSum2+D[r][j]; 
 } 
int main() 
 { 
 int m; 
 scanf("%d", &N); 
 for( int i = 1; i <= N; i ++ ) 
 for( int j = 1; j <= i; j ++ ) 
 scanf("%d", &D[i][j]); 
 printf("%d", MaxSum(1, 1)); 
 return 0;
} 
