#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[1005];

int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n);
	/* ˫ָ���㷨 */
	int l = 1;
	for(int r = 1;r < n;r++){
		if(a[r] != a[l - 1])//�����ظ���Ԫ�ط��õ�����ǰ��
			a[l++] = a[r];
	}
	cout << l << endl;
	return 0;
}
