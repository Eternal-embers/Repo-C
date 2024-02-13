#include<iostream>

using namespace std;

const int N = 100005;

int m;

int q[N], hh = 0, tt = -1;


int main(){
	cin >> m;
	while(m--){
		string op;
		int x;

		cin >> op;
		if(op == "push"){
			cin >> x;
			q[++tt] = x;
		}
		else if(op == "pop") hh++;
		else if(op == "empty") cout << (hh > tt ? "YES" : "NO") << endl;
		else if(op == "query") cout << q[hh] << endl;
	}

	return 0;
}
