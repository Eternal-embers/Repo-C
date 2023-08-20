/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/31 19:07
	Description: 阶乘计算
*/
#include<stdio.h>
#include<string.h>
#define LEN 5000

int a[LEN],b[LEN];

void clear(int a[]){
	int i;
	for(i = 0;i < LEN;i++)
		a[i] = 0;
}

void read(int a[]){
	char s[LEN + 1];
	scanf("%s",s);
	clear(a);
	int i,length = strlen(s);
	for(i = 0;i < length;i++)
		a[length - i - 1] = s[i] - '0';
}

void print(int a[]){
	int i;
	for(i = LEN;i >= 1;i--)
		if(a[i] != 0) break;
	while(i >= 0)
		putchar(a[i--] + '0');
	putchar('\n');
}


void mult_short(int a[],int b,int c[]){
	clear(c);
	int i;
	for(i = 0;i < LEN;i++){
		c[i] += a[i] * b;
		if(c[i] >= 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

int* frac(int n){
	int i;
	a[0] = 1;
	int *p1 = a,*p2 = b;
	for(i = 1;i <= n;i++){
		mult_short(p1,i,p2);
		int *t = p1;
		p1 = p2;
		p2 = t;
	}
	return p1;
}

/*
void mult(int a[],int b[],int c[]){
	clear(c);
	int i,j;
	for(i = 0;i < LEN;i++){
		for(j = 0;j <= i;j++){
			c[i] += a[j] * b[i - j];
			if(c[i] >= 10) {
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
			}
		}
	}
}
*/

int main(){
	int n;
	scanf("%d",&n);
	int *res = frac(n);
	print(res);
	return 0;
}

