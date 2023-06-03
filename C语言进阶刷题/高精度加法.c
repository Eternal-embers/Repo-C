#include<stdio.h>
int main()
{
	int a[100]={0},b[100]={0},i=0,bt1=1,bt2=1,bit,add=0,count = 0;
	do{
		scanf("%d",&a[bt1]);
	}while(a[bt1++]!=11);
	a[bt1-1] = 0;
	bt1-=2;
	do{
		scanf("%d",&b[bt2]);
	}while(b[bt2++]!=11);
	b[bt2-1] = 0;
	bt2-=2;
	bit = (bt1>bt2)?bt1:bt2;
	int res[bit+1];
	for(i = bit;i>=0;i--){
	res[i] = a[i]+b[i]+add;
	if(res[i]>=10) add = 1;
		else add = 0;
	res[i]%=10;
	}
	if(res[0]!=0){
	printf("%d",res[0]);
	count++;
	}
	for(i = 1;i<=bit;i++){
	printf("%d",res[i]);
	count++;
	if(count%3==0)printf(",");
	}
	return 0;
}
