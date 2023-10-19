/*
	Name: ϡ�����
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 10/11 19:34
	Description: ����Ԫ���ʵ��ϡ�����
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct sparseMatrix{
	int i,j;//�ڶ�ά�����е�����(i,j)
	int v;//ֵ
}Spa;//��Ԫ���ʾ��(i,j,v)

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
	/* ��һ����Ԫ���(rows,cols,len) */
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

/* ʱ�临�Ӷ�O(rows * length) */
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

/* ת�õ��Ż��㷨��ʱ�临�Ӷ�O(cols + length) */
Spa *tranpose_optimize(Spa *spa){
	Spa *tran = (Spa *)malloc(sizeof(Spa) * (spa[0].v + 1));//ת�þ���
	int r[spa[0].j];//ת�þ����и��еķ���Ԫ��Ŀ
	int pos[spa[0].j];//ת�þ����и��з���Ԫ����ʼ����
	int i;
	memset(r,0,sizeof(r));
	for(i = 1;i < spa[0].v;i++)
		r[spa[i].j]++;//��¼ת�þ����и��з���Ԫ��Ŀ

	pos[0] = 1;//��һ�е�һ������Ԫ������
	for(i = 1;i < spa[0].j;i++){
		pos[i] = pos[i - 1] + r[i - 1];//��i�еĵ�һ������Ԫ������
	}
	
	
	/* ת�þ������Ϣ& (rows,cols,length) */
	tran[0].i = spa[0].j;
	tran[0].j = spa[0].i;
	tran[0].v = spa[0].v;
	
	/*
		�����е�spa �� A ����Ԫ���
		���������ͨ����Ԫ����з���Ԫ������ spa[i].j ��pos�����ҵ��Լ��� A^T ����Ԫ��� tran ��������
		Ȼ��ͨ������pos����Ϊ������һ������Ԫ����������
	*/
	for(i = 1;i <= spa[0].v;i++){
		int index = pos[spa[i].j];//��������ȷ������
		tran[index].i = spa[i].j;
		tran[index].j = spa[i].i;
		tran[index].v = spa[i].v;
		pos[spa[i].j]++;//���������е���һ������Ԫ������
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
	printf("ϡ�����ѹ����\n");
  	showMatrix(spa);
  	Spa *tran = transpose(spa);
  	printf("ת��ϡ�����\n");
  	showMatrix(tran);
  	Spa *tran_optimize = tranpose_optimize(spa);
  	printf("ת��ϡ�������Ż���\n");
   	showMatrix(tran_optimize);
	return 0;
}

