#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100005;

int h[N], len;


void down(int u){
	int t = u;
	if(2 * u <= len && h[2 * u] < h[t]) t = 2 * u;
	if(2 * u + 1 <= len && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if(t != u){
		swap(h[t], h[u]);
		down(t);
	}
}

void up(int u){
	while(u / 2 && h[u / 2] > h[u]){
	   swap(h[u], h[u / 2]);
	   u / = 2;
	}
}

//构建堆
for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
len = n;
for(int i = len / 2;i;i--) down(i);

//向堆中插入 x
len++;
h[len] = x;
up(len);

//删除最小的元素
h[1] = h[len];
len--;
down(1);
