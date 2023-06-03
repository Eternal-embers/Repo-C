#include<stdio.h>
#include<math.h>
float inv_sqrt(float x){
	float xhalf = 0.5 * x;
	int i = *(int *)&x;
	i = 0x5f375a86 - (i >> 1);//最优解0x5f375a86,0x5f3759df
	x = *(float *)&i;
	x = x * (1.5 - xhalf * x * x);
	return x;
}//最终x = sqrt(x)/1;
//巧妙利用了float的存储方式，经过一次牛顿迭代就可以把误差缩小到千分之一
int main(){
	int i;
	for(i = 2;i < 50;i++){
		printf("sqrt(%d) = %f\n",i,1/sqrt(i));
		printf("inv_sqrt(%d) = %f\n",i,inv_sqrt(i));
		printf("误差%lf\n\n",fabs(1/sqrt(i) - inv_sqrt(i)));
	}
	return 0;
}
