/*
	Name: ����Ĵ�ӡ
	Copyright:�ӵ���
	Author:�ӵ���
	Date:17/08/23 18:44
	Description:����Ĵ�ӡ
*/
#include<stdio.h>
#include<stdlib.h>
struct Matrix{
	int cols;//��
	int rows;//��
	int *matrix;//���������
};

char c[5][3] = {"��","��", "��", "��","��"};

/* ȡ�� */
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

/* ��ӡ���� */
void matrixPrint(struct Matrix *M){
	int x = M->cols;
	int y = M->rows;
	int *matrix = M->matrix;
	/* ��ȡ�����еľ���ֵ������ */
	int max = 0;
	int i,j;
	for(i = 0;i < y;i++){
		for(j = 0;j < x;j++)
			if(abs(*(matrix + x * i + j)) > max) max = abs(*(matrix + x * i + j));
	}
	int digit = 1;
	/* ���max��λ�� */
	while(max){
		max /= 10;
		digit++;
	}
	/* ������� */
	printf("%s ",c[0]);//��ӡ"��"
	for(j = 0;j < x;j++)
		printf("%*d  ",digit,*(matrix + j));//�����һ��
	printf("%s\n",c[1]);//��ӡ"��"

	for(i = 1;i < y - 1;i++){
		printf("%s ",c[4]);//��ӡ"��"
		for(j = 0;j < x;j++){
			printf("%*d  ",digit,*(matrix + x * i + j));//���2 ~ y - 1��
		}
		printf("%s\n",c[4]);//��ӡ"��"
	}
	
	printf("%s ",c[2]);//��ӡ"��"
	for(j = 0;j < x;j++)
		printf("%*d  ",digit,*(matrix + x * i + j));
	printf("%s\n",c[3]);//��ӡ"��"
}

/* ����ת�� */
struct Matrix *matrixTranspose(struct Matrix *M){
	int y = M->rows;
	int x = M->cols;
	int* matrix = M->matrix;
	int i,j;
	int *matrix_T = (int *)malloc(sizeof(int) * (x * y));
	struct Matrix *M_T = createMatrix(x,y,matrix_T);
	/* ת�� */
	for(i = 0;i < y;i++){
		for(j = 0;j < x;j++){
			*(matrix_T + y * j + i) = *(matrix + x * i + j);//����������н���
		}
	}
	return M_T;
}

/* ������Ԫ */
void matrixElimination(struct Matrix *M,int pivot,int row){//pivotΪ��Ԫ��rowΪ��Ҫ��Ԫ����
	/*
	    ��ӡ������㲽��
 		matrixPrint(M);
 		printf("\n");
 	*/
	if(pivot == M->rows) {
 	 	matrixPrint(M);
		/* �ش� */
		int i,j;
		int x[M->rows];
		for(i = 0;i < M->rows;i++)
			x[i] = 0;
		for(i = M->rows - 1;i >= 0;i--){//����i������
			x[i] = *(M->matrix + i * M->cols + M->cols - 1);
			for(j = 0;j < M->cols - 1;j++){
				if(j != i) x[i] -= *(M->matrix + i * M->cols + j) * x[j];
			}
			x[i] /= *(M->matrix + i * M->cols + i);//����ϵ��
		}
		for(i = 0;i < M->rows;i++)
			printf("x[%d] = %d\n",i + 1,x[i]);
		return;
	}
	else if(*(M->matrix + pivot * M->cols + pivot) == 0){//��Ԫλ��Ϊ0
		int i;
		for(i = pivot + 1;i < M->cols;i++){
			if(*(M->matrix + i * M->cols + pivot) != 0){
				//������
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
			printf("�˾����޷�������Ԫ!");
			return;
		}
		matrixElimination(M,pivot,row);
	}
	else if(row >= M->rows){//�л���һ����Ԫ
		matrixElimination(M,pivot + 1,pivot + 2);
	}
	else{
		if(*(M->matrix + row * M->rows + pivot) == 0){
   			matrixElimination(M,pivot,row + 1);//����(row,pivot)λ��Ϊ0,������Ԫ
		}
		else{//��Ԫ
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

