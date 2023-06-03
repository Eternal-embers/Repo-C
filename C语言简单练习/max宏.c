#include<stdio.h>
#define max(x,y) ({         \
	typeof(x) _x = (x);    \
	typeof(y) _y = (y);    \
	(void) (&_x == &_y);    \
	_x > _y ? _x : _y; })
//(void) (&_x == &_y); 对于不同类型的指针比较，编译器会给出一个警告
//当两个值比较，比较的结果没有用到时编译器会给出警告，此句可以消除警告

int main(){
	printf("%f",max(32.4,31.5));
	return 0;
}

