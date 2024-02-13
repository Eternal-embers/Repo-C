#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 100005;

int n;
vector<PII> segs;

vector<PII> merge(vector<PII> &segs){
	vector<PII> res;

	sort(segs.begin(),segs.end());

	int start = -2e9, end = -2e9;
	for(PII seg: segs){
		//区间不相交
		if(end < seg.first){
			if(start != -2e9) res.push_back(seg);
			start = seg.first, end = seg.second;
		}
		else end = max(end, seg.second);
	}

	if(start != -2e9) res.push_back({start, end});

	return res;
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++) {
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}

	vector<PII> res = merge(segs);

	cout << res.size() << endl;
	
	return 0;
}

