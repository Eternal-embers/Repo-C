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
	int i,j,dp[length2+1],pre,temp;
	for(j = 0;j<=length2;j++){
		dp[j] = j;//³õÊ¼»¯dp[0][j]; 
	}
	for(i = 1;i<=length1;i++){
	temp = dp[0];//pre = dp[i-1][0];
	dp[0] = i;//dp[i][0] = 1; 
		for(j = 1;j<=length2;j++)
		{
			pre = temp;//pre = dp[i-1][j-1];
			temp = dp[j];//temp = dp[i-1][j]; 
			if(s1[i-1]==s2[j-1]) dp[j] = pre;
				else dp[j] = min(pre,dp[j-1],dp[j])+1;//dp[i][j]
		}
	}
	return dp[length2];
}

int main()
{
	char s1[50],s2[50];
	scanf("%s%s",s1,s2);
	printf("%d",mindistance(s1,s2));
	return 0;
}
