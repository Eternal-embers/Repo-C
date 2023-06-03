#include<stdio.h>
//基准年份：          2008   2009   2010   2011   2012   2013   2014   2015   2016   2017   2018   2019
const char *ani[12] = {"子鼠","丑牛","寅虎","卯兔","辰龙","巳蛇","午马","未羊","申猴","酉鸡","戌狗","亥猪"};
//基准月份：           1.20-2.18  2.19-3.20 3.21-4.19 4.20-5.20 5.21-6.21 6.22-7.22 7.23-8.22 8.23-9.22 9.23-10.23 10.24-11.22 11.23-12.21 12.22-1.19
const char *star[12] = {"水瓶座" ,"双鱼座" ,"白羊座" ,"金牛座" ,"双子座" ,"巨蟹座" ,"狮子座" ,"处女座" ,"天枰座" ,  "天蝎座" ,  "射手座" ,  "摩羯座"}; 
int index_ani,index_star;
int year = 0,month = 0,day = 0,days;
int search(void){
	//判断生肖和年份
	if(year%4==0&&year%100!=0||year%400==0)//闰年 
	{
		if(month==2 && day>29){
		printf("- - -输入错误- - -\n\n");
		return 0;
		}
		//求days 
		if(month==1)days = day;
	    else if(month==2)days = day+31;
	    else if(month==3)days = day+60;
	    else if(month==4)days = day+91;
	    else if(month==5)days = day+121;
	    else if(month==6)days = day+152;
	    else if(month==7)days = day+182;
	    else if(month==8)days = day+213;
	    else if(month==9)days = day+244;
	    else if(month==10)days = day+274;
	    else if(month==11)days = day+305;
	    else if(month==12)days = day+335; 
	     //求index_star 
		if(days>=20 && days<=49)  index_star = 0;
		if(days>=50 && days<=80)  index_star = 1;
		if(days>=81 && days<=110) index_star = 2;
		if(days>=111 && days<=141)index_star = 3;
		if(days>=142 && days<=173)index_star = 4;
		if(days>=174 && days<=204)index_star = 5;
		if(days>=205 && days<=235)index_star = 6;
		if(days>=236 && days<=266)index_star = 7;
		if(days>=267 && days<=297)index_star = 8;
		if(days>=298 && days<=327)index_star = 9;
		if(days>=328 && days<=356)index_star = 10;
		if((days>=357 && days<=366) || (days>=0 && days<=19))	index_star = 11;
	}
	else//非闰年 
	{
		if(month==2 && day>28){
		printf("- - -输入错误- - -\n\n");
		return 0;
		}
		//求days
		if(month==1)days = day;
	    else if(month==2)days = day+31;
	    else if(month==3)days = day+59;
	    else if(month==4)days = day+90;
	    else if(month==5)days = day+120;
	    else if(month==6)days = day+151;
	    else if(month==7)days = day+181;
	    else if(month==8)days = day+212;
	    else if(month==9)days = day+243;
	    else if(month==10)days = day+273;
	    else if(month==11)days = day+304;
	    else if(month==12)days = day+334; 
	    //计算index_star
		if(days>=20 && days<=49)  index_star = 0;
		if(days>=50 && days<=79)  index_star = 1;
		if(days>=80 && days<=109) index_star = 2;
		if(days>=110 && days<=140)index_star = 3;
		if(days>=141 && days<=172)index_star = 4;
		if(days>=173 && days<=203)index_star = 5;
		if(days>=204 && days<=234)index_star = 6;
		if(days>=235 && days<=265)index_star = 7;
		if(days>=266 && days<=296)index_star = 8;
		if(days>=297 && days<=326)index_star = 9;
		if(days>=327 && days<=355)index_star = 10;
		if((days>=356 && days<=365) || (days>=0 && days<=19))	index_star = 11; 
	}
	//求index_ani
	if(year>2008)index_ani = (year-2008)%12;
	else index_ani =11-((2007-year)%12);
	//输出结果 
	printf("%s %s\n",ani[index_ani],star[index_star]);
	return 1;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//非闰年，将日期转换为days，1.1代表第1天，12.31代表第365天  
//月份: 1   2   3   4   5   6   7   8   9   10  11  12
//非闰: 0  31  59  90  120 151 181 212 243 273 304 334
//闰年: 0  31  60  91  121 152 182 213 244 274 305 335 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  星座  ：水瓶   双鱼    白羊   金牛   双子    巨蟹    狮子    处女    天枰    天蝎    射手    摩羯
//非闰days:20-49  50-79  80-109 110-140 141-172 173-203 204-234 235-265 266-296 297-326 327-355 356-365-0-19
//闰年days:20-49  50-80  81-110 111-141 142-173 174-204 205-235 236-266 267-297 298-327 328-356 357-366-0-19 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main()
{
	char flag ='Y';
	while(flag=='Y'){
	printf("- - - - - - - - 生肖星座查询 - - - - - - - -\n");
	printf("- - - -输入格式:year-month.day- - - -\n>>");
	scanf("%d-%d.%d",&year,&month,&day);
	if(month<=0 || month>12 || day<=0){
		while(getchar()!='\n')
		continue;
		printf("- - -输入错误- - -\n\n");
		continue;
	}
	if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && day>31){
		while(getchar()!='\n')
		continue;
		printf("- - -输入错误- - -\n\n");
		continue;
	}
	if((month==4 || month==6 || month==9 || month==11) && day>30){
		while(getchar()!='\n')
		continue;
		printf("- - -输入错误- - -\n\n");
		continue;
	}
	getchar();
	if(search()==0)continue;
	printf("- - - -是否要继续查询?Y or N- - - -\n>>");
	scanf("%c",&flag);
	getchar();
	}
	printf("- - -查询结束- - -\n");
	printf("- - - - - - - - - - - - -\n");
	return 0;
}
