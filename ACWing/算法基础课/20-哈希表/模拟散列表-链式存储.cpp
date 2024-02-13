#include<iostream>
#include<cstring>

using namespace std;

const int N = 100003;

int m;
int h[N], e[N], ne[N], idx;

void insert(int x){
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int x){
	int k = (x % N + N) % N;
	for(int i = h[k];i != -1;i = ne[i])
		if(e[i] == x) return true;
	return false;
}

int main(){
	scanf("%d", &m);
	
	memset(h, -1, sizeof h);
	
	char op[2];
	int x;
	while(m--){
		scanf("%s%d", op, &x);
		if(op[0] == 'I') insert(x);
		else printf("%s\n",find(x) ? "Yes" : "No");
	}
	
	return 0;
}
