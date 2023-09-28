#include<stdio.h>
#include<stdlib.h>

/* radix进制转十进制 */
unsigned convertToDecimal(unsigned* digits,unsigned radix,unsigned len){
	int i;
	unsigned res = 0,weight = 1;//转换结果
	for(i = 0;i < len;i++){
		res += weight * digits[len - i - 1];
		weight *= radix;
	}
	printf("convert to decimal number: %u\n",res);
	return res;
}

/* 十进制数转dest进制数 */
unsigned* baseConvert(unsigned decimal,unsigned dest){
	if(decimal > 0){
		baseConvert(decimal / dest,dest);
		printf("%d ",decimal % dest);
	}
}

/* 进制转换函数 */
void convert(unsigned *bits,unsigned len,unsigned orgin,unsigned dest){
	unsigned decimal = convertToDecimal(bits,orgin,len);
	printf("%u convert to base %u: ",decimal,dest);
 	baseConvert(decimal,dest);//十进制数转dest进制数
}

int main(){
	int bits[6] = {1,5,0,2,7,1};//12进制编码,十进制数352885
	unsigned len = 6,orgin = 12,dest = 16;
	printf("Base %d code: ",orgin);
	int i;
	for(i = 0;i < len;i++)
		printf("%d ",bits[i]);
	putchar('\n');
	convert(bits,len,orgin,dest);//得到16进制编码[5,6,2,7,5]
	return 0;
}

