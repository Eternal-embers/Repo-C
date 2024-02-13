#include<iostream>

using namespace std;

const int N = 100005;
int n, k;
int q[N];

//时间复杂度O(n)
int quick_sort(int l,int r,int k){
	if(l == r) return q[l];//保证第k个数始终再区间[l,r]中
	
	int x = q[l],i = l - 1,j = r + 1;
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	int sl = j - l + 1;//[l,j]区间中数的个数
	if(k <= sl) return quick_sort(l, j, k);

	return quick_sort(j + 1, r, k - sl);//在[j + 1, r]寻找第(k - sl)个数
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++) cin >> q[i];
	
	cout << quick_sort(0, n - 1, k) << endl;
	return 0;
}
