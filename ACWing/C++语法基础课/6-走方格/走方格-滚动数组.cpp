#include<iostream>
using namespace std;

int n,m;
int dp[11];

int main(){
    cin >> n >> m;
	for(int j = 0;j <= m;j++) dp[j] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			dp[j] = dp[j] + dp[j - 1];
		}
	}
	cout << dp[m] << endl;
    return 0;
}
