#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100005, M = N * 2;//����ͼ�������˶�

int n;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;//ɾ�����ĺ�ʣ����ͨ���е��������ֵ

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//������uΪ���������еĽڵ���
int dfs(int u){
	st[u] = true;//���u�ڵ�
	
	int sum = 1, res = 0;// sumΪ�ڵ�����(��ʼ��Ϊu�ڵ�)
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			int s = dfs(j);//sΪ��jΪ���������Ľڵ���
			res = max(res, s);//resΪö������ɾ�����ڵ��ʣ����ͨ���е��������ֵ
			sum += s;
		}
	}

 	//resΪ��u�ĸ������еĵ��������ֵ��n-sumΪu�ĸ��ڵ�������ͨ������ֵ
	res = max(res, n - sum);
	
	ans = min(ans, res);//�ҳ�ɾ��ĳ�ڵ��ʣ�������ͨ���е��������ֵ��С
	
	return sum;
}

int main(){
	cin >> n;

	memset(h, -1, sizeof h);
	
	for(int i = 0;i < n - 1;i++){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1);//�ڵ�Ϊ1-n
	
	cout << ans << endl;
	
	return 0;
}
