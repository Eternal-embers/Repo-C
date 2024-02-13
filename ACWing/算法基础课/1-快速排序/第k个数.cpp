#include<iostream>

using namespace std;

const int N = 100005;
int n, k;
int q[N];

//ʱ�临�Ӷ�O(n)
int quick_sort(int l,int r,int k){
	if(l == r) return q[l];//��֤��k����ʼ��������[l,r]��
	
	int x = q[l],i = l - 1,j = r + 1;
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	int sl = j - l + 1;//[l,j]���������ĸ���
	if(k <= sl) return quick_sort(l, j, k);

	return quick_sort(j + 1, r, k - sl);//��[j + 1, r]Ѱ�ҵ�(k - sl)����
}

int main(){
	cin >> n >> k;
	for(int i = 0;i < n;i++) cin >> q[i];
	
	cout << quick_sort(0, n - 1, k) << endl;
	return 0;
}
