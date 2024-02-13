#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char s[100];
	gets(s);
	
	int n = strlen(s);
	
	for(int i = 0;i < n;i++){
		int j = i;
		while(j < n && s[j] != ' ') j++;
		
		for(int k = i;k < j;k++) cout << s[k];
		cout << endl;

		i = j;
	}
	return 0;
}
