/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/30 16:35
	Description: Լɪ��
*/
#include<stdio.h>
#include<stdbool.h>

int a[10004];
bool b[10004];
int cnt = 0;
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int i = k > n ? k % n : k,j = 1;
	while(cnt != n){
		if(!b[i]){ //���û�г���
			//����j
			if(j == m) {
				printf("%d\n",i);
				b[i] = true;///��¼��i���˳���
				cnt++;//��¼����һ��
				j = 0;
			}
			j++;
		}
		i = i % n;
		i++;//��һ����
	}
	return 0;
}

