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
#define LEN 1000000

char s1[LEN],s2[LEN];

void bigNumberAddition(char* x1,char* x2){
	int i,j;
	/* 获取x1和x2位数 */
	int len1 = strlen(x1);
	int len2 = strlen(x2);
	
	/* 确定结果的正负 */
	_Bool flag1 = 1,flag2 = 1,flag = 1;//假设x1和x2和x1+x2结果为正
	if(x1[0] == '-') {
		flag1 = 0;//记录负号信息
		for(i = 0;i < len1;i++)
			x1[i] = x1[i + 1];
		len1--;
	}//向前挪位
	if(x2[0] == '-') {
		flag2 = 0;//记录负号信息
		for(i = 0;i < len2;i++)
			x2[i] = x2[i + 1];
		len2--;
	}//向前挪位
	
    /* 处理负号 */
	if(flag1 == 0 && flag2 == 1) flag = 0;//负数减正数，结果为负
	else if( (flag1 == 1 && flag2 == 1) && (len1 < len2 || len1 == len2 && x1[0] < x2[0]) ){
		flag = 0; //小的正数减去一个大的正数，结果为负
	}
	else if( (flag1 == 0 && flag2 == 0) && (len1 > len2 || len1 == len2 && x1[0] > x2[0]) ){
		flag = 0;//小的负数减去一个大的负数，结果为负
	}

	/* 将数字字符串转换为数组 */
	int n1[len1],n2[len2];
	//将数字从低位到高位排序,方便进位
	for(i = 0;i < len1;i++)
		n1[len1 - i - 1] = x1[i] - '0';
	for(i = 0;i < len2;i++)
		n2[len2 - i - 1] = x2[i] - '0';

	/*计算结果*/
	int len = len1 > len2 ? len1 + 1 : len2 + 1;
	int res[len];
	memset(res,0,sizeof(res));
	if(flag1 + flag2 == 1){//如果x1和x2异号
		for(i = 0;i < len1;i++){
			if(i < len1 && i < len2) {
				res[i] = n1[i] - n2[i];
				if(res[i] < 0) res[i] = -res[i];
			}
				else if(i < len1) res[i] = n1[i];
					else res[i] = n2[i];
		}
	}
	else{//如果x1和x2同号
		for(i = 0;i < len1;i++){
			if(i < len1 && i < len2) res[i] = n1[i] + n2[i];
				else if(i < len1) res[i] = n1[i];
					else res[i] = n2[i];
		}
	}

	/*进位*/
	for(i = 0;i < len;i++){
		if(res[i] >= 10){
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	/*确定最终位数*/
       for(i = len - 1;i >= 0;i--){
		if(res[i] > 0){
			len = i + 1;
			break;
		}
	}
	if(i < 0) len = 0;
	int count = len;
	
	/*输出结果*/
	if(len == 0) {
		putchar('0');
		return;
	}
	if(flag == 0) printf("-");
	i = len - 1;
	while(i > 0){
		printf("%d",res[i]);
		count--;
		if(count % 3 == 0) putchar(',');
		i--;
	}
	printf("%d",res[0]);//最后一位后面没有逗号，单独输出
}
int main(){
	printf("x1 = ");
	scanf("%s",s1);
	printf("x2 = ");
	scanf("%s",s2);
	printf("(%s) + (%s) = ",s1,s2);
	bigNumberAddition(s1,s2);
	system("pause>NULL");
	return 0;
}
