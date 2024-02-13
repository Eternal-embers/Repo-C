#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int p[N],l[N],r[N];//双向链表
pair<int,int> a[N],ans[N];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a + 1, a + 1 + n);
	
	a[0].first = 1e9 + 1,a[n + 1].first = -1e9 - 1;
	for(int i = 1;i <= n;i++){
		l[i] = i - 1,r[i] = i + 1;
		p[a[i].second] = i;
	}
	
	for(int i = n;i > 1;i--){
		int j = p[i],left = l[j],right = r[j];
		int lv = abs(a[j].first - a[left].first);
		int rv = abs(a[right].first - a[j].first);
		if(lv <= rv) ans[i] = {lv,a[left].second};
		else ans[i] = {rv,a[right].second};
		
		//删除节点
		r[left] = right,l[right] = left;
	}
	
	for(int i = 2;i <= n;i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
