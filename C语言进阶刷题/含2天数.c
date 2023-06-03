#include<stdio.h>
/*
小蓝特别喜欢2，今年是公元2020 年，他特别高兴，因为每天日历上都可以看到2
如果日历中只显示年月日，请问从公元1900 年1 月1 日到公元9999 年
12 月31 日，一共有多少天日历上包含2。即有多少天中年月日的数位中包含数字2。
*/
int day[] = {
	0,31,28,31,30,31,30,31,30,31,31,30,31
};
_Bool is_leap(int y){
	return y % 400==0 || y % 4==0 && y % 100!=0;
}//判读闰年
int daysOfMonth(int y,int m){
	if(m==2) return 28 + is_leap(y);
	return day[m];
}//获取某月的最大天数
_Bool check(int x,int y,int z){
	int a[] = {x,y,z},i;
	for(i = 0;i < 3;++i)
		while(a[i] > 0)
			if(a[i] % 10 ==2) return 1;
				else a[i] /= 10;
   return 0;
}//检查年月日中是否有2
int main(){
	int i,j,k;
	int res = 0;
	for(i = 1900;i <= 9999;i++)
		for(j = 1;j <= 12; ++j)
			for(k = 1; k <= daysOfMonth(i,j);k++)
				res += check(i,j,k);
   printf("%d",res);
}
