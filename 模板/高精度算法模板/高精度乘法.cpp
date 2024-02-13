#include<iostraem>

using namespace std;

//大数乘以一个较小的数
vector<int> mul(vector<int> &a,int b){
	vector<int> c;
	
	int t = 0;
	for(int i = 0;i < a.size() || t;i++){
		if(i < a.size()) t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	
	//处理b = 0的情况
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	
	return c;
}


