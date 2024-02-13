#include<iostream>

using namespace std;

/*
	二维前缀和
	s[i,j] = s[i,j - 1] + s[i - 1,j] - s[i-1,j-1] + a[i,j]
	(x1,y1)到(x2,y3)这一子矩阵的所有数之和：
	s[x2,y2] - s[x1 - 1,y2] - s[x2,y1 - 1] + s[x1 - 1,y1 - 1]
*/

const int N = 1000;
int s[N][N];

//求前缀和数组
s[i][j] = s[i][j - 1] + s[i - 1][j]  - s[i - 1][j - 1] + a[i][j];

//求(x1,y1)到(x2,y2)这一子矩阵的所有数之和
sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]

