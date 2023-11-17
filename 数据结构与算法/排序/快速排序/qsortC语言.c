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
	printf("qsort第一个参数为指针，指向待排序的数组的首元素\n");
	printf("第二个参数是待排序项的数量\n");
	printf("第三个参数是指明待排序数组的每个元素的大小\n");
	printf("第四个参数为一个指向指向函数的指针，这个指针的比较函数用于确定排序的顺序，该函数应接受两个参数，分别指向待比较两项的指针\n");
	printf("如果第一项大于第二项，比较函数则返回正数，如果两项相同返回0，如果第一项小于第二项，则返回负数。\n");
	double vals[NUM];
	fillarray(vals,NUM);//生成数据
	puts("Random list:");
	showarray(vals,NUM);//打印原始数组
	qsort(vals,NUM,sizeof(double),mycomp);//快速排序
	puts("\nSorted list:");
	showarray(vals,NUM);//打印排序好的数组
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
	//要使用指向double的指针来访问这两个值
	const double *a1 = (const double *)p1;
	const double *a2 = (const double *)p2;
	return *a1 - *a2;//如果从大到小排序则return *a2 - *a1;
}
