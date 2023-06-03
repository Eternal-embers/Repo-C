#include<stdio.h>
int main()
{
	int arr[] = {[2]=2,[4]=4,5,6,[2]=100,101,102};//[n]后面的赋值依次是[n+1]、[n+2]、[n+3]... ,如果出现[k]则赋值从[k]依次赋值
	//后面重新赋值可以覆盖前面的赋值
	int i;
	for(i=0;i<7;i++)
	printf("%d ",arr[i]);
	return 0;
}
