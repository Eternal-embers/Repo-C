#include<stdio.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	char S[1001]={'0'},T[1001]={'0'};
	int lens,lent,i,j;
	gets(S+1);//保证S[j]为S的第j个字符
	gets(T+1);//保证T[i]为T的第i个字符
	lens = strlen(S);
	lent = strlen(T);
	int dp[lent+1][lens+1];//dp[i][j]表示S前j个字符转换包含T前i个字符所需要的操作数
	for(j = 0;j<lens;j++){
		dp[0][j] = 0;//当T为空时，只需删除字符即可，而删除不算操作
	}
	//由于一个字符串s1要包含另一个s2则s1中的字符数必须大于等于s2
	for(i = 1;i<=lent;i++){
	//由于计算dp[i][i]时无法对S中的字符进行删除操作，所以要单独计算j==i的情况
	if(T[i]==S[i]) dp[i][i] = dp[i-1][i-1];
		else dp[i][i] = dp[i-1][i-1]+1;//只进行替换
		for(j = i+1;j<=lens;j++)
		if(T[i]==S[j]) dp[i][j] = dp[i-1][j-1];//T中第i个字符等于S中第j个字符
		else {
			dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+1);//删除或替换
		}
	}
	printf("%d",dp[lent][lens]);
	return 0;
}
