/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/30 16:35
	Description: 约瑟夫环
*/
#include<stdio.h>
#include<stdbool.h>

int a[10004];
bool b[10004];
int cnt = 0;
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int i = k > n ? k % n : k,j = 1;
	while(cnt != n){
		if(!b[i]){ //如果没有出局
			//报数j
			if(j == m) {
				printf("%d\n",i);
				b[i] = true;///记录第i个人出局
				cnt++;//记录出局一人
				j = 0;
			}
			j++;
		}
		i = i % n;
		i++;//下一个人
	}
	return 0;
}

