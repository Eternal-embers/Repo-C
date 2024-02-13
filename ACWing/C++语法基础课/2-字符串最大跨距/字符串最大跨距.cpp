#include<iostream>
using namespace std;

int main(){
	string s,s1,s2;
	cin >> s;

	size_t pos1 = s.find(",");
	size_t pos2 = s.rfind(",");
	
	s1 = s.substr(pos1 + 1,pos2 - pos1 - 1);
	s2 = s.substr(pos2 + 1);
	s = s.substr(0,pos1);
	
	size_t lpos = s.find(s1);
	size_t rpos = s.rfind(s2);
	
	if(lpos != npos && rpos != npos && lpos + s1.length() <= rpos)
		cout << rpos - lpos - s1.size();
	else
		cout << -1;
	return 0;
}
