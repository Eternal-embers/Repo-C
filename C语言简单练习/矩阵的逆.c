/*
	Name:矩阵的逆
	Copyright:劣等生
	Author:劣等生
	Date:08/18 23:46
	Description:矩阵的逆
*/
#include<stdio.h>
#include<stdlib.h>

struct Matrix{
	int cols;//列
	int rows;//行
	int *matrix;//矩阵的数组
};

char c[5][3] = {"┌","┐", "└", "┘","│"};

/* 取整 */
int abs(int x){
	return x > 0 ? x : -x;
}

struct Matrix *createMatrix(int rows,int cols,int *matrix){
	struct Matrix *M = (struct Matrix *)malloc(sizeof(struct Matrix));
	M->cols = cols;
	M->rows = rows;
	M->matrix = matrix;
	return M;
}

/* 打印矩阵 */
void matrixPrint(struct Matrix *M){
	int x = M->cols;
	int y = M->rows;
	int *matrix = M->matrix;
	/* 获取矩阵中的绝对值最大的数 */
	int max = 0;
	int i,j;
	for(i = 0;i < y;i++){
		for(j = 0;j < x;j++)
			if(abs(*(matrix + x * i + j)) > max) max = abs(*(matrix + x * i + j));
	}
	int digit = 2;
	/* 求出max的位数 */
	while(max){
		max /= 10;
		digit++;
	}
	/* 输出矩阵 */
	printf("%s ",c[0]);//打印"┌"
	for(j = 0;j < x;j++)
		printf("%*d  ",digit,*(matrix + j));//输出第一行
	printf("%s\n",c[1]);//打印"┐"

	for(i = 1;i < y - 1;i++){
		printf("%s ",c[4]);//打印"│"
		for(j = 0;j < x;j++){
			printf("%*d  ",digit,*(matrix + x * i + j));//输出2 ~ y - 1行
		}
		printf("%s\n",c[4]);//打印"│"
	}

	printf("%s ",c[2]);//打印"└"
	for(j = 0;j < x;j++)
		printf("%*d  ",digit,*(matrix + x * i + j));
	printf("%s\n",c[3]);//打印"┘"
}

/* 求矩阵的逆，只有单位矩阵才有逆 */
struct Matrix *matrixInverse(struct Matrix *M){
	int *matrix = (int *)malloc(sizeof(int) * (M->rows * M->cols * 2));
	struct Matrix *M_inv = createMatrix(M->rows,M->cols * 2,matrix);
	int i,j,k;
	/* 将单位矩阵并入M得到增广矩阵 */
	for(i = 0;i < M_inv->rows;i++){
        for(j = 0;j < M->cols;j++){
        	*(matrix + i * M_inv->cols + j) = *(M->matrix + i * M->cols + j);
		}
	}
	/* 设置增广矩阵右半部分为单位矩阵 */
	for(i = 0;i < M_inv->rows;i++){
		for(j = M->cols;j < M_inv->cols;j++){
			if(i + M->cols == j)
				*(matrix + i * M_inv->cols + j) = 1;
			else
				*(matrix + i * M_inv->cols + j) = 0;
		}
	}
	printf("并入单位矩阵得到增广矩阵：\n");
	matrixPrint(M_inv);
	putchar('\n');
	/* 矩阵消元,高斯-若尔当思想,假设矩阵中主元位置都不会为0 */
	//向下消元
	for(i = 0;i < M_inv->rows - 1;i++){//主元在第i行
		for(j = i + 1;j < M_inv->rows;j++){//对第j行进行消元
			int multiple = *(M_inv->matrix + j * M_inv->cols + i) / *(M_inv->matrix + i * M_inv->cols + i);
			for(k = 0;k < M_inv->cols;k++)
				*(M_inv->matrix + j * M_inv->cols + k) -= multiple * (*(M_inv->matrix + i * M_inv->cols + k));
		}
	}
	printf("向下消元：\n");
	matrixPrint(M_inv);
	putchar('\n');
	//向上消元
	for(i = M_inv->rows - 1;i > 0;i--){//主元在第i行
        for(j = i - 1;j >= 0;j--){//对第j行进行消元
			int multiple = *(M_inv->matrix + j * M_inv->cols + i) / *(M_inv->matrix + i * M_inv->cols + i);
			for(k = 0;k < M_inv->cols;k++)
				*(M_inv->matrix + j * M_inv->cols + k) -= multiple * (*(M_inv->matrix + i * M_inv->cols + k));
		}
	}
	printf("向上消元：\n");
	matrixPrint(M_inv);
	putchar('\n');
	for(i = 0;i < M_inv->rows - 1;i++){//将主元位置变为1，通过将该行同时除以某个数实现
		if(*(M->matrix + i * M_inv->cols + i) != 1){//如果不为1，则通过将该行除以某个数使得主元位置为1
			int divisor = *(M->matrix + i * M_inv->cols + i);
			for(j = 0;j < M_inv->cols;j++){
				*(M->matrix + i * M_inv->cols + j) /= divisor;
			}
			putchar('\n');
		}
	}
	/* 分割出矩阵的逆 */
	int* matrix_inv = (int *)malloc(sizeof(int) * M->cols * M->rows);
	for(i = 0;i < M_inv->rows;i++){
		for(j = M->cols;j < M_inv->cols;j++){
			*(matrix_inv + i * M->cols + j - M->cols) = *(M_inv->matrix + i * M_inv->cols + j);
		}
	}
	M_inv->cols = M->cols;
	free(M_inv->matrix);
	M_inv->matrix = matrix_inv;
	return M_inv;
}

int main(){
	int m[3][3] = {
		1,2,3,
		2,5,7,
		3,6,10,
	};
	struct Matrix *M = createMatrix(3,3,(int *)m);
	printf("矩阵A: \n");
	matrixPrint(M);
	putchar('\n');
	struct Matrix *M_inv = matrixInverse(M);
	printf("矩阵的逆：\n");
	matrixPrint(M_inv);
	return 0;
}

