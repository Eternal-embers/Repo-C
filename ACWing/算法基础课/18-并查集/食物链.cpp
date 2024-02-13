#include<iostream>

using namespace std;

const int N = 50005;

int n, m;
int p[N], d[N];

int find(int x){
	if(p[x] != x){
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	
	return p[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) p[i] = i;
	
	int res = 0;
	while(m--){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(x > n || y > n) res++;
		else{
			int px = find(x), py = find(y);
			if(t == 1){
				if(px == py && (d[x] - d[y]) % 3) res++;
				else if(px != py){
					p[px] = p[py];
					d[px] = d[y] - d[x];//(d[x] + d[px] - d[y]) % 3 == 0
				}
			}
			else{
				if(px == py && (d[x] - d[y] - 1) % 3) res++;
				else if(px != py){
					p[px] = p[py];
					d[px] = d[y] - d[x] + 1;//(d[x] + d[px] - d[y]) % 3 == 1
				}
			}
		}
	}
	
	printf("%d", res);
	
	return 0;
}
