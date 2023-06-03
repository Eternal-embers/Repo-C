#include<stdio.h>
#include<math.h>
int min(int a,int b){
    return a < b ? a : b;
}

int main(){
	int T,i,j,k,max;
	scanf("%d",&T);
	int a[T],res[T],cost,temp;
	for(i = 0;i < T;i++){
		scanf("%d",&a[i]);//ук
	}
	
	for(i = 0;i < T;i++){
		int dp[a[i] + 1];
		for(j = 0;pow(9,j) < a[i];j++);
		max = j - 1;
		dp[0] = 0;
		for(j = 1;j <= a[i];j++){
			cost = a[i];
			for(k = 0;k <= max;k++){
				temp = pow(9,j);
				if(k - temp >= 0) cost = min(cost,dp[k - temp] + 1);
			}
			dp[j] = cost;
			printf("%d\n",dp[j]);
		}
		res[i] = dp[a[i]];
	}
	for(i = 0;i < T;i++){
		printf("%d",res[i]);
	}
	return 0;
}
