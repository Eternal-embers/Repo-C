#include<stdio.h>
int main(){
	int day,month,year,m2,d;
	int sum1,sum2,ans = 0;
	for(year = 1900; year <= 9999;year++){
		if(year % 4==0 && year % 100!=0 || year % 400==0) m2 = 29;
			else m2 = 28;
		for(month = 1;month <= 12;month++){
			if(month==2) d = m2;
				else if(month == 4 || month==6 || month== 9 || month==11) d = 30;
					else d = 31;
			for(day = 1;day <= d;day++){
				int a = year,b = month,c = day;
				sum1 = sum2 = 0;
				while(a>0){
					sum1+=a%10;
					a/=10;
				}
				while(b>0){
					sum2+=b%10;
					b/=10;
				}
				while(c>0){
					sum2+=c%10;
					c/=10;
				}
				if(sum1==sum2) ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
