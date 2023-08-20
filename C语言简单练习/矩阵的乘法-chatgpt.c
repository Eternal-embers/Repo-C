/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/

#include <stdio.h>

void block_multiply(int A[][4], int B[][4], int C[][4], int n, int blockSize, int i, int j, int k) {
    if (i >= n || j >= n || k >= n) {
        return;
    }

    for (int x = i; x < i + blockSize && x < n; x++) {
 for (int y = k; y < k + blockSize && y < n; y++) {
            for (int z = j; z < j + blockSize && z < n; z++) {
                C[x][z] += A[x][y] * B[y][z];
            }
        }
    }

    if (k + blockSize >= n) {
        block_multiply(A, B, C, n, blockSize, i, j + blockSize, 0);
    } else {
        block_multiply(A, B, C, n, blockSize, i, j, k + blockSize);
    }

    if (j + blockSize >= n) {
        block_multiply(A, B, C, n, blockSize, i + blockSize, 0, 0);
    } else {
        block_multiply(A, B, C, n, blockSize, i, j + blockSize, 0);
    }
}

int main() {
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10 11, 12}, {13, 14, 15, 16}};
    int C[4][4] = {0};

    int n = 4; // 矩阵维度
    int blockSize = 2; // 分块大小

    block_multiply(A, B, C, n, blockSize, 0, 0, 0);

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

