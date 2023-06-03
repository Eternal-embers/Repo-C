#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b,c,d,e,f,g,h,i,ans = 0;
  for(a = 1;a < 10;a++)
    for(b = 1;b < 10;b++)
    if(a!=b)
      for(c = 1;c < 10;c++)
      if(c!=b && c!=a)
        for(d = 1;d < 10;d++)
        if(d!=c && d!=b && d!=a)
          for(e = 1;e < 10;e++)
          if(e!=d && e!=c && e!=b && e!=a)
            for(f = 1;f < 10;f++)
            if(f!=e && f!=d && f!=c && f!=b && f!=a)
              for(g = 1;g < 10;g++)
              if(g!=f && g!=e && g!=d && g!=c && g!=b && g!=a )
                for(h = 1;h < 10;h++)
                if(h!=g && h!=f && h!=e && h!=d && h!=c && h!=b && h!=a)
                  for(i = 1;i < 10;i++)
                  if(i!=h && i!=g && i!=f && i!=e && i!=d && i!=c && i!=b && i!=a
                   && (100*g+10*h+i)*b+(100*d+10*e+f)*c==c*(10-a)*(100*g+10*h+i))
                        ans++;
  printf("%d",ans);
  return 0;
}
