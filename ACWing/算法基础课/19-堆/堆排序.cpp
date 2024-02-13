#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;
int n, m;
int h[N], len;

void down(int u){
	int t = u;
	if(2 * u <= len && h[2 * u] < h[t]) t = 2 * u;
	if(2 * u + 1 <= len && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if(t != u){
		swap(h[u], h[t]);
		down(t);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
	len = n;
	
	for(int i = n / 2;i;i--) down(i);
	
	while(m--){
		printf("%d ", h[1]);
		h[1] = h[len];
		len--;
		down(1);
	}
}


