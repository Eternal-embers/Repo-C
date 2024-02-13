#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int q[N],tmp[N];

/*
	����������Ϊ�Ӵ�С����ʱ������Ը�����n(n - 1) / 2
	n = 1e5 ʱ������Ը���ԼΪ5e9�����Է���ֵ����long long
*/
LL merge_sort(int l,int r){
	if(l >= r) return 0;
	
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);//���[l,mid]��[mid + 1,r]���ڲ������
	
	//��ÿ�Խ[l,mid]��[mid + 1,r]�������
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r){
		if(q[i] <= q[j]) tmp[k++] = q[i++];
		else {//q[i] > q[j]��[i,mid]֮�������q[j] ���������
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
