/*
	Name: �˻����������
	Copyright:�ӵ���
	Author:�ӵ���
	Date:08/28 12:05
	Description: dp + �߾���
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct BigInt{
	int len;
	int num[50];
}dp[50][50],sum[50][50],c;//dp[n][k]��ʾ���䳤��Ϊn���˺���Ϊkʱȡ�õ������

int N,K;
char s[50];

void print(struct BigInt *a){
	int i;
 	for(i = a->len;i >= 1;i--)
		putchar(a->num[i] + '0');
	putchar('\n');
}

/* �ж�a�Ƿ����b */
int max(struct BigInt *a,struct BigInt *b){
	if(a->len > b->len) return 1;
	else if(a->len < b->len) return 0;
	else{
		int i;
		for(i = a->len;i >= 1;--i){
			if(a->num[i] > b->num[i]) return 1;
			else if(a->num[i] < b->num[i]) return 0;
		}
		return 0;//�������
	}
}

void mult(struct BigInt *a,struct BigInt *b){
	memset(c.num,0,sizeof(c));//���c
	int i,j;
	for(i = 1;i < 50;++i){//�����iλ
		for(j = 1;j <= i;++j){
            c.num[i] += a->num[j] * b->num[i - j + 1];
		}
		if(c.num[i] >= 10){
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
		}
	}
	for(i = 49;i >= 1;--i)
		if(c.num[i] != 0) break;
	c.len = i;
}

int main(){
	scanf("%d %d",&N,&K);
	scanf("%s",s + 1);//������1��ʼ
	int i,j,n,k;

	for(i = 1;i <= N;i++){
		//dp[i][0]Ϊ�ַ���ǰi����ɵ���
		dp[i][0].len = i;
		for(j = 1;j <= i;j++)
			dp[i][0].num[i - j + 1] = s[j] - '0';//����Ϊi�����ų˺�
			
		//dp[i][j]��Ϊ0
		for(j = 1;j <= N;j++){
			memset(dp[i][j].num,0,sizeof(dp[i][j].num));
			dp[i][j].len = 0;
		}
	}
	
	for(i = 1;i <= N;i++){
		for(j = 1;j <= N;j++){
			memset(sum[i][j].num,0,sizeof(sum[i][j].num));
			for(k = i;k <= j;k++)//�����ִ��ӵ�i������j��ɵ����ַ���sum[i][j]
				sum[i][j].num[j - k + 1] = s[k] - '0';
			sum[i][j].len = j - i + 1;
		}
	}

	for(n = 1;n <= N;n++){//���䳤��
		for(k = 1;k < n;k++){//�˺�����
			for(i = k;i <= n;i++){//ѡ�����λ��
				mult(&dp[i][k - 1],&sum[i + 1][n]);//��������c��
				if(max(&c,&dp[n][k]))
					dp[n][k] = c;//���½��
			}
		}
	}
	print(&dp[N][K]);
	return 0;
}

