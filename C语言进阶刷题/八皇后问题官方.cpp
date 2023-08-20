#include "stdio.h"
#include<math.h> 
#define N 8	/* �������̴�baiС */

/* �ж�ĳ��λ���Ƿ���Է��ûʺ󣬿��Է���1�����ܷ���0*/
int place( int k );

/* ���ݺ�����������һ���ʺ���õ����������� */
void backtrack( int i );

/* ��¼��ĸ��� */
int	sum;

 /* ����ÿһ�еĻʺ�λ��,x[i]��ʾ�ʺ�i�������̵ĵ�i�еĵ�x[i]�� */
int	x[N];

int main()
{
	backtrack( 0 );
	printf( "����%d�ֽⷨ", sum );
	return(0);
}

int place( int k )
{
	/*
	���Իʺ�k�ڵ�k�е�x[k]��ʱ�Ƿ���ǰ���ѷ��úõĻʺ��๥���� 
	x[j] ==x[k] ʱ�����ʺ���ͬһ���ϣ�
	abs(k - j) == abs(x[j] - x[k]) ʱ�����ʺ���ͬһб���ϡ�
	����������ʺ󶼿��໥�������ʷ���0��ʾ������������
	*/
	for ( int j = 0; j < k; j++ )
		if ( abs( k - j ) == abs( x[j] - x[k] ) || (x[j] == x[k]) )
			return(0);
	return(1);
}

void backtrack( int t )
{
	/* t == N ʱ���㷨������Ҷ��㣬�õ�һ���µ�N�ʺ󻥲������ķ��÷��� */
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
