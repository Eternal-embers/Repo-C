#include<iostram>
#include<vector>
#include<algorithm>

using namespace std;

//大数除以一个较小的数，r为余数
vector<int> div(vector<int> &a,int &b,int &r){
	vector<int> c;
	
	for(int i = a.size() - 1;i >= 0;i--){
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}
	
	reverse(c.begin(),c.end());
	//去除前导0
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}
