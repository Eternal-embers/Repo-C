/*
	Name:��������Ϸ
	Copyright:�ӵ���
	Author:�ӵ���
	Date:2023/06/23 13:14
	Description: �򵥵��߼��ж�
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define line; printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
#define pause; system("pause>NULL");
_Bool input(){
	int option;
	while(1){
		printf("\t\t���ж�����ѡ�����Ƿ�������(1/0)��");
		scanf("%d",&option);
		if(option == 0 || option == 1) break;
		else printf("\t\t��������������ѡ�����������ĸ�����������1����������0��\n");
	}
	return option;
}

int main(){
	int x[9];
	int i,option;
	srand(time(NULL));//���ݵ�ǰʱ���ȡ�����������
	/* ����7������� */
	for(i = 1;i <= 7 ;i++)
		x[i] = rand() % N + 1;//����������ķ�Χ��1~N
	/* ��ʼ��Ϸ */
	printf("\n\n\t\t\t\t>>>��������Ϸ<<<\n\n");
	printf("\t\t���������չʾ���߸�����ѡ��һ�������������\n\t\t");
	printf("%d %d %d %d %d %d %d",x[3],x[7],x[1],x[6],x[4],x[2],x[5]);
	pause;
	putchar('\n');
	printf("\t\t�ã����������������߸�����ÿ�������ʾ�ĸ���������Ҫ�ж�����ѡ�����Ƿ������У������������1����������0��");
	pause;
	putchar('\n');
	
	/* ��һ���ж� */
	line;
	printf("\t\t%d %d %d %d\n",x[3],x[2],x[4],x[1]);//ȡx1��x2��x3��x4
	option = input();


	if(option == 1){
		/* �ڶ����ж� */
  		line;
	   	printf("\t\t%d %d %d %d\n",x[2],x[6],x[1],x[7]);//ȡx1��x2
	 	option = input();
	 	
	 	/* �������ж�*/
		if(option == 1){
   			line;
			printf("\t\t%d %d %d %d\n",x[5],x[4],x[7],x[1]);//ȡx1
			option = input();
			/* �жϽ�� */
			if(option == 1) printf("\t\t����ѡ������%d\n",x[1]);//x1
			else printf("\t\t����ѡ������%d\n",x[2]);//x2
		}
		else{
			line;
			printf("\t\t%d %d %d %d\n",x[7],x[2],x[3],x[6]);//ȡx3
   			option = input();
   			/* �жϽ�� */
			if(option == 1) printf("\t\t����ѡ������%d\n",x[3]);//x3
			else printf("\t\t����ѡ������%d\n",x[4]);//x4
		}
	}
	else{
		/* �ڶ����ж� */
		line;
	   	printf("\t\t%d %d %d %d\n",x[6],x[5],x[4],x[2]);//ȡx5��x6
	 	option = input();

	 	/* �������ж�*/
		if(option == 1){
			line;
			printf("\t\t%d %d %d %d\n",x[1],x[5],x[3],x[2]);//ȡx5
			option = input();
			/* �жϽ�� */
			if(option == 1) printf("\t\t����ѡ������%d\n",x[5]);//x5
			else printf("\t\t����ѡ������%d\n",x[6]);//x6
		}
		else{
		   	line;
			printf("\t\t%d %d %d %d\n",x[2],x[4],x[3],x[5]);//ȡx7,�Ѿ��������
   			option = input();
   			/* �жϽ�� */
            printf("\t\t����ѡ������%d\n",x[7]);
		}
	}
	line;
	pause;
	printf("\t\t��Ϸ������");
	return 0;
}

