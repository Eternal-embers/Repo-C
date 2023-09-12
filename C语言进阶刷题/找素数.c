/*
	Name: 找素数
	Copyright:劣等生
	Author:劣等生
	Date: 08/29 10:01
	Description: 素数筛
*/
#include<stdio.h>
#include<math.h>
#include<memory.h>

int prime[4800] = {0};//根号2147483647下共4791个素数

int main(){
	int a,b,res = 0;
	scanf("%d %d",&a,&b);

	/* 找出sqrt(b)之前的全部素数 */
	int cnt = 0;//记录sqrt(2147483647)内的全部素数个数
	int i,j,t,n = 46340;
	for(i = 2;i <= n;i++){
		t = sqrt(i);
		for(j = 2;j <= t;j++)
			if(i % j == 0) break;
		if(j > t)
			prime[cnt++] = i;
	}

	if(a < 46340){
		t = b < 46340 ? b : 46340;
		for(i = a;i <= t;i++){
			for(j = 0;j < cnt;j++)
				if(i == prime[j]) {
					res++;
					break;
				}
		}
	}
	
	t = a > 46341 ? a : 46341;
	for(i = t;i <= b;i++){
		for(j = 0;j < cnt;j++)
			if(i % prime[j] == 0) break;
		if(j >= cnt) res++;
	}
	
	printf("%d",res);
	return 0;
}

