#include<stdio.h>
int main(){
	int n,m,res = 0;//n为饮料数，m为瓶盖数
    scanf("%d",&n);
	while(n > 0 || m >=3){
		res += n;
		m += n;
		n = m / 3;
		m %= 3;
	}
	printf("%d",res);
}
