/*
	Name: ������
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 08/29 10:01
	Description: ����ɸ
*/
#include<stdio.h>
#include<math.h>
#include<memory.h>

int prime[4800] = {0};//����2147483647�¹�4791������

int main(){
	int a,b,res = 0;
	scanf("%d %d",&a,&b);

	/* �ҳ�sqrt(b)֮ǰ��ȫ������ */
	int cnt = 0;//��¼sqrt(2147483647)�ڵ�ȫ����������
	int i,j,t,n = 46340;
	for(i = 2;i <= n;i++){
		t = sqrt(i);
		for(j = 2;j <= t;j++)
			if(i % j == 0) break;
		if(j > t)
			prime[cnt++] = i;
	}

	if(a < 46340){
		t = b < 46340 ? b : 46340;
		for(i = a;i <= t;i++){
			for(j = 0;j < cnt;j++)
				if(i == prime[j]) {
					res++;
					break;
				}
		}
	}
	
	t = a > 46341 ? a : 46341;
	for(i = t;i <= b;i++){
		for(j = 0;j < cnt;j++)
			if(i % prime[j] == 0) break;
		if(j >= cnt) res++;
	}
	
	printf("%d",res);
	return 0;
}

