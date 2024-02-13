#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s){
	if(y == n) y = 0, x++;//����
	if(x == n){
		if(s == n){
			for(int i = 0;i < n;i++) puts(g[i]);
			puts("");
		}
		
		return;//��s != n������ʧ�ܣ����ݵ���һ�η���
	}
	
	//����(x,y)�Żʺ�
	dfs(x, y + 1, s);
	
	//��(x,y)�Żʺ�
	if(!row[x] && !col[y] && !dg[y + x] && !udg[y - x + n]){
		//���
		g[x][y] = 'Q';
		row[x] = col[y] = dg[y + x] = udg[y - x + n] = true;
		
		dfs(x, y + 1, s + 1);//��̽��һ������
		
		//�ָ��ֳ�
		row[x] = col[y] = dg[y + x] = udg[y - x + n] = false;
		g[x][y] = '.';
	}
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			g[i][j] = '.';

	dfs(0, 0, 0);
	
	return 0;
}
