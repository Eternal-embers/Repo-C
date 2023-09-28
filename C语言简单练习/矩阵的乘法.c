/*
	Name: 矩阵的乘法
	Copyright:劣等生
	Author:劣等生
	Date: 08/18 18:04
	Description: 矩阵的乘法
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
	int digit = 1;
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

/* 公式法 */
struct Matrix *matrixMultiple1(struct Matrix *M1,struct Matrix *M2){
	int i,j,k;
	int *matrix = (int *)malloc(sizeof(int) * (M1->rows * M2->cols));
	int length = M1->rows * M2->cols;
	for(i = 0;i < length;i++)
        matrix[i] = 0;
	struct Matrix *M3 = createMatrix(M1->rows,M2->cols,matrix);
	for(i = 0;i < M3->rows;i++){
		for(j = 0;j < M3->cols;j++){
			for(k = 0;k < M1->cols;k++){
				*(M3->matrix + i * M3->cols + j) += *(M1->matrix + i * M1->cols + k) * (*(M2->matrix + k * M2->cols + j));
			}
		}
	}
	return M3;
}

/* 向量乘法 */
void vectorMultiple(struct Matrix *M1,int row,struct Matrix *M2,int col,struct Matrix *M3){//M1的第row行乘以M2的第col列
	int i;
	int k = M1->cols;
	for(i = 0;i < k;i++){
        *(M3->matrix + row * M3->cols + col) += *(M1->matrix + row * M1->cols + i) * (*(M2->matrix + i * M2->cols + col));
	}
}

/* 将M1的行向量与M2的列向量相乘 */
struct Matrix *matrixMultiple2(struct Matrix *M1,struct Matrix *M2){
	int i,j;
	int *matrix = (int *)malloc(sizeof(int) * (M1->rows * M2->cols));
	int length = M1->rows * M2->cols;
	for(i = 0;i < length;i++)
        matrix[i] = 0;
	struct Matrix *M3 = createMatrix(M1->rows,M2->cols,matrix);
	for(i = 0;i < M1->rows;i++){
		for(j = 0;j < M2->cols;j++){
   			vectorMultiple(M1,i,M2,j,M3);
		}
	}
	return M3;
}

int main(){
	int m1[2][2] = {
		1,0,
		-4,1
	};
	int m2[2][2] = {
		2,1,
		8,7
	};
	int m4[2][3] = {
		2,-1,
		3,2,
		4,1
	};
	int m5[2][2] = {
		1,6,
		-1,2
	};
	int m7[4][4] = {
		1,0,1,-2,
		0,1,0,1,
		-1,2,-1,0,
		0,-1,0,-1
	};
	int m8[4][4] = {
		1,0,1,0,
		0,-1,0,1,
		1,0,1,0,
		0,1,0,-1
	};
	int a[3][3] = {
		1,2,3,
		2,5,7,
		3,6,10
	};
	int a_inv[3][3] = {
		8,-2,-1,
		1,1,-1,
		-3,0,1
	};
	struct Matrix *M1 = createMatrix(2,2,(int *)m1);
	struct Matrix *M2 = createMatrix(2,2,(int *)m2);
	struct Matrix *M3 = matrixMultiple1(M1,M2);
	printf("公式法：\n");
	matrixPrint(M1);
	matrixPrint(M2);
	matrixPrint(M3);
	printf("\n");
	struct Matrix *M4 = createMatrix(2,3,(int *)m4);
	struct Matrix *M5 = createMatrix(2,2,(int *)m5);
	struct Matrix *M6 = matrixMultiple2(M4,M5);
	printf("向量法：\n");
	matrixPrint(M4);
	matrixPrint(M5);
	matrixPrint(M6);
	struct Matrix *M7 = createMatrix(4,4,(int *)m7);
	struct Matrix *M8 = createMatrix(4,4,(int *)m8);
	struct Matrix *M9 = matrixMultiple1(M7,M8);
	printf("分块乘法：\n");
	matrixPrint(M7);
	matrixPrint(M8);
	matrixPrint(M9);
	struct Matrix *A = createMatrix(3,3,(int *)a);
	struct Matrix *A_inv = createMatrix(3,3,(int *)a_inv);
	struct Matrix *I = matrixMultiple1(A,A_inv);
	printf("A * A_inv = \n");
 	matrixPrint(I);
	return 0;
}

