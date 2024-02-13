#include<iostream>
using namespace std;

int main(){
	string s;
	while(cin >> s,s != "."){
		int i = 1;
		while(i <= s.size()){
			if(s.size() % i == 0){
				bool flag = true;
				for(int j = i;j < s.size();j += i)
					for(int k = 0;k < i;k++)
						if(s[k] != s[j + k])
							flag = false;
				if(flag) break;
			}
			i++;
		}
		cout << s.size() / i << endl;
	}
    return 0;
}
