/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description: ���������C(n,m),C(n,m) = n! / (n-m)! / m!
*/
#include <stdio.h>

int min(int a,int b){
	return a < b ? a : b;
}

// �ݹ�ʵ��
int combinationRecursive(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    } else {
        return combinationRecursive(n - 1, m - 1) + combinationRecursive(n - 1, m);
    }
}

// ��̬�滮ʵ��
int combinationDynamic(int n, int m) {
    int C[n+1][m+1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, m); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][m];
}

int main() {
    int n = 5;
    int m = 2;

    int resultRecursive = combinationRecursive(n, m);
    int resultDynamic = combinationDynamic(n, m);

    printf("C(%d, %d) = %d\n", n, m, resultRecursive);
    printf("C(%d, %d) = %d\n", n, m, resultDynamic);

    return 0;
}


