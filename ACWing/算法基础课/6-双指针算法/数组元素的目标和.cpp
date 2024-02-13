#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;
int n, m, x;
int a[N], b[N];


int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);
	for(int i = 0;i < m;i++) scanf("%d", &b[i]);
	
	for(int i = 0, j = m - 1;i < n; i++){
		while(j >= 0 && a[i] + b[j] > x) j--;
		if(a[i] + b[j] == x){
			printf("%d %d\n",i ,j);
			break;
		}
	}
	return 0;
}
