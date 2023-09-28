/*
	Name: 判断浮点数的大小
	Copyright:劣等生
	Author:劣等生
	Date: 09/24 11:56
	Description: 根据IEEE浮点标准来判断浮点数的大小
*/
#include<stdio.h>
#include<math.h>

typedef union {
    float f;
    unsigned int u;
} FloatToUnsigned;

void printBits(unsigned int num) {
    int numBits = sizeof(num) * 8; // 获取无符号整数的总位数
    int i;
    for (i = numBits - 1; i >= 0; i--) {
        unsigned int mask = 1 << i; // 创建一个只有第i位为1的掩码
        int bit = (num & mask) ? 1 : 0; // 检查第i位是否为1
        printf("%d", bit); // 打印第i位的值
    }
    printf("\n");
}

unsigned int f2u(float f) {
    FloatToUnsigned converter;
    converter.f = f;
    printBits(converter.u);
    return converter.u;
}


int float_le(float x,float y){
	/* convert float to unsigned */
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
	/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	//return 1 when x < y,return 0 when x > y,return -1 when x = y
	return ux == uy ? -1 : (1 - (sx<<1)) * ux < (1 - (sy<<1)) * uy;
}


int main(){
	//test
	float a = -3.0;
	float b = -2.0;
	int res = float_le(a,b);
	printf("a = %f,b = %f\n",a,b);
	if(res == -1) printf("a = b");
	else if(res) printf("a < b");
	else printf("a > b");
	return 0;
}

/*
	根据我下面提供的逻辑填写返回值：
    1.sx = 1,sy = 0
    下列情况x <= y:
    2.sx = 0,sy = 0 且 ux <= uy
    3.sx = 1,sy = 1 且 ux >= uy
    下列情况x > y:
	1.sx = 0,sy = 1
	2.sx = 0,sy = 0 且 ux > uy
	3.sx = 1,sy = 1 且 ux < uy
    请用sx,sy,ux,uy编写返回值的表达式，当x <= y时返回1，当x > y时返回0
*/
