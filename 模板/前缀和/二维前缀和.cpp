#include<iostream>

using namespace std;

/*
	��άǰ׺��
	s[i,j] = s[i,j - 1] + s[i - 1,j] - s[i-1,j-1] + a[i,j]
	(x1,y1)��(x2,y3)��һ�Ӿ����������֮�ͣ�
	s[x2,y2] - s[x1 - 1,y2] - s[x2,y1 - 1] + s[x1 - 1,y1 - 1]
*/

const int N = 1000;
int s[N][N];

//��ǰ׺������
s[i][j] = s[i][j - 1] + s[i - 1][j]  - s[i - 1][j - 1] + a[i][j];

//��(x1,y1)��(x2,y2)��һ�Ӿ����������֮��
sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]

