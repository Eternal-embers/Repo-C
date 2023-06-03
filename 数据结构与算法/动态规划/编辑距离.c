#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min(int a,int b,int c){
	if(a>b) a = b;
	if(a>c) a = c;
	return a;
}
int mindistance(char *s1,char *s2){
	int length1 = strlen(s1);
	int length2 = strlen(s2);
	int i,j,dp[length1+1][length2+1];
	for(i = 0;i<=length1;i++){
		dp[i][0] = i;//只需删除操作 
	}
	for(i = 0;i<=length2;i++){
		dp[0][i] = i;//只需插入操作 
	}
	for(i = 1;i<=length1;i++){
		for(j = 1;j<=length2;j++)
		{
			//如果s1[i]与s2[j]相等,第i个字符对应的下标应该是i-1; 
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];//如果s1第i个字符与s2第j个字符相等 
				else dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
		}
	}
	return dp[length1][length2];
}

int main()

{
	char s1[50],s2[50];
	scanf("%s%s",s1,s2);
	printf("%d",mindistance(s1,s2));
	return 0;
}
