/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description: 三角形的面积-向量法
*/
#include<stdio.h>
#include<math.h>

double res[1004] = {0};

int main(){
	//S = (|AB| X |AC|)/2
	int T;
	scanf("%d",&T);
	int i;
	for(i = 0;i < T;i++){
		double x1,y1,x2,y2,x3,y3;
		scanf("%lf %lf",&x1,&y1);
		scanf("%lf %lf",&x2,&y2);
		scanf("%lf %lf",&x3,&y3);
        res[i] = fabs(((x1-x2)*(y1-y3)-(y1-y2)*(x1-x3)) / 2);
	}
	for(i = 0;i < T;i++){
		printf("%.2f\n",res[i]);
	}
	return 0;
}

