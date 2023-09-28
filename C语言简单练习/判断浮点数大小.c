/*
	Name: �жϸ������Ĵ�С
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 09/24 11:56
	Description: ����IEEE�����׼���жϸ������Ĵ�С
*/
#include<stdio.h>
#include<math.h>

typedef union {
    float f;
    unsigned int u;
} FloatToUnsigned;

void printBits(unsigned int num) {
    int numBits = sizeof(num) * 8; // ��ȡ�޷�����������λ��
    int i;
    for (i = numBits - 1; i >= 0; i--) {
        unsigned int mask = 1 << i; // ����һ��ֻ�е�iλΪ1������
        int bit = (num & mask) ? 1 : 0; // ����iλ�Ƿ�Ϊ1
        printf("%d", bit); // ��ӡ��iλ��ֵ
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
	�����������ṩ���߼���д����ֵ��
    1.sx = 1,sy = 0
    �������x <= y:
    2.sx = 0,sy = 0 �� ux <= uy
    3.sx = 1,sy = 1 �� ux >= uy
    �������x > y:
	1.sx = 0,sy = 1
	2.sx = 0,sy = 0 �� ux > uy
	3.sx = 1,sy = 1 �� ux < uy
    ����sx,sy,ux,uy��д����ֵ�ı��ʽ����x <= yʱ����1����x > yʱ����0
*/
