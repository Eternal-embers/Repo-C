#include <stdio.h>
#include <stdlib.h>
/*
阿尔法炸弹2015 年1 月1日放置，定时为15天，则它在2015年1月16日爆炸。
有一个贝塔炸弹，2014 年11 月9 日放置，定时为1000 天，请你计算它爆炸的准确日期。
请输出该日期，格式为yyyy-mm-dd 即4 位年份2 位月份2 位日期。比如：2015-02-19。
*/
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
_Bool isLeap(int year){
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int main(){
	int y,m,d,days,cnt = 53;
	for(y = 2015;;y++){
		for(m = 1;m <= 12;m++){
			if(m == 2) days = day[m] + isLeap(y);
				else days = day[m];
			for(d = 1;d <= days;d++){
				if(cnt == 1000) {
					printf("%d-%02d-%02d",y,m,d);
					return 0;
				}
				cnt++;
			}
		}
	}
}
