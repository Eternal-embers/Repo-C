#include<iostream>

using namespace std;

//�ж��Ƿ���a >= b
bool cmp(vector<int> &a,vector<int> &b){
	if(a.size() != b.size()) return a.size() > b.size();
	for(int i = a.size() - 1;i >= 0;i--)
		if(a[i] != b[i])
			return a[i] > b[i];
	return true;
}

//�߾��ȼ���,c = a - b
vector<int> sub(vector<int> &a,vector<int> &b){
	vector<int> c;
	
	for(int i = 0,t = 0;i < a.size();i++){
		t = a[i] - t;
		if(i < b.size()) t -= b[i];
		c.push_back((t + 10) % 10);
		if(t < 0) t = 1;
		else t = 0;
	}
	
	//ȥ��ǰ�õ�0
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}

//����a - b
if(a > b) {
	vector<int> c = sub(a, b);
	for(int i = c.size() - 1;i >= 0;i--) cout << c[i];
}
else{
	vector<int> c = sub(b, a);
	cout << "-";
	for(int i = c.size() - 1;i >= 0;i--) cout << c[i];
}
