#include<iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s,s != "."){
		int k = 1;
		while(k <= s.size()){
			if(s.size() % k == 0){
				bool flag = true;
				for(int i = k;i < s.size();i += k)
					if(s.substr(0,k) != s.substr(i,k))
						flag = false;
				if(flag) break;
			}
			k++;
		}
		cout << s.size() / k << endl;
	}
    return 0;
}
