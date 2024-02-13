#include<iostream>
using namespace std;

int n,m;
int f(int x,int y){
    if(x == 0 && y == 0) return 1;
	if(x < 0 || y < 0) return 0;
	else return f(x - 1,y) + f(x,y - 1);
}

int main(){
    cin >> n >> m;
    cout << f(n,m) << endl;
    return 0;
}
