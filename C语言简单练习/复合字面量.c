#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	//复合字面量，也可以理解为强制转换,可以不需要另外创建一个数组 
	char *p1 = (char [8]){'a','b','c','d','e','f','g','\0'};
	char *p2 = (char [11]){"hello,world"};
	int *pt = (int[4]){10,20,30,40};//复合字面量，可以不需要事先创建数组，复合字面量创建了一个匿名数组，必须在创建的同时时使用它 
    for(i=0;i<4;i++)
    printf("%d ",pt[i]);
    printf("\n");
    for(i=0;i<8;i++)
    printf("%c ",p1[i]);
    printf("\n");
    for(i=0;i<11;i++)
    printf("%c",p2[i]);
    return 0;
}
