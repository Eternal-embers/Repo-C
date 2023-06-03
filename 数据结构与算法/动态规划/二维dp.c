#include<stdio.h>
unsigned long long uniquepath(int m,int n){
	if (m <= 0 || n <= 0) return 0;
    unsigned long long dp[m][n];
	int i,j;
    for( i = 0; i < m; i++){
    	dp[i][0] = 1;
    }
    for(i = 0;i < n;i++){
    	dp[0][i] = 1;
	}
    // 推导出 dp[m-1][n-1]
    for (i = 1; i < m; i++) {
        for ( j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}//最大(35,35) 
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%llu",uniquepath(m,n));
	return 0;
}
