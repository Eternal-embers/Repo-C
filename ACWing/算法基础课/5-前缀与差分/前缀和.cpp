#include<iostream>

using namespace std;

const int N = 100005;

int q[N],s[N];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&q[i]);
	
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + q[i];
	
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",s[r] - s[l - 1]);
	}
	
	return 0;
}

/*
    前缀和函数：partial_sum(q + 1, q + n + 1, s + 1);
    在头文件numeric里
*/
