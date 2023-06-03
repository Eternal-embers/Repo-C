#include<stdio.h>
/* 模拟蛇形填数 */
int main(){
	int a[50][50],i,j,row,col,num = 1;
	for(i = 0;i < 50;i++){
		/* 填i行，每行填一个数*/
		col = i;//第一行从第i个开始填
		for(row = 0;row <= i;row++){
			a[row][col] = num;
			num++;
			col--;
		}
	}
	printf("%d",a[19][19]);
	return 0;
}

