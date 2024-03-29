#include<iostream>

using namespace std;

const int N = 1e5 + 5;
int n,q,k;
int a[N];

int main(){
	cin >> n >> q;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	while(q--){
		cin >> k;

		int l = 0,r = n - 1;
		while(l < r){
			int mid = l + r >> 1;
			if(a[mid] >= k) r = mid;
			else l = mid + 1;
		}
		if(a[l] != k) {
			cout << "-1 -1" << endl;
			continue;
		}
		else{
			cout << l << " ";
			l = 0,r = n - 1;
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(a[mid] <= k) l = mid;
				else r = mid - 1;
			}
			cout << l << " " << endl;
		}
	}
	return 0;
}
