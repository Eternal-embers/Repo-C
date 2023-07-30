/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/30 15:05
	Description: 海伦公式计算三角形的面积
*/
#include<stdio.h>
#include<math.h>

double res[1004] = {0};

int main(){
	//S = sqrt(p(p-a)(p-b)(p-c))
	int T;
	scanf("%d",&T);
	int i;
	for(i = 0;i < T;i++){
		double x1,y1,x2,y2,x3,y3;
		scanf("%lf %lf",&x1,&y1);
		scanf("%lf %lf",&x2,&y2);
		scanf("%lf %lf",&x3,&y3);
		double a = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
		double b = sqrt(pow(x1-x3,2) + pow(y1-y3,2));
		double c = sqrt(pow(x2-x3,2) + pow(y2-y3,2));
		double p = (a + b + c) / 2;;
		res[i] = sqrt(p*(p-a)*(p-b)*(p-c));
	}
	for(i = 0;i < T;i++){
		printf("%.2f\n",res[i]);
	}
	return 0;
}

