/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 08/02 12:06
	Description: ��ˮ����
*/
#include<stdio.h>

int w[10004];//��ˮ����w[i]��ʾ��i��ͬѧ��Ҫ��w[i]��ˮ
int u[10004];//ˮ��ͷ��u[i]��ʾ��i��ˮ��ͷ��Ҫ��u[i]��ˮ
int cnt = 0;//��¼����ˮ������

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i = 0;i < n;i++)
		scanf("%d",&w[i]);
	int k = m < n ? m : n;//k��ʾ���ڽ�ˮ��ˮ��ͷ����
	int next = k;//��һ�����Ŷӵ��˵ı��
	int t = 0;//��ʱ
	/* 1~k�ŵ�ͬѧȥ��ˮ��1~k��ˮ��ͷ�ֱ����w[0]...w[k-1]�Ľ�ˮ�� */
	for(i = 0;i < k;i++)
		u[i] = w[i];
	while(cnt < n){
		/* ��һ����ˮ��ͷ��һ���� */
        for(i = 0;i < m;i++){
			u[i]--;//��ˮһ��
			if(u[i] == 0){
				cnt++;//���������1
				if(next < n)
					u[i] = w[next++];//���ճ����ĵ�i-1��ˮ��ͷ����������һ���Ŷ�ͬѧ�Ľ�ˮ��
				else u[i] = -1;//��i-1��ˮ��ͷ���ٽ�ˮ
			}
		}
		t++;//��ʱ��1
	}
	printf("%d",t);
	return 0;
}

