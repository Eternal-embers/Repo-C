#include<iostream>
using namespace std;

int n,m,res = 0;
int dfs(int x,int y){
    if(x == 0 && y == 0) res++;
    if(x > 0) dfs(x - 1,y);
    if(y > 0) dfs(x,y - 1);
}

int main(){
    cin >> n >> m;
    dfs(n,m);
    cout << res << endl;
    return 0;
}
