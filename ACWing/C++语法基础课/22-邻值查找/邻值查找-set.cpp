#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int n;

int main(){
	set<pair<int,int>> a;
	a.insert({2e9,-1});
	a.insert({-2e9,-1});

	cin >> n;
	if(n == 2) {
	    cout << "2000000000 1" << endl;
	    return 0;
	}

	int x;
	cin >> x, a.insert({x,1});
	for(int i = 2;i <= n;i++){
		cin >> x;
		if(i > 1){
			auto right = a.upper_bound({x,-1});
			auto left = right;
			left--;

		    int r = abs(right->first - x);
			int l = abs(x - left->first);

			if(l <= r)
				cout << l << ' ' << left->second << endl;
			else
				cout << r << ' ' << right->second << endl;
		}

		a.insert({x,i});
	}

	return 0;
}
