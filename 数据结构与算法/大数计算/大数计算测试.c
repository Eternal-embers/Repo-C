/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>
#include<string.h>
#include<memory.h>
#define LEN 1000000

char s1[LEN],s2[LEN];

void bigNumberAddition(char* x1,char* x2){
	int i,j;
	/* ��ȡx1��x2λ�� */
	int len1 = strlen(x1);
	int len2 = strlen(x2);
	
	/* ȷ����������� */
	_Bool flag1 = 1,flag2 = 1,flag = 1;//����x1��x2��x1+x2���Ϊ��
	if(x1[0] == '-') {
		flag1 = 0;//��¼������Ϣ
		for(i = 0;i < len1;i++)
			x1[i] = x1[i + 1];
		len1--;
	}//��ǰŲλ
	if(x2[0] == '-') {
		flag2 = 0;//��¼������Ϣ
		for(i = 0;i < len2;i++)
			x2[i] = x2[i + 1];
		len2--;
	}//��ǰŲλ
	
    /* ������ */
	if(flag1 == 0 && flag2 == 1) flag = 0;//���������������Ϊ��
	else if( (flag1 == 1 && flag2 == 1) && (len1 < len2 || len1 == len2 && x1[0] < x2[0]) ){
		flag = 0; //С��������ȥһ��������������Ϊ��
	}
	else if( (flag1 == 0 && flag2 == 0) && (len1 > len2 || len1 == len2 && x1[0] > x2[0]) ){
		flag = 0;//С�ĸ�����ȥһ����ĸ��������Ϊ��
	}

	/* �������ַ���ת��Ϊ���� */
	int n1[len1],n2[len2];
	//�����ִӵ�λ����λ����,�����λ
	for(i = 0;i < len1;i++)
		n1[len1 - i - 1] = x1[i] - '0';
	for(i = 0;i < len2;i++)
		n2[len2 - i - 1] = x2[i] - '0';

	/*������*/
	int len = len1 > len2 ? len1 + 1 : len2 + 1;
	int res[len];
	memset(res,0,sizeof(res));
	if(flag1 + flag2 == 1){//���x1��x2���
		for(i = 0;i < len1;i++){
			if(i < len1 && i < len2) {
				res[i] = n1[i] - n2[i];
				if(res[i] < 0) res[i] = -res[i];
			}
				else if(i < len1) res[i] = n1[i];
					else res[i] = n2[i];
		}
	}
	else{//���x1��x2ͬ��
		for(i = 0;i < len1;i++){
			if(i < len1 && i < len2) res[i] = n1[i] + n2[i];
				else if(i < len1) res[i] = n1[i];
					else res[i] = n2[i];
		}
	}

	/*��λ*/
	for(i = 0;i < len;i++){
		if(res[i] >= 10){
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	/*ȷ������λ��*/
       for(i = len - 1;i >= 0;i--){
		if(res[i] > 0){
			len = i + 1;
			break;
		}
	}
	if(i < 0) len = 0;
	int count = len;
	
	/*������*/
	if(len == 0) {
		putchar('0');
		return;
	}
	if(flag == 0) printf("-");
	i = len - 1;
	while(i > 0){
		printf("%d",res[i]);
		count--;
		if(count % 3 == 0) putchar(',');
		i--;
	}
	printf("%d",res[0]);//���һλ����û�ж��ţ��������
}
int main(){
	printf("x1 = ");
	scanf("%s",s1);
	printf("x2 = ");
	scanf("%s",s2);
	printf("(%s) + (%s) = ",s1,s2);
	bigNumberAddition(s1,s2);
	system("pause>NULL");
	return 0;
}
