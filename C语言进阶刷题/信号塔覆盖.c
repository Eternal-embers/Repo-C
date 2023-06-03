#include<stdio.h>
#include<math.h>
int main(){
	int w,h,n,r,ans = 0;
	scanf("%d%d%d%d",&w,&h,&n,&r);
	int a[w+1][h+1],i,j,k;
	int t[n][2];//塔
	for(i = 0;i < n;i++)
		scanf("%d%d",&t[i][0],&t[i][1]);//信号塔坐标(a,b)
	for(i = 0;i <= w;i++)
		for(j = 0;j <= h;j++)
			a[i][j] = 0;//区域清零
	for(i = 0;i <= w;i++)
		for(j = 0;j <= h;j++){
			for(k = 0;k < n;k++)
				if(pow(i-t[k][0],2)+pow(j-t[k][1],2)<=r*r)
					a[i][j] = 1;
		}
	for(i = 0;i <= w;i++)
		for(j = 0;j <= h;j++)
			if(a[i][j]==1) ans++;
	printf("%d",ans);
	return 0;
}
