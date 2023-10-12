/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<math.h>

double f(double t){
	return 0.9917 * pow(t,144) + t - 0.9917;
}

int main(){
	double left = -1,right = 1;
	double mid = 0;
	while(fabs(f(mid)) > 1e-15){
		mid = (left + right) / 2;
		printf("t = %.15f,f(t)=%.15f\n",mid,f(mid));
		if(f(mid) < 0) left = mid;
		else if(f(mid) > 0) right = mid;
		else break;
	}
	printf("最终结果：t = %.15f,f(t) = %.15f",mid,f(mid));
    return 0;
}

