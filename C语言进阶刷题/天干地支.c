#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ÇëÔÚ´ËÊäÈëÄúµÄ´úÂë
  const char *sky[10]={"¼×","ÒÒ","±û","¶¡","Îì","¼º","¸ı","ĞÁ","ÈÉ","¹ï"};
  const char *land[12]={"×Ó","³ó","Òú","Ã®","³½","ËÈ","Îç","Î´","Éê","ÓÏ","Ğç","º¥"};
  //1984ÄêÎª¸ı×ÓÄê
  int year;
  int index_sky,index_land;
  printf(">>");
  scanf("%d",&year);
  if(year>1984) {
    index_sky = (year-1984)%10;
    index_land = (year-1984)%12;
  }
  else {
    index_sky = 9-(1983-year)%10;
    index_land = 11-(1983-year)%12;
  }
  printf("%s%s",sky[index_sky],land[index_land]);
  return 0;
}
