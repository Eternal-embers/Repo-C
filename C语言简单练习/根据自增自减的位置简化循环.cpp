#include<stdio.h>
#include<math.h>
int main()
{
 int count=0,n=10;
 printf("square:\n");
 while(++count<11)//++count等于11时停止循环 
 {
 	printf("%d's square is %d\n",n,n*n);
 	n++;
    //count++;如果count出现在循环体后面用++count 
 }
 n=11; 
 printf("cube:\n");
 while(count++<20)
 {
 	//count++;如果count出现在循环体前面用count++ 
 	printf("%d's cube is %d\n",n,n*n*n);
 	n++;
 }
 return 0;
}
