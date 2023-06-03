#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	//i<=n表示喝完三瓶后还能剩下
	for(i = 3;i <= n;i+=3)
		n++;//每次喝三瓶，换一瓶
	printf("%d",n);
	return 0;
}
