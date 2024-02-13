#include<iostream>

using namespace std;

int n;

int lowbit(int x){
	return x & -x;
}

int main(){
	cin >> n;
	
	int x;
	while(n--){
		cin >> x;
		
		int res = 0;
		while(x) x -= lowbit(x), res++;
		
		cout << res << " ";
	}
	
	return 0;
}
