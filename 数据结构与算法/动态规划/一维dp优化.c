#include<stdio.h>
unsigned long long f(int n){
	if(n<=2) return n;
	int i;
	unsigned long long pre,cur,ans;
	pre = 1;
	cur = 2;
	for( i = 2;i<n;i++){
		ans = pre + cur;
		pre = cur;
		cur = ans;
	}
	return ans;
}//最大求到91 
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",f(n));
	return 0;
}
