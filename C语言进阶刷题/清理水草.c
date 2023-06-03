#include<stdio.h>
#include<memory.h>
int main(){
    int n,m,t;
    int i,j,k,ans = 0;
    scanf("%d%d%d",&n,&m,&t);
    int c[t][4];//r1,c1,r2,c2;
    int g[n][m];//²Ý
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++)
			g[i][j] = 1;
	}
    for(i = 0;i < t;i++)
        scanf("%d%d%d%d",&c[i][0],&c[i][1],&c[i][2],&c[i][3]);
    for(i = 0;i < t;i++)
        for(j = c[i][0]-1;j <= c[i][2]-1;j++)
            for(k = c[i][1]-1;k <= c[i][3]-1;k++)
				g[j][k] = 0;
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
            if(g[i][j]==1) ans++;
    printf("%d",ans);
    return 0;
}
