/*
	Name:�������
	Copyright:�ӵ���
	Author:�ӵ���
	Date:08/18 23:46
	Description:�������
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
	int digit = 2;
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

/* �������棬ֻ�е�λ��������� */
struct Matrix *matrixInverse(struct Matrix *M){
	int *matrix = (int *)malloc(sizeof(int) * (M->rows * M->cols * 2));
	struct Matrix *M_inv = createMatrix(M->rows,M->cols * 2,matrix);
	int i,j,k;
	/* ����λ������M�õ�������� */
	for(i = 0;i < M_inv->rows;i++){
        for(j = 0;j < M->cols;j++){
        	*(matrix + i * M_inv->cols + j) = *(M->matrix + i * M->cols + j);
		}
	}
	/* ������������Ұ벿��Ϊ��λ���� */
	for(i = 0;i < M_inv->rows;i++){
		for(j = M->cols;j < M_inv->cols;j++){
			if(i + M->cols == j)
				*(matrix + i * M_inv->cols + j) = 1;
			else
				*(matrix + i * M_inv->cols + j) = 0;
		}
	}
	printf("���뵥λ����õ��������\n");
	matrixPrint(M_inv);
	putchar('\n');
	/* ������Ԫ,��˹-������˼��,�����������Ԫλ�ö�����Ϊ0 */
	//������Ԫ
	for(i = 0;i < M_inv->rows - 1;i++){//��Ԫ�ڵ�i��
		for(j = i + 1;j < M_inv->rows;j++){//�Ե�j�н�����Ԫ
			int multiple = *(M_inv->matrix + j * M_inv->cols + i) / *(M_inv->matrix + i * M_inv->cols + i);
			for(k = 0;k < M_inv->cols;k++)
				*(M_inv->matrix + j * M_inv->cols + k) -= multiple * (*(M_inv->matrix + i * M_inv->cols + k));
		}
	}
	printf("������Ԫ��\n");
	matrixPrint(M_inv);
	putchar('\n');
	//������Ԫ
	for(i = M_inv->rows - 1;i > 0;i--){//��Ԫ�ڵ�i��
        for(j = i - 1;j >= 0;j--){//�Ե�j�н�����Ԫ
			int multiple = *(M_inv->matrix + j * M_inv->cols + i) / *(M_inv->matrix + i * M_inv->cols + i);
			for(k = 0;k < M_inv->cols;k++)
				*(M_inv->matrix + j * M_inv->cols + k) -= multiple * (*(M_inv->matrix + i * M_inv->cols + k));
		}
	}
	printf("������Ԫ��\n");
	matrixPrint(M_inv);
	putchar('\n');
	for(i = 0;i < M_inv->rows - 1;i++){//����Ԫλ�ñ�Ϊ1��ͨ��������ͬʱ����ĳ����ʵ��
		if(*(M->matrix + i * M_inv->cols + i) != 1){//�����Ϊ1����ͨ�������г���ĳ����ʹ����Ԫλ��Ϊ1
			int divisor = *(M->matrix + i * M_inv->cols + i);
			for(j = 0;j < M_inv->cols;j++){
				*(M->matrix + i * M_inv->cols + j) /= divisor;
			}
			putchar('\n');
		}
	}
	/* �ָ��������� */
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
	printf("����A: \n");
	matrixPrint(M);
	putchar('\n');
	struct Matrix *M_inv = matrixInverse(M);
	printf("������棺\n");
	matrixPrint(M_inv);
	return 0;
}

