/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 08/31 15:37
	Description: N�ʺ�����
*/
#include<stdio.h>

int n;
int sum = 0;
int a[20] = {0};//a[x] = y��ʾ��x�еĵ�y��λ�÷��ûʺ�

int abs(int num){
	return num > 0 ? num : -num;
}

/* �ж�(x,y)λ���Ƿ���Է� */
_Bool place(int x,int y){
	int i;
	for(i = 0;i < x;i++)
		if(abs(x - i) == abs(y - a[i]) || y == a[i]) return 0;
	return 1;
}

void backTrace(int x){
	if(x == n)
		sum++;
	else{
		int y;
		for(y = 0;y < n;y++){
			a[x] = y;//��(x,y)λ�÷Żʺ�
			if(place(x,y)) backTrace(x + 1);//����ܷžͼ�������һ��
		}
	}
}

int main(){
	scanf("%d",&n);
	backTrace(0);
	printf("%d",sum);
	return 0;
}

