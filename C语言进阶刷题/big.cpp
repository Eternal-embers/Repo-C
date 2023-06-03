#include<stdio.h>
int main(){
	int T,i,j,k,max;
	long num[11] = {1,9,81,729,6561,59049,531441,4782969,43046721,387420489,3486784401};
	scanf("%d",&T);
	int a[T],cost,temp;
	int dp[50000] = {0};
	for(i = 0;i < T;i++){
		scanf("%d",&a[i]);//ук
	}

	for(i = 0;i < T;i++){
  		for(j = 0;num[j] <= a[i];j++);
  		max = j - 1;
		dp[0] = 0;
		for(j = 1;j <= a[i];j++){
			cost = a[i];
			for(k = 0;k <= max;k++){
				temp = j - num[k];
				if(temp < 0) break;
				else if(temp >= 0 && cost > dp[temp] + 1) cost = dp[temp] + 1;
			}
			dp[j] = cost;
		}
		printf("%d\n",dp[a[i]]);
	}
	return 0;
}
