/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 08/31 15:37
	Description: N皇后问题
*/
#include<stdio.h>

int n;
int sum = 0;
int a[20] = {0};//a[x] = y表示第x列的第y个位置放置皇后

int abs(int num){
	return num > 0 ? num : -num;
}

/* 判断(x,y)位置是否可以放 */
_Bool place(int x,int y){
	int i;
	for(i = 0;i < x;i++)
		if(abs(x - i) == abs(y - a[i]) || y == a[i]) return 0;
	return 1;
}

void backTrace(int x){
	if(x == n)
		sum++;
	else{
		int y;
		for(y = 0;y < n;y++){
			a[x] = y;//在(x,y)位置放皇后
			if(place(x,y)) backTrace(x + 1);//如果能放就继续放下一个
		}
	}
}

int main(){
	scanf("%d",&n);
	backTrace(0);
	printf("%d",sum);
	return 0;
}

