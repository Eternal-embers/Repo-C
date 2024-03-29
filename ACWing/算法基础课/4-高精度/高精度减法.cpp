#include<iostream>
#include<vector>

using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
	if(a.size() != b.size()) return a.size() > b.size();
	for(int i = a.size() - 1;i >= 0;i--)
		if(a[i] != b[i])
			return a[i] > b[i];
	return true;
}

vector<int> sub(vector<int> &a,vector<int> &b){
	vector<int> c;
	
	for(int i = 0,t = 0;i < a.size();i++){
		t = a[i] - t;
		if(i < b.size()) t -= b[i];
		c.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}

int main(){
	string s1,s2;;
	vector<int> a,b,c;
	
	cin >> s1 >> s2;
	for(int i = s1.size() - 1;i >= 0;i--) a.push_back(s1[i] - '0');
	for(int i = s2.size() - 1;i >= 0;i--) b.push_back(s2[i] - '0');
	
	if(cmp(a, b)){
		c = sub(a, b);
		for(int i = c.size() - 1;i >= 0;i--) cout << c[i];
	}
	else{
		c = sub(b, a);
		cout << "-";
		for(int i = c.size() - 1;i >= 0;i--) cout << c[i];
	}
	return 0;
}
