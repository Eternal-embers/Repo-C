/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<string.h>
#include<memory.h>
#define LEN 100
void bigNumberMultiply(char* x1,char* x2){
	/*计算x1和x2的位数*/
	int len1,len2;
	len1 = strlen(x1);
	len2 = strlen(x2);
	/*判断正负*/
	int flag = 1,i,j;
	if(x1[0] == '-') {
		flag *= -1;
		for(i = 0;i < len1;i++)
			x1[i] = x1[i + 1];
		len1--;
	}
	if(x2[0] == '-') {
		flag *= -1;
		for(i = 0;i < len2;i++)
			x2[i] = x2[i + 1];
		len2--;
	}
	/*将字符数字串转换为数组*/
	int n1[len1],n2[len2];
	for(i = 0;i < len1;i++)
		n1[len1 - i - 1] = x1[i] - '0';
	for(i = 0;i < len2;i++)
		n2[len2 - i - 1] = x2[i] - '0';
	/*计算乘积结果*/
	int len = len1 + len2;
	int res[len];
	memset(res,0,sizeof(res));
	for(i = 0;i < len1;i++)
		for(j = 0;j < len2;j++)
			res[i + j] += n1[i]*n2[j];
	/*进位*/
	for(i = 0;i < len - 1;i++){
		if(res[i] >=  10){
			res[i+1] += res[i]/10;
			res[i] %= 10;
		}
	}
	/*确定最终结果的位数*/
	int count = len - 2;
	if(res[len - 1] > 0) count++;
	if(res[len - 2] > 0) count++;
	/*输出结果，用逗号分隔每三位数字*/
	if(flag == -1) printf("-");//如果结果为负数，输出负数符号
	if(res[len - 1] > 0) {
		printf("%d",res[len - 1]);
		count--;
		if(count % 3 == 0) putchar(',');
	}
	i = len - 2;
	while(i > 0){
		printf("%d",res[i]);
		count--;
		if(count % 3 == 0) putchar(',');
		i--;
	}
	printf("%d",res[0]);
}

int main(){
	char s1[LEN],s2[LEN];
	printf("x1 = ");
	scanf("%s",s1);
	printf("x2 = ");
	scanf("%s",s2);
	printf("%s * %s = ",s1,s2);
	bigNumberMultiply(s1,s2);
	system("pause>NULL");
	return 0;
}

