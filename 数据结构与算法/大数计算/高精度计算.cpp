/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

static const int LEN = 1004;

int a[LEN],b[LEN],c[LEN],d[LEN];

void clear(int a[]){
	for(int i = 0;i < LEN;++i)
		a[i] = 0;
}

void read(int a[]){
	static char s[LEN + 1];
	scanf("%s",s);
	clear(a);
	int len = strlen(s);
	for(int i = 0;i < len;++i)
		a[len - i - 1] = s[i] - '0';
}

void print(int a[]){
	int i;
 	for(i = LEN - 1;i >= 1;--i)
		if(a[i] != 0) break;
	while(i >= 0)
		putchar(a[i--] + '0');
	putchar('\n');
}

void add(int a[],int b[],int c[]){
	 clear(c);
	 for(int i = 0;i < LEN - 1;++i){
	 	c[i] += a[i] + b[i];
	 	if(c[i] >= 10){
			c[i + 1] += 1;
			c[i] -= 10;
		}
	 }
}

//只能处理a>b情况的a-b
void sub(int a[],int b[],int c[]){
	clear(c);
	for(int i = 0;i < LEN - 1;++i){
		c[i] += a[i] - b[i];
		if(c[i] < 0){
			c[i + 1] -= 1;
			c[i] += 10;
		}
	}
}

//高精度-单精度
void mul_short(int a[],int b,int c[]){
	clear(c);
	for(int i = 0;i < LEN - 1;++i){
		c[i] += a[i] * b;//直接把a的第i位乘以乘数b
		if(c[i] >= 10){
            c[i + 1] += c[i] / 10;//进位的增量值
            c[i] %= 10;//当前位留下的值
		}
	}
}

//高精度-高精度
/*
	竖式计算a*b的每一步实际上是计算a*b[i]*(10^i)
    将b分解为它的所有数码，其中每个数码都是单精度数，
	将它们分别与a相乘，再向左移动到各自的位置上相加即可得到答案
*/
void mul(int a[],int b[],int c[]){
	clear(c);
	for(int i = 0;i < LEN - 1;++i){
		//计算结果中从低到高第i位，并一并处理了进位
		//第i次循环为c[i]加上了所有满足p + q = i的a[p]与b[q]的乘积之和
		for(int j = 0;j <= i;++j)
			c[i] += a[j] * b[i - j];//计算第10的i次方位
		if(c[i] >= 10){
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

int *karatsuba_polymul(int n, int *a, int *b) {
  if (n <= 32) {
    // 规模较小时直接计算，避免继续递归带来的效率损失
    int *r = new int[n * 2 + 1]();
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j) r[i + j] += a[i] * b[j];
    return r;
  }

  int m = n / 2 + 1;
  int *r = new int[m * 4 + 1]();
  int *z0, *z1, *z2;

  z0 = karatsuba_polymul(m - 1, a, b);
  z2 = karatsuba_polymul(n - m, a + m, b + m);

  // 计算 z1
  // 临时更改，计算完毕后恢复
  for (int i = 0; i + m <= n; ++i) a[i] += a[i + m];
  for (int i = 0; i + m <= n; ++i) b[i] += b[i + m];
  z1 = karatsuba_polymul(m - 1, a, b);
  for (int i = 0; i + m <= n; ++i) a[i] -= a[i + m];
  for (int i = 0; i + m <= n; ++i) b[i] -= b[i + m];
  for (int i = 0; i <= (m - 1) * 2; ++i) z1[i] -= z0[i];
  for (int i = 0; i <= (n - m) * 2; ++i) z1[i] -= z2[i];

  // 由 z0、z1、z2 组合获得结果
  for (int i = 0; i <= (m - 1) * 2; ++i) r[i] += z0[i];
  for (int i = 0; i <= (m - 1) * 2; ++i) r[i + m] += z1[i];
  for (int i = 0; i <= (n - m) * 2; ++i) r[i + m * 2] += z2[i];

  delete[] z0;
  delete[] z1;
  delete[] z2;
  return r;
}
//Karatsuba 乘法
void karatsuba_mul(int a[], int b[], int c[]) {
  int *r = karatsuba_polymul(LEN - 1, a, b);
  memcpy(c, r, sizeof(int) * LEN);
  for (int i = 0; i < LEN - 1; ++i)
    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  delete[] r;
}

/* 判断剩余的被除数是否可以减去一个除数*/
bool greater_eq(int a[],int b[],int last_dg,int len) {
	//有可能被除数剩余部分比除数长，这个情况下最多多出1位
	//len是被除数b的长度，避免反复计算
	if(a[last_dg + len] != 0) return true;
	//从高位到地位，逐位比较
	for(int i = len - 1;i >= 0;--i){
		if(a[last_dg + i] > b[i]) return true;
		if(a[last_dg + i] < b[i]) return false;
	}
	return true;//相等情形
}

/* 模拟竖式除法运算 */
void div(int a[],int b[],int c[],int d[]){
 	clear(c);
	clear(d);

	int la,lb;
	for(la = LEN - 1;la > 0;--la)
		if(a[la - 1] != 0) break;
	for(lb = LEN - 1;lb > 0;--lb)
		if(b[lb - 1] != 0) break;
	if(lb == 0) {
		puts("> <");
		return;
	}//除数不能为0

	/* c是商，d是被除数的剩余部分 */
	for(int i = 0;i < la;++i) d[i] = a[i];
	for(int i = la - lb;i >= 0;--i){
		//计算商的第i位
		while(greater_eq(d,b,i,lb)){
			//高精度减法
			//若可以减去一个除数，那么减
			for(int j = 0;j < lb;++j){
				d[i + j] -= b[j];
				if(d[i + j] < 0) {
					d[i + j + 1] -= 1;
					d[i + j] += 10;;
				}
			}
			c[i] += 1;//商的此位加1
		}
	}
}

int main(){
	read(a);
	read(b);
	div(a,b,c,d);
	print(c);
	print(d);
	return 0;
}

