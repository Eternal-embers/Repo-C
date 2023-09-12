/*
	Name:�˻����
	Copyright:�ӵ���
	Author:�ӵ���
	Date:08/27 17:50
	Description: �߾���+dfs
*/
#include<stdio.h>
#include<string.h>
#define LEN 45

int N,K;
int s[LEN],a[LEN],c[LEN],t[LEN],res[LEN];
int lastPos = 0;//��һ���˺�λ�õĺ�һ����������

void clear(int a[]){
	int i;
	for(i = 0;i < LEN;i++)
		a[i] = 0;
}

void print(int a[]){
	int i;
	for(i = LEN - 1;i >= 1;i--)
		if(a[i] != 0) break;
	while(i >= 0)
		putchar(a[i--] + '0');
	putchar('\n');
}

/* �߾��ȳ˸߾��� */
void mult(int a[],int b[],int c[]) {
	clear(c);
	int i,j;
	for(i = 0;i < LEN - 1;++i){//�����iλ
		for(j = 0;j <= i;++j)
			c[i] += a[j] * b[i - j];//���c[i]�е�iλ����
		if(c[i] >= 10){//��λ
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

//pos��ʾ���ó˺ŵĺ�һ������������k��¼�ѷ��ó˺ŵ�����,c�洢���ս����t�洢ÿ�ε���ʱ���
void dfs(int s[],int pos,int k){
	if(k == N + 2){
		int i,len1,len2,flag = 0;
		for(i = LEN;i > 0;i--)
			if(c[i] != 0) {
				len1 = i + 1;
				break;
			}
		for(i = LEN;i >= 0;i--)
			if(res[i] != 0) {
				len2 = i + 1;
				break;
			}
  		/* �ж��Ƿ���Ҫ���� */
		if(len1 > len2) flag = 1;//��Ҫ����
		else if(len1 == len2){
			for(i = len1;i >= 0;i--)
				if(c[i] > res[i]) {
					flag = 1;
					break;
				}
				else break;
		}
		if(flag){
			//������Ľ������ԭ�Ƚ��
			for(i = 0;i < LEN;i++)
				res[i] = c[i];
		}
		clear(c);
    		c[0] = 1;
		return;
	}
	else{
		print(a);
		print(c);
		print(res);
		putchar('\n');
		int i,j;
		/* ѡ��ų˺ŵ�λ�ã���pos��һλ��ʼѡ */
		for(i = pos + 1;i < N - K + k;i++){
			if(N + 2 - i > 0){
				int lastPos_t = lastPos;
				/* ���˴γ˺����ϴγ˺�֮���������a */
				int len = pos - lastPos;
				clear(a);
				for(j = 0;j <= len;j++)
					a[j] = s[lastPos + j];
				/* ��a����һ�εĽ�����,����������t */
				mult(a,c,t);
				/* ���µļ���������c */
				for(i = 0;i < LEN;i++)
			    	c[i] = t[i];
				dfs(s,i,k + 1);//�����ų˺�
				lastPos = lastPos_t;//�ָ���һ�����ϸ��˺ŵ�λ��
			}
		}
	}
}

int main(){
	int i;
	scanf("%d %d",&N,&K);
	char str[N + 1];
	scanf("%s",str);
	clear(s);
	for(i = 0;i < N;i++)
		s[N - i - 1] = str[i] - '0';
    clear(res);
    dfs(s,0,0);
    print(res);
	return 0;
}

