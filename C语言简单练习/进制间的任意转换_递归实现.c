#include<stdio.h>
#include<stdlib.h>

/* radix����תʮ���� */
unsigned convertToDecimal(unsigned* digits,unsigned radix,unsigned len){
	int i;
	unsigned res = 0,weight = 1;//ת�����
	for(i = 0;i < len;i++){
		res += weight * digits[len - i - 1];
		weight *= radix;
	}
	printf("convert to decimal number: %u\n",res);
	return res;
}

/* ʮ������תdest������ */
unsigned* baseConvert(unsigned decimal,unsigned dest){
	if(decimal > 0){
		baseConvert(decimal / dest,dest);
		printf("%d ",decimal % dest);
	}
}

/* ����ת������ */
void convert(unsigned *bits,unsigned len,unsigned orgin,unsigned dest){
	unsigned decimal = convertToDecimal(bits,orgin,len);
	printf("%u convert to base %u: ",decimal,dest);
 	baseConvert(decimal,dest);//ʮ������תdest������
}

int main(){
	int bits[6] = {1,5,0,2,7,1};//12���Ʊ���,ʮ������352885
	unsigned len = 6,orgin = 12,dest = 16;
	printf("Base %d code: ",orgin);
	int i;
	for(i = 0;i < len;i++)
		printf("%d ",bits[i]);
	putchar('\n');
	convert(bits,len,orgin,dest);//�õ�16���Ʊ���[5,6,2,7,5]
	return 0;
}

