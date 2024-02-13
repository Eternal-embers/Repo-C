#include<iostream>

using namespace std;

int main(){
	double x;
	cin >> x;

	double l = -10000,r = 10000;
	while(l - r > 1e-8){
		double m = (l + r) / 2;
		if(m * m * m >= x) r = m;
		else l = m;
	}
	
	printf("%.6f",l);
	return 0;
}
