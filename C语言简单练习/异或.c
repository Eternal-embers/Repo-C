#include<stdio.h>
void swap(int *a,int *b){
	if(&(*a)==&(*a)) return;
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
int main()
{
	int a = 3;
	int *p = &a;
	printf("异或交换两个数的值并不能加快速度\n");
	printf("如果通过异或来交换值存在一个陷阱\n");
	printf("当两个数的地址相同时，用异或交换它们的值会使得它们全部为0\n");
	printf("所以交换两个数的值前需要检查它们是否是同一地址\n");
	printf("a = %d\n",a);
	swap(&a,&a);
	printf("&a = %d\n",&a);
	printf("&(*p) = %d\n",&(*p));
	printf("a^a后：a = %d",a);
	return 0;
}
