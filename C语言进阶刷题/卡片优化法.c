#include<stdio.h>
int main(){
	int count,i = 1,t;//count统计1出现的次数
	//1一定是最先被用完的
	while(1){
	   t = i;
	   while(t > 0){
			if(t % 10==1) count++;
			if(count>2021) {
				printf("%d",i);
				return;
			}
			t /= 10;
	   }
	   i++;
	}
}
