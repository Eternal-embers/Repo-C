#include<iostream>

using namespace std;

const int N = 100005;

int m;

int stk[N], top = 0;

int main(){
	cin >> m;
	while(m--){
		string op;
		int x;
		cin >> op;
		if(op == "push"){
			cin >> x;
			stk[top++] = x;
		}
		else if(op == "pop") top--;
		else if(op == "empty") cout << (top > 0 ? "NO" : "YES") << endl;
		else if(op == "query") cout << stk[top - 1] << endl;
	}
	
	return 0;
}
