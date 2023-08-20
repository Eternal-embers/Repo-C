#include "stdio.h"
#include<math.h> 
#define N 8	/* 定义棋盘大bai小 */

/* 判断某个位置是否可以放置皇后，可以返回1，不能返回0*/
int place( int k );

/* 回溯函数，搜素上一个皇后放置的其他可能性 */
void backtrack( int i );

/* 记录解的个数 */
int	sum;

 /* 描述每一行的皇后位置,x[i]表示皇后i放在棋盘的第i行的第x[i]列 */
int	x[N];

int main()
{
	backtrack( 0 );
	printf( "共有%d种解法", sum );
	return(0);
}

int place( int k )
{
	/*
	测试皇后k在第k行第x[k]列时是否与前面已放置好的皇后相攻击。 
	x[j] ==x[k] 时，两皇后在同一列上；
	abs(k - j) == abs(x[j] - x[k]) 时，两皇后在同一斜线上。
	两种情况两皇后都可相互攻击，故返回0表示不符合条件。
	*/
	for ( int j = 0; j < k; j++ )
		if ( abs( k - j ) == abs( x[j] - x[k] ) || (x[j] == x[k]) )
			return(0);
	return(1);
}

void backtrack( int t )
{
	/* t == N 时，算法搜索至叶结点，得到一个新的N皇后互不攻击的放置方案 */
	if ( t == N )
		sum++;
	else
		for ( int i = 0; i < N; i++ )
		{
			x[t] = i;
			if ( place( t ) )
			backtrack( t + 1 );
		}
}
