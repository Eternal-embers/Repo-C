#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s[205];
	int n;
	while(cin >> n,n != 0){
		int min = 0;
		for(int i = 0;i < n;i++){
			cin >> s[i];
			reverse(s[i].begin(),s[i].end());
			if(s[min].size() > s[i].size()) min = i;
		}
		bool flag = true;
		int k = 0;
		while(flag && k <= s[min].size()){
			k++;
			for(int i = 0;i < n;i++){
				if(s[min].substr(0,k) != s[i].substr(0,k)){
					flag = false;
					break;
				}
			}
		}
		string res = s[min].substr(0,k-1);
		reverse(res.begin(),res.end());
		cout << res << endl;
	}
	return 0;
}
