#include <stdio.h>
#include <stdlib.h>
/*
方程:a*a + b*b + c*c = 1000有一组正整数解6，80，30，求它的另一组解
*/
int main(int argc, char *argv[])
{
	int a,b,c;
  	for(a = 1;a < 32;a++)
    	for(b = a; b < 32;b++)
      		for(c = b; c < 32;c++){
        		if(a * a + b * b + c * c == 1000 && a != 6){
		 			 printf("%d %d %d\n",a,b,c);
        		}
      		}
  return 0;
}
