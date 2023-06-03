#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
 int i,j,count=0;
 for(i=2;count!=2019;i++)
 {
     for(j=2;j<sqrt(i);j++)
     if(i%j==0)break;
     if(j>sqrt(i))count++;
 }
 printf("%d",i-1);
 system("pause");
 return 0;
}
