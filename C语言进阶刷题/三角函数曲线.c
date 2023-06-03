//用“@”显示0～360的sin(x)的曲线

#include <stdio.h>
#include <math.h>

int main()
{
 int x;
 int m;
 int i;

 double y;

 for (y = 1; y >= 0.1; y = y - 0.1)
 {
  x = asin(y) * 10;
 m = 31 - x;

 for (i = 0; i < x; i++)
 {
  printf(" ");
 }

 printf("@");

 for ( ; i < m; i++)
 {
  printf(" ");
 }

 printf("@\n");
 }

 printf("@");
 for (i = 0; i < 31; i++)
 {
 printf(" ");
 }
 printf("@");
 for (i = 31; i < 62; i++)
 {
 printf(" ");
 }
 printf("@\n");

 for (y = -0.1; y >= -1; y = y - 0.1)
 {
  x = - asin(y) * 10;
 m = 31 - x;

 for (i = 0; i < x + 32; i++)
 {
  printf(" ");
 }

 printf("@");

 for (i = x; i < m; i++)
 {
  printf(" ");
 }

 printf("@\n");
 }

 return 0;
}
