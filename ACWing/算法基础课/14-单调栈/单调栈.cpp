#include<iostream>

using namespace std;

const int N = 100005;

int m;

int stk[N], tt = 0;

int main(){
	cin >> m;
	for(int i = 0;i < m;i++){
		int x;
		cin >> x;
		while(tt && stk[tt] >= x) tt--;
		if(tt) cout << stk[tt] << ' ';
		else cout << -1 << ' ';
		
		stk[++tt] = x;
	}
	return 0;
}
