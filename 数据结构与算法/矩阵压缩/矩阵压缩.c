 /*
	Name: 矩阵压缩
	Copyright:劣等生
	Author:劣等生
	Date: 10/11 20:47
	Description: 矩阵压缩的实现，对称矩阵、三角矩阵、多对角矩阵
*/
#include<stdio.h>
#include<stdlib.h>

void showMatrix(int *matrix,int n){
	int i;
	for(i = 0;i < n;i++){
		printf("%d ",matrix[i]);
	}
	putchar('\n');
}

/*
	对称矩阵,索引从0开始
	if(i >= j) k = i(i + 1) / 2 + j
	if(i < j)  k = j(j + 1) / 2 + i
 */
int *compressSymMatrix(int *matrix,int n){
	int size = n * (n + 1) /2;
	int *sym = (int *)malloc(sizeof(int) * size);//压缩n阶对称方阵需要n*(n+1)/2个空间
	int i,j,k;
	for(i = 0;i < n;i++){
		for(j = 0;j <= i;j++){
			k = i * (i + 1) / 2 + j;
			sym[k] = *(matrix + i * n + j);//sym[k] = matrix[i,j]
		}
	}
	printf("压缩对称矩阵：");
 	showMatrix(sym,size);
 	return sym;
}

/*
	上三角矩阵,索引从0开始
	if(i <= j) k = i * (2 * n - i + 1) / 2 + j - i
	if( i > j) k = n * (n + 1) / 2
 */
int *compressUpTriMatrix(int *matrix,int n){
	int size = n * (n + 1) / 2 + 1;
	int *upTri = (int *)malloc(sizeof(int) * size);//压缩n阶上三角方阵需要n*(n+1)/2 + 1个空间
	int i,j,k;
	for(i = 0;i < n;i++){
		for(j = i;j < n;j++){
			k = i * (2 * n - i + 1) / 2 + j - i;
			upTri[k] = *(matrix + i * n + j);//upTri[k] = matrix[i,j]
		}
	}
	upTri[size - 1] = 0;
	printf("压缩上三角矩阵：");
	showMatrix(upTri,size);
	return upTri;
}

/*
	下三角矩阵,索引从0开始
	if(i >= j) k = i * (i + 1) / 2 + j
	if( i > j) k = n * (n + 1) / 2
 */
int *compressLowTriMatrix(int *matrix,int n){
	int size = n * (n + 1) / 2 + 1;
	int *lowTri = (int *)malloc(sizeof(int) * size);//压缩n阶下三角方阵需要n*(n+1)/2 + 1个空间
	int i,j,k;
	for(i = 0;i < n;i++){
		for(j = 0;j <= i;j++){
			k = i * (i + 1) / 2 + j;
			lowTri[k] = *(matrix + i * n + j);//lowTri[k] = matrix[i,j]
		}
	}
	lowTri[size - 1] = 0;
	printf("压缩下三角矩阵：");
	showMatrix(lowTri,size);
	return lowTri;
}

/*
	压缩多对角矩阵，索引从0开始
	三对角矩阵的压缩：
	k = 2 * i + j
 */
 int *compressPolydiagMatrix(int *matrix,int n){
	int size = 3 * n;
	int *polydiag = (int *)malloc(sizeof(int) * size);//压缩n阶三对角方阵需要3 * n个空间
	int i,j,k;
	//矩阵的第一行
	polydiag[0] = *(matrix);
	polydiag[1] = *(matrix + 1);
	//矩阵的最后一行
	polydiag[size - 4] = *(matrix + (n-1) * n + n - 2);
	polydiag[size - 3] = *(matrix + (n-1) * n + n - 1);
	for(i = 1;i < n - 1;i++){
		for(j = i - 1;j <= i + 1;j++){
			k = 2 * i + j;
			polydiag[k] = *(matrix + i * n + j);//polydiag[k] = matrix[i,j]
		}
	}
	polydiag[size - 2] = 0;//左下角全部为0
	polydiag[size - 1] = 0;//右下角全部为0
	printf("压缩3对角矩阵：");
	showMatrix(polydiag,size);
	return polydiag;
 }

int main(){
	int sym[6][6] = {
		 1, 2, 4, 7,11,16,
		 2, 3, 5, 8,12,17,
		 4, 5, 6, 9,13,18,
		 7, 8, 9,10,14,19,
		11,12,13,14,15,20,
		16,17,18,19,20,21
	};
	compressSymMatrix((int *)sym,6);
	int upTri[6][6] = {
		 1, 2, 3, 4, 5, 6,
		 0, 7, 8, 9,10,11,
		 0, 0,12,13,14,15,
		 0, 0, 0,16,17,18,
		 0, 0, 0, 0,19,20,
		 0, 0, 0, 0, 0,21
	};
	compressUpTriMatrix((int *)upTri,6);
	int lowTri[6][6] = {
		 1, 0, 0, 0, 0, 0,
		 2, 3, 0, 0, 0, 0,
		 4, 5, 6, 0, 0, 0,
		 7, 8, 9,10, 0, 0,
		11,12,13,14,15, 0,
		16,17,18,19,20,21
	};
 	compressLowTriMatrix((int *)lowTri,6);
 	int polydiag[6][6] = {
		 1, 2, 0, 0, 0, 0,
		 3, 4, 5, 0, 0, 0,
		 0, 6, 7, 8, 0, 0,
		 0, 0, 9,10,11, 0,
		 0, 0, 0,12,13,14,
		 0, 0, 0, 0,15,16
	};
 	compressPolydiagMatrix((int *)polydiag,6);
	return 0;
}

