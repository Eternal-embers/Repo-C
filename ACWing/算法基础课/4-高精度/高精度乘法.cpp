#include<iostream>
#include<vector>

using namespace std;

vector<int> mul(vector<int> a,int b){
	vector<int> c;
	
	int t = 0;
	for(int i = 0;i < a.size() || t;i++){
		if(i < a.size()) t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}

int main(){
	string s;
	vector<int> a;
	int b;
	cin >> s >> b;
	for(int i = s.size() - 1;i >= 0;i--) a.push_back(s[i] - '0');
	
	vector<int> c = mul(a,b);
	
	for(int i = c.size() - 1;i >= 0;i--) cout << c[i];
	return 0;
}
