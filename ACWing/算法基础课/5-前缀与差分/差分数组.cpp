#include<iostream>

using namespace std;

const int N = 100005;

int n,m;
int a[N],b[N];

void insert(int l,int r,int c){
	b[l] += c;
	b[r + 1] -= c;
}

int main(){
	scanf("%d%d",&n, &m);
	
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	
	//构造差分数组
	for(int i = 1;i <= n;i++) b[i] = a[i] - a[i - 1];
	
	while(m--){
		int l,r,c;
		scanf("%d%d%d",&l, &r, &c);
		insert(l, r, c);
	}
	
	//求差分数组的前缀和即，最后的a数组结果记录在b数组中
	for(int i = 1;i <= n;i++) b[i] += b[i - 1];
	
	for(int i = 1;i <= n;i++) printf("%d ",b[i]);
	
	return 0;
}
