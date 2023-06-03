#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int a,b,c,d,n,limit;
  scanf("%d",&n);
  limit = sqrt(n)+1;
  //注意后一个值大于等于前一个值，这里不考虑会有一个过不了
  for(a = 0;a <= limit;a++){
    for(b = a;a*a+b*b<=n;b++){
      for(c = b;a*a+b*b+c*c<=n;c++){
        for(d = c;a*a+b*b+c*c+d*d<=n;d++){
          if(a*a+b*b+c*c+d*d==n){
            printf("%d %d %d %d",a,b,c,d);
            return 0;
          }
        }
      }
    }
  }
}
