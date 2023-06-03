#include<iostream>
using namespace std;
long long func(long long x){
	if (x < 9) return x;
	else  return func(x / 9) * 10 + x % 9;
}

int main(){
	int t, i, sum;
	long long x,y;
	cin >> t;
	while (t--){
		long long arr[20]={0};
		i = 0; sum = 0;
		cin >> x;
		y = func(x);
		while (y){
			arr[i++] = y % 10;
			y = y / 10;
		}
		for (int j = 0; j <= i + 1; j++) {
			if (arr[j] >= 5) {
				sum = sum + (9 - arr[j]);
				arr[j + 1]++;
			}
			else sum = sum + arr[j];
		}
		cout << sum << endl;
	}
}
