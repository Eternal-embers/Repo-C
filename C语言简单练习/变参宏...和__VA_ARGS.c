#include<stdio.h>
#include<math.h>
#define PR(X,...) printf("Message" #X ":" __VA_ARGS__)

/*
    通过宏参数列表中的最后参数写成省略号可以实现函数接受可变的参数
    预定义宏__VA_ARGS__可用于替换部分，表名省略号代表什么
*/

int main(){
    double x = 48;
    double y;
    y = sqrt(x);
    PR(1,"x = %g\n",x);
    PR(2,"x = %.2f,y = %.4f\n",x,y);
	return 0;
}

