/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���

	Date:02/04/23 14:36
	Description:����ʽ������-����ʵ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN 1000//������Ķ���ʽ���������

/* ����ʽ�Ļ����ṹ�� */
struct poly{
	double coef;//ϵ��
	double index;//ָ��
	struct poly *next;
};
struct poly *result[100];//�洢���
int size = 0;//��¼��ǰ�洢�Ľ������
	
//dataΪһ����������ʽ�����ϵ����ָ���Ķ�ά����,����һά�������������0��Ϊϵ��������1��Ϊָ��
//length��ʾ����ʽ�е�����
//����һ�����ݴδӸߵ�������Ķ���ʽ
struct poly* createPoly(double (*data)[2],int length)
{
	/*����һ��ͷ���*/
	struct poly *head = (struct poly *)malloc(sizeof(struct poly));
	struct poly *first = (struct poly *)malloc(sizeof(struct poly));//firstָ������
	/* �������ʽ�ĵ�һ��*/
	head->next = first;
	first->coef = data[0][0];
	first->index = data[0][1];
	first->next = NULL;
	
	/* ������ʽ�е���������뵽������ */
	struct poly *p1,*p2,*pre;
	int i = 1;
	while(i < length)//��һ���Ѿ����룬����i = 1
	{
		/* ���ɽ��*/
		p1 = (struct poly*)malloc(sizeof(struct poly));//p1ָ��Ҫ����Ľ��
		p1->coef = data[i][0];
		p1->index = data[i][1];
		
		pre = head;//preʼ��ָ��p2��ǰһ�����
 		p2 = first;//p2���ڱ���
		//�Ӷ���ʽ�����ʼ�������ҵ����ʵ�λ�ò���
		while(p2 && p2->index > p1->index){
			pre = pre->next;
			p2 = p2->next;
		}//ֱ��p2��ָ��С�ڻ����Ҫ����Ľ���ָ��ʱ��ֹͣ����
		
		if(p2 == NULL){//��������������β��
			p1->next = NULL;
			pre->next = p1;
		}
		else {
			//����ݴ���ֱͬ�Ӻϲ�ͬ����
			if(p2->index == p1->index)
			{
				p2->coef += p1->coef;
				free(p1);
			}
			else//������뵽pre��p2֮��
			{
				pre->next = p1;
				p1->next = p2;
				if(pre == head) first = p1;//����²���Ľ���Ϊ���������first
			}
		}
		i++;
	}
	free(head);
	return first;//���������ַ
}

//coef_digitָ��ϵ�������С��λ��
//index_digitָ��ָ�������С��λ��
void showPoly(struct poly *P,int coef_digit,int index_digit){
	if(P){
		int cnt = 0;
		struct poly *node = P;
		while(node->next){
			if(node->coef != 0){
				printf("(%.*f)*[X^%.*f] + ",coef_digit,node->coef,index_digit,node->index);
				cnt++;
				if(cnt % 6 == 0) printf("\n\t\t");
			}
			node = node->next;
		}
		//���һ�����Ҫ���+�����Ե������
		printf("(%.*f)*[X^%.*f]",coef_digit,node->coef,index_digit,node->index);
	}
}

/* �������ʽf1��f2�ĳ˻� */
struct poly *multiply(struct poly *f1,struct poly *f2) {
	struct poly *head = (struct poly *)malloc(sizeof(struct poly));
	struct poly *res = NULL;//����ʽ������

	/* �������ʽf1��f2�ĳ˻� */
	struct poly *p1,*p2,*node,*pre,*pt;
	p1 = f1;//p1���ڱ���f1����ʽ�ĸ���
	while(p1){
		//printf("p1 %.0f[X^%.0f]\n",p1->coef,p1->index);//����
		p2 = f2;//p2���ڱ���f2����ʽ�ĸ���
		while(p2){
			//printf("%.0f[X^%.0f]*%.0f[X^%.0f]=%.0f[X^%.0f]\n",p1->coef,p1->index,p2->coef,p2->index,node->coef,node->index);//����
			/* ���ɴ洢ĳ������˽���Ľ�� */
			node = (struct poly *)malloc(sizeof(struct poly));
			node->coef = p1->coef * p2->coef;//ϵ�����
			node->index = p1->index + p2->index;//ָ�����
			
			/* ���뵽�洢����������У������ݴΰ��Ӹߵ������� */
			if(res == NULL) {//����洢�����������û�н��
				res = node;
				head->next = res;
				res->next = NULL;
				p2 = p2->next;
				continue;
			}
			pre = head;//preʼ��ָ��pt��ǰһ�����
 			pt = res;//pt���ڱ����洢���������
			//�Ӷ���ʽ�����ʼ�������ҵ����ʵ�λ�ò���
			while(pt && pt->index > node->index){
				pre = pre->next;
				pt = pt->next;
			}//ֱ��pt��ָ��С�ڻ����Ҫ����Ľ���ָ��ʱ��ֹͣ����
			if(pt == NULL){//��������������β��
				node->next = NULL;
				pre->next = node;
			}
			else {
				//����ݴ���ֱͬ�Ӻϲ�ͬ����
				if(pt->index == node->index)
				{
					pt->coef += node->coef;
					free(node);
				}
				else//������뵽pre��p2֮��
				{
					pre->next = node;
					node->next = pt;
					if(pre == head) res = node;//����²���Ľ���Ϊ���������res
				}
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	free(head);
	return res;
}

/* ����ʽ���ݼ��� */
struct poly *poly_pow(struct poly *f,int n){
	struct poly *res,*pre,*t;
	int i;
	res = f;
	pre = f;
	i = 1;
	while(i < n){
		res = multiply(pre,f);
		if(pre != f){
	 		while(pre){//�ͷż�����������õ�����
				t = pre->next;
				free(pre);
				pre = t;
	 		}
		}
		pre = res;
	  	i++;
	}
	return res;
}

void clear(struct poly *P){
	struct poly* t;
    while(P){
		t = P->next;
		free(P);
		P = t;
	}
}

void menu(){
	printf("\t\t_______________________________________________\n");
	printf("\t\t|                                             |\n");
	printf("\t\t|          ________________________           |\n");
	printf("\t\t|          |>>>>>����ʽ������<<<<<|           |\n");
	printf("\t\t|          �˵���                             |\n");
	printf("\t\t|          �˳�- - - - - - - - - - - 0        |\n");
	printf("\t\t|                                             |\n");
	printf("\t\t|          ��������ʽ�ĳ˷�����- - - 1        |\n");
	printf("\t\t|                                             |\n");
	printf("\t\t|          �������ʽ�ĳ˷�����- - - 2        |\n");
	printf("\t\t|                                             |\n");
	printf("\t\t|          ����ʽ���ݼ�������- - - - 3        |\n");
	printf("\t\t|                                             |\n");
	printf("\t\t|          �鿴������- - - - - - - 4        |\n");
	printf("\t\t|_____________________________________________|\n");
	printf("\n\t\t>>");
}

struct poly *input(){
	double data[LEN][2];
	struct poly *P;
	int i,len;
    printf("\t\t����ʽ������");
	scanf("%d",&len);//��������
	printf("\t\t      ϵ�� ָ��\n");
	for(i = 0;i < len;i++){
		printf("\t\t��%d�",i + 1);
		scanf("%lf%lf",&data[i][0],&data[i][1]);//�������ϵ����ָ��
	}
	P = createPoly(data,len);//��������ʽ
	printf("\t\t��������");
 	showPoly(P,1,1);//�˴����ڴ�ӡ����Ķ���ʽ�ľ��ȣ��ڶ��͵����������ֱ��ʾϵ����ָ����ȷ��С�����λ
 	printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - -\n");
	return P;
}

void depose_res(struct poly *res){
	int coef_digit,index_digit,flag;
	printf("\t\tϵ����С�����־�ȷ����λ��:");
	scanf("%d",&coef_digit);
	printf("\t\tָ����С�����־�ȷ����λ��:");
	scanf("%d",&index_digit);
	printf("\t\t������:");
   	showPoly(res,coef_digit,index_digit);
   	system("pause>NULL");
    printf("\n\t\t�Ƿ񱣴�ý����(��[1]/��[0])   >>");
    scanf("%d",&flag);
	if(flag == 1){
		result[size++] = res;
		printf("\t\t�������ɹ�!\n");
	}
	else {//�ͷ�res����Ŀռ�
		clear(res);
		printf("\t\t�ͷſռ�ɹ�!\n");
	}
	printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

int main(){
	printf("\n\n");
	int option;
	while(1){
		menu();
		scanf("%d",&option);
		if(option == 1){
            struct poly *poly1,*poly2,*res;
            /* ������������ʽ*/
            printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("\t\t>>>f1\n");
            poly1 = input();
            printf("\t\t>>>f2\n");
            poly2 = input();
			/* ����poly1��poly2�ĳ˻� */
			res = multiply(poly1,poly2);
			/* ������ */
			depose_res(res);
		}
		else if(option == 2){
			int i,num;
			do{
            	printf("\t\t���������ʽ������");
            	scanf("%d",&num);
            	if(num < 2) printf("\t\t����ʽ�����������1\n");
            }while(num < 2);
			struct poly *P[num],*res,*pre;
            for(i = 0;i < num;i++){
            	printf("\t\t>>>f%d\n",i + 1);
				P[i] = input();
			}
			/* ������ */
			res = P[0];
			pre = res;
			i = 1;
			while(i < num){
				res = multiply(res,P[i]);
				clear(P[i-1]);//�ͷ�ʹ����Ķ���ʽP[i]
				/*
				clear(pre);//�ͷ����õĶ���ʽ����
				pre = res;
				�˴���bug���ͷ�res�Ŀռ䵼�³��������Ҫ�Ľ�
				������ʱû���ҵ�����취�����Դ˴���������res�ռ�δ�ͷ�
				*/
				i++;
			}
			clear(P[i-1]);//�ͷ�ʹ����Ķ���ʽP[i]
			/* ������ */
   			depose_res(res);
		}
		else if(option == 3){
			int index;
			struct poly *P,*res;
            printf("\t\t���������ʽ�Ĵ��ݣ�");
            scanf("%d",&index);
            P = input();//�������ʽ
			res = poly_pow(P,index);//�������ʽ����
			/* ������ */
   			depose_res(res);
		}
		else if(option == 4) {
			int n,coef_digit,index_digit;
            printf("\t\t��ǰ���洢%d����������Ҫ�鿴ĳ�������������������\n",size);
            printf("\t\t�鿴ȫ����������0\n\t\t>>");
            scanf("%d",&n);
            if(n > 0 && n < size){
	 			printf("\t\tϵ����С�����־�ȷ����λ��:");
				scanf("%d",&coef_digit);
				printf("\t\tָ����С�����־�ȷ����λ��:");
				scanf("%d",&index_digit);
				printf("\t\t������:");
   				showPoly(result[n],coef_digit,index_digit);
			}
			else if(n == 0) {
				int i;
				printf("\t\tϵ����С�����־�ȷ����λ��:");
				scanf("%d",&coef_digit);
				printf("\t\tָ����С�����־�ȷ����λ��:");
				scanf("%d",&index_digit);
				printf("\t\t�洢�����\n");
				i = 0;
				while(i < size){
					printf("\t\t%d  ",i);
	 				showPoly(result[i],coef_digit,index_digit);
					printf("\n\n");
					i++;
				}
			}
			else printf("\t\t�������\n");
			system("pause>NULL");
			printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - -\n");
		}
		else if(option == 0){
			printf("\t\t��л����ʹ�ã�");
			return 0;
		}
		else {
			printf("\t\t�������");
			system("pause>NULL");
			system("cls");
		}
	}
	return 0;
}

