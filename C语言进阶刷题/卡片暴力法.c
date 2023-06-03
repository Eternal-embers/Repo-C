#include<stdio.h>
int main(){
	int num[10] =
	{2021,2021,2021,2021,2021,2021,2021,2021,2021,2021};
	int i = 1,t,bit;
	while(1){
		t = i;
		while(t > 0){
			bit = t % 10;
			num[bit]--;
			if(num[bit] < 0) {
				printf("%d",i);
				return;
			}
			t /= 10;
		}
		i++;
	}
}
