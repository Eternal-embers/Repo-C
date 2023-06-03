#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,ans=5;
	for(i = 2000;i<=2099;i++){
	if(i%4==0&&i%100!=0 || i%400==0) ans = (ans+366)%7;
	else ans = (ans+365)%7;
	}
	printf("%d",ans);
	return 0;
}
