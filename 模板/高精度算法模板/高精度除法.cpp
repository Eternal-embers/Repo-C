#include<iostram>
#include<vector>
#include<algorithm>

using namespace std;

//��������һ����С������rΪ����
vector<int> div(vector<int> &a,int &b,int &r){
	vector<int> c;
	
	for(int i = a.size() - 1;i >= 0;i--){
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}
	
	reverse(c.begin(),c.end());
	//ȥ��ǰ��0
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}
