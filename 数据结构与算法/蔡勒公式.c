#include<stdio.h>
int dayOfTheWeek(int day,int month,int year){
	int m = month;
	int y = year;
	if(month <= 2){
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y % 100;
	int w = (y + y/4 + c/4 - 2 * c + (26*(m + 1)/10) + day -1) % 7;
	return (w + 7) % 7;
}//蔡勒公式，任意给出某一天，计算星期几

int main(){
	int year,month,day;
	printf("year = ");
	scanf("%d",&year);
	printf("month = ");
	scanf("%d",&month);
	printf("day = ");
	scanf("%d",&day);
	printf("%d/%d/%02d 是星期%d",year,month,day,dayOfTheWeek(day,month,year) == 0 ? 7 : dayOfTheWeek(day,month,year));
	return 0;
}
