#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int q[N],tmp[N];

/*
	当整个序列为从大到小排序时，逆序对个数是n(n - 1) / 2
	n = 1e5 时，逆序对个数约为5e9，所以返回值采用long long
*/
LL merge_sort(int l,int r){
	if(l >= r) return 0;
	
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);//求得[l,mid]和[mid + 1,r]的内部逆序对
	
	//求得跨越[l,mid]与[mid + 1,r]的逆序对
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r){
		if(q[i] <= q[j]) tmp[k++] = q[i++];
		else {//q[i] > q[j]，[i,mid]之间的数与q[j] 构成逆序对
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	
	while(i <= mid) tmp[k++] = q[i++];
	while(j <= r) tmp[k++] = q[j++];
	
	for(i = l,j = 0;i <= r;i++, j++) q[i] = tmp[j];
	
	return res;
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> q[i];
	
	cout << merge_sort(0, n - 1) << endl;
	return 0;
}
