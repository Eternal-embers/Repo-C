/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/30 23:38
	Description: 一元三次方程求解
*/
#include<stdio.h>
#include<math.h>

double a,b,c,d;

double f(double x){
	return a*x*x*x + b*x*x + c*x + d;
}

int exist(double x1,double x2){
	return f(x1) * f(x2) <= 0;
}

double binarySearch(int i,int j){
	double left = i,right = j;
	double mid = (left + right) / 2;
	while(fabs(f(mid)) > 1e-6){
		if(exist(left,mid))
			right = mid;
		else
			left = mid;
		mid = (left + right) / 2;
	}
	return mid;
}

int main(){
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	/* 根与根之差的绝对值大于等于1，根据此可以知道在两根之间至少存在一个整数 */
	//检查i与i+1之间是否存在根
	for(int i = -100;i < 100;i++){
		if(exist(i,i + 1)) {
			printf("%.2f ",binarySearch(i,i + 1));
			if(f(i+1) == 0) i++;
		}
	}
	return 0;
}

