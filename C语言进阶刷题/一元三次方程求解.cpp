/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:07/30 23:38
	Description: һԪ���η������
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
	/* �����֮��ľ���ֵ���ڵ���1�����ݴ˿���֪��������֮�����ٴ���һ������ */
	//���i��i+1֮���Ƿ���ڸ�
	for(int i = -100;i < 100;i++){
		if(exist(i,i + 1)) {
			printf("%.2f ",binarySearch(i,i + 1));
			if(f(i+1) == 0) i++;
		}
	}
	return 0;
}

