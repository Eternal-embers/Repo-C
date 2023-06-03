#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int a,b,c,d,e,num;
  for(a = 1;a<10;a++)
    for(b = 0;b<10;b++)
      for(c = 0;c<10;c++)
        for(d = 0;d<10;d++)
          for(e = 0;e<10;e++){
            if(a!=b && a!=c && a!=d && a!=e && b!=c && b!=d && b!=e && c!=d && c!=e && d!=e){
              for(num = 2;num<10;num++)
                if((a*10000+b*1000+c*100+d*10+e)*num==(e*10000+d*1000+c*100+b*10+a)){
                printf("%d%d%d%d%d",a,b,c,d,e);
                return 0;
                }
              }
          }
}
