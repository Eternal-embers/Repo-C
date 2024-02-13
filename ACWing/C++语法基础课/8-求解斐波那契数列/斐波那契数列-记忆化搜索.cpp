#include<iostream>

using namespace std;

/* ¼ÇÒä»¯ËÑË÷ */
const int MOD = 100000007;
const int N = 100000;
int a[N];
int f(int n){
	if(a[n]) return a[n];
	if(n <= 1) return 1;
	a[n] = f(n-1) + f(n-2);
	a[n] %= MOD;
	return a[n];
}

int main(){
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}

