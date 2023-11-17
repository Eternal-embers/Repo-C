#include<stdio.h>
#include<stdlib.h>
#define NUM 40
void fillarray(double ar[],int n);
void showarray(const double ar[],int n);
int mycomp(const void *p1,const void *p2);
int main(){
	int arr[20];
	int i;
	printf("qsort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));\n");
	printf("qsort��һ������Ϊָ�룬ָ���������������Ԫ��\n");
	printf("�ڶ��������Ǵ������������\n");
	printf("������������ָ�������������ÿ��Ԫ�صĴ�С\n");
	printf("���ĸ�����Ϊһ��ָ��ָ������ָ�룬���ָ��ıȽϺ�������ȷ�������˳�򣬸ú���Ӧ���������������ֱ�ָ����Ƚ������ָ��\n");
	printf("�����һ����ڵڶ���ȽϺ����򷵻����������������ͬ����0�������һ��С�ڵڶ���򷵻ظ�����\n");
	double vals[NUM];
	fillarray(vals,NUM);//��������
	puts("Random list:");
	showarray(vals,NUM);//��ӡԭʼ����
	qsort(vals,NUM,sizeof(double),mycomp);//��������
	puts("\nSorted list:");
	showarray(vals,NUM);//��ӡ����õ�����
	return 0;
}

void fillarray(double ar[],int n){
	int index;
	for(index = 0;index<n;index++)
		ar[index] = (double)rand()/((double)rand()+0.1);
}

void showarray(const double ar[],int n){
	int index;
	for(index = 0;index<n;index++){
		printf("%9.4f ",ar[index]);
		if(index % 6 == 5) putchar('\n');
	}
	if(index % 6 != 0) putchar('\n');
}
int mycomp(const void *p1,const void *p2){
	//Ҫʹ��ָ��double��ָ��������������ֵ
	const double *a1 = (const double *)p1;
	const double *a2 = (const double *)p2;
	return *a1 - *a2;//����Ӵ�С������return *a2 - *a1;
}
