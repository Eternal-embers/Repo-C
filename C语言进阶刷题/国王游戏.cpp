/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:08/02 10:34
	Description: ������Ϸ
*/
#include<stdio.h>
#include<stdlib.h>

/* ���´��벻��ȷ������д */
struct uv{
	int a;//�����ϵ���
	int b;//�����ϵ���
};

struct uv k;//����
struct uv g[10004];//��

int max(int a,int b){
	return a > b ? a : b;
}

/* ��С�������� */
int compare(const void *p1,const void *p2){
	struct uv *pt1 = (struct uv *)p1;
	struct uv *pt2 = (struct uv *)p2;
	int w1 = max(pt2->b,pt1->a * pt1->b);
	int w2 = max(pt1->b,pt2->a * pt2->b);
	return w1 - w2;
}

int main(){
	int n;
	scanf("%d",&n);
	int i;
	scanf("%d %d",&k.a,&k.b);
	for(i = 0;i < n;i++){
		scanf("%d %d",&g[i].a,&g[i].b);
	}
	qsort(g,n,sizeof(struct uv),&compare);
	printf("�����\n");
	for(i = 0;i < n;i++){
		printf("%d %d\n",g[i].a,g[i].b);
	}
	int res = k.a;
	for(i = 0;i < n;i++)
		res *= g[i].a;
	res /= g[n - 1].b;
	printf("%d",res);
	return 0;
}

