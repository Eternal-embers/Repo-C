#include<iostream>
#include<algorithm>

/* 高精度加法 */
vector<int> add(vector<int> &a,vector<int> &b){
	vector<int> c;

	if(a.size() < b.size()) return add(b,a);

	int t = 0;
	for(int i = 0;i < a.size();i++){
		t += a[i];
		if(i < b.size()) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if(t) c.push_back(t);

	return c;
}

vector<int> read(string &s){
	vector<int> q;
	for(int i = s.size() - 1;i >= 0;i--)
		q.push_back(s[i] - '0');
	return q;
}

void print(vector<int> &q){
	for(int i = q.size() - 1;i >= 0;i--) cout << q[i];
}
