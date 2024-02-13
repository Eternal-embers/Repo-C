#include<iostream>
using namespace std;

int n;
bool v[11];
int s[10],top = 0;

void dfs(int cnt){
   if (cnt == n){
   	    for(int i = 0;i < n;i++)
			cout << s[i] << " ";
		cout << endl;
		return;
   }
   for(int i = 1;i <= n;i++){
        if(!v[i]) {
			v[i] = true;
            s[top++] = i;
            dfs(cnt + 1);
            v[i] = false;
            top--;
        }
    }
}

int main(){
    cin >> n;
	dfs(0);
    return 0;
}
