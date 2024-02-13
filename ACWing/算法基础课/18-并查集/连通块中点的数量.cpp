#include<iostream>

using namespace std;

const int N = 100005;

int n, m;
int p[N], cnt[N];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		p[i] = i;
		cnt[i] = 1;
	}
	while(m--){
		char op[3];
		int a, b;
		scanf("%s", op);
		if(op[0] == 'C'){
			scanf("%d%d", &a, &b);
			if(find(a) == find(b)) continue;
			cnt[find(b)] += cnt[find(a)];
			p[find(a)] = find(b);
		}
		else if(op[1] == '1'){
			scanf("%d%d", &a, &b);
			cout << (find(a) == find(b) ? "Yes" : "No") << endl;
		}
		else{
			scanf("%d", &a);
			printf("%d\n",cnt[find(a)]);
		}
	}
	
	return 0;
}
