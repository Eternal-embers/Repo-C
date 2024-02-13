#include<iostream>

using namespace std;

const int N = 1005;

int s[N][N];
int n, m, q;

int main(){
	scanf("%d %d %d",&n, &m, &q);
	int a;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&a);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a;
		}
	}
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		int res = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
		printf("%d\n",res);
	}
	return 0;
}
