#include<stdio.h>
char s[30][60];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dfs(int x,int y){
	int i,count = 1;
	s[x][y] = '0';
	for(i = 0;i < 4;i++){
		int a = x + dx[i];
		int b = y + dy[i];
		if(a >=0 && a < 30 &&  b>=0 && b < 60 && s[a][b]=='1') {
			count += dfs(a,b);
		}
	}
	return count;
}
int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	char ch;
	char *p = &s[0][0];
	FILE *fp = fopen("D:\\data\\Êý×Ö¾ØÕó.txt","r");
	int i,j,ans = 0;
	i = 0;
	while(!feof(fp)) {
		ch = fgetc(fp);
		if(ch=='1' || ch=='0') p[i++] = ch;
	}
	for(i = 0;i < 30;i++)
		for(j = 0;j < 60;j++)
			if(s[i][j]=='1'){
				ans = max(ans,dfs(i,j));
			}
	printf("%d",ans);
	return 0;
}
