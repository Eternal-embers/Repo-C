/*
	Name: 矩阵的打印
	Copyright:劣等生
	Author:劣等生
	Date:17/08/23 18:44
	Description:矩阵的打印
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

/* 矩阵转置 */
struct Matrix *matrixTranspose(struct Matrix *M){
	int y = M->rows;
	int x = M->cols;
	int* matrix = M->matrix;
	int i,j;
	int *matrix_T = (int *)malloc(sizeof(int) * (x * y));
	struct Matrix *M_T = createMatrix(x,y,matrix_T);
	/* 转置 */
	for(i = 0;i < y;i++){
		for(j = 0;j < x;j++){
			*(matrix_T + y * j + i) = *(matrix + x * i + j);//将矩阵的行列交换
		}
	}
	return M_T;
}

/* 矩阵消元 */
void matrixElimination(struct Matrix *M,int pivot,int row){//pivot为主元，row为需要消元的行
	/*
	    打印具体计算步骤
 		matrixPrint(M);
 		printf("\n");
 	*/
	if(pivot == M->rows) {
 	 	matrixPrint(M);
		/* 回代 */
		int i,j;
		int x[M->rows];
		for(i = 0;i < M->rows;i++)
			x[i] = 0;
		for(i = M->rows - 1;i >= 0;i--){//求解第i个参数
			x[i] = *(M->matrix + i * M->cols + M->cols - 1);
			for(j = 0;j < M->cols - 1;j++){
				if(j != i) x[i] -= *(M->matrix + i * M->cols + j) * x[j];
			}
			x[i] /= *(M->matrix + i * M->cols + i);//除以系数
		}
		for(i = 0;i < M->rows;i++)
			printf("x[%d] = %d\n",i + 1,x[i]);
		return;
	}
	else if(*(M->matrix + pivot * M->cols + pivot) == 0){//主元位置为0
		int i;
		for(i = pivot + 1;i < M->cols;i++){
			if(*(M->matrix + i * M->cols + pivot) != 0){
				//交换行
				int j,t;
				for(j = 0;j < M->cols;j++){
					t = *(M->matrix + i * M->cols + j);
					*(M->matrix + i * M->cols + j) = *(M->matrix + pivot * M->cols + j);
					*(M->matrix + pivot * M->cols + j) = t;
				}
				break;
			}
		}
		if(i >= M->rows){
			printf("此矩阵无法进行消元!");
			return;
		}
		matrixElimination(M,pivot,row);
	}
	else if(row >= M->rows){//切换下一个主元
		matrixElimination(M,pivot + 1,pivot + 2);
	}
	else{
		if(*(M->matrix + row * M->rows + pivot) == 0){
   			matrixElimination(M,pivot,row + 1);//矩阵(row,pivot)位置为0,无需消元
		}
		else{//消元
			int i;
			int multiple = *(M->matrix + row * M->cols + pivot) / *(M->matrix + pivot * M->cols + pivot);
			for(i = pivot;i < M->cols;i++)
				*(M->matrix + row * M->cols + i) -= *(M->matrix + pivot * M->cols + i) * multiple;
			matrixElimination(M,pivot,row + 1);
		}
	}
}


int main(){
	int a[3][4] = {
		1,2,1,2,
		3,8,1,12,
		0,4,1,2,
	};
	struct Matrix *M = createMatrix(3,4,(int *)a);
	matrixPrint(M);
	printf("\n");
	struct Matrix *M_T = matrixTranspose(M);
	matrixPrint(M_T);
	printf("\n");
 	matrixElimination(M,0,1);
	return 0;
}

