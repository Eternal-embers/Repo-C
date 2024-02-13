#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 100005;

int n;
int h[N], len;
int hp[N], ph[N], m;

void heap_swap(int a, int b){
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u){
	int t = u;
	if(2 * u <= len && h[2 * u] < h[t]) t = 2 * u;
	if(2 * u + 1 <= len && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if(t != u){
		heap_swap(u, t);
		down(t);
	}
}

void up(int u){
	while(u / 2 && h[u / 2] > h[u]){
		heap_swap(u / 2, u);
		u /= 2;
	}
}

int main(){
	scanf("%d", &n);
	while(n--){
		char op[3];
		int k, x;
		
		scanf("%s", op);
		if(op[0] == 'I'){
			scanf("%d", &x);
			len++, m++;
			h[len] = x;
			ph[m] = len, hp[len] = m;
			up(len);
		}
		else if(op[0] == 'P') printf("%d\n", h[1]);
		else if(!strcmp(op,"DM")) {
			heap_swap(1,len);
			len--;
			down(1);
		}
		else if(!strcmp(op,"D")){
			scanf("%d", &k);
			k = ph[k];
			heap_swap(k, len);
			len--;
			down(k), up(k);
		}
		else{
			scanf("%d%d", &k, &x);
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
	}
	
	return 0;
}
