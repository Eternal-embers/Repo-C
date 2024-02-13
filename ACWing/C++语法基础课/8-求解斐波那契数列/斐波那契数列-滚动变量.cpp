#include<iostream>
using namespace std;

int main(){
    int n;
	cin >> n;
	if(n <= 1) return 1;
	int x,y,z;
	x = 0,y = 1;
	for(int i = 2;i <= n;i++){
		z = x + y;
		x = y;
		y = z;
	}
	cout << z;
	return 0;
}
