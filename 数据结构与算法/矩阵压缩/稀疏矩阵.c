/*
	Name: 稀疏矩阵
	Copyright:劣等生
	Author:劣等生
	Date: 10/11 19:34
	Description: 用三元组表实现稀疏矩阵
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct sparseMatrix{
	int i,j;//在二维数组中的索引(i,j)
	int v;//值
}Spa;//三元组表示法(i,j,v)

void showMatrix(Spa *matrix){
	int i;
	for(i = 0;i <= matrix[0].v;i++){
		printf("(%d,%d,%d) ",matrix[i].i,matrix[i].j,matrix[i].v);
	}
	putchar('\n');
}

Spa *compressSparseMatrix(int *matrix,int rows,int cols){
	int i,j,k,len = 0;
	for(i = 0;i < rows;i++){
		for(j = 0;j < cols;j++){
			if(*(matrix + i * cols + j) != 0)  len++;
		}
	}
	Spa *spa = (Spa *)malloc(sizeof(Spa) * (len + 1));
	/* 第一个三元组放(rows,cols,len) */
	spa[0].i = rows;
	spa[0].j = cols;
	spa[0].v = len;
	k = 1;
	for(i = 0;i < rows;i++){
		for(j = 0;j < cols;j++){
			if(*(matrix + i * cols + j) != 0)  {
				spa[k].i = i;
				spa[k].j = j;
				spa[k].v = *(matrix + i * cols + j);
				k++;
			}
		}
	}
	return spa;
}

/* 时间复杂度O(rows * length) */
Spa* transpose(Spa *spa){
	Spa *tran = (Spa *)malloc(sizeof(Spa) * (spa[0].v + 1));
	tran[0].i = spa[0].i;
	tran[0].j = spa[0].j;
	tran[0].v = spa[0].v;
	int i,j,k = 1;
	for(i = 0;i <= spa[0].i;i++){
		for(j = 0;j <= spa[0].v;j++){
			if(spa[j].j == i) {
				tran[k].i = spa[j].j;
				tran[k].j = spa[j].i;
				tran[k].v = spa[j].v;
				k++;
			}
		}
	}
	return tran;
}

/* 转置的优化算法，时间复杂度O(cols + length) */
Spa *tranpose_optimize(Spa *spa){
	Spa *tran = (Spa *)malloc(sizeof(Spa) * (spa[0].v + 1));//转置矩阵
	int r[spa[0].j];//转置矩阵中各行的非零元数目
	int pos[spa[0].j];//转置矩阵中各行非零元的起始索引
	int i;
	memset(r,0,sizeof(r));
	for(i = 1;i < spa[0].v;i++)
		r[spa[i].j]++;//记录转置矩阵中各行非零元数目

	pos[0] = 1;//第一行第一个非零元的索引
	for(i = 1;i < spa[0].j;i++){
		pos[i] = pos[i - 1] + r[i - 1];//第i行的第一个非零元的索引
	}
	
	
	/* 转置矩阵的信息& (rows,cols,length) */
	tran[0].i = spa[0].j;
	tran[0].j = spa[0].i;
	tran[0].v = spa[0].v;
	
	/*
		代码中的spa 是 A 的三元组表
		下面代码中通过三元组表中非零元的列数 spa[i].j 在pos数组找到自己在 A^T 的三元组表 tran 的索引，
		然后通过更新pos数组为该行下一个非零元设置索引。
	*/
	for(i = 1;i <= spa[0].v;i++){
		int index = pos[spa[i].j];//根据行数确定索引
		tran[index].i = spa[i].j;
		tran[index].j = spa[i].i;
		tran[index].v = spa[i].v;
		pos[spa[i].j]++;//调整至该行的下一个非零元的索引
	}
	return tran;
}

int main(){
	int matrix[6][7] = {
		0, 1, 0, 0,-1, 0, 0,
		0, 0, 0, 3, 0, 0, 0,
		2, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 4, 0, 0, 0,
		0, 0, 6, 0, 0, 5, 0,
		0,-2, 0, 0, 0, 0, 8
	};
 	Spa *spa = compressSparseMatrix((int *)matrix,6,7);
	printf("稀疏矩阵压缩：\n");
  	showMatrix(spa);
  	Spa *tran = transpose(spa);
  	printf("转置稀疏矩阵：\n");
  	showMatrix(tran);
  	Spa *tran_optimize = tranpose_optimize(spa);
  	printf("转置稀疏矩阵的优化：\n");
   	showMatrix(tran_optimize);
	return 0;
}

