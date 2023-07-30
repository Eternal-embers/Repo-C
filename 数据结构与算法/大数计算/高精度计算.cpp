/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
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

//ֻ�ܴ���a>b�����a-b
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

//�߾���-������
void mul_short(int a[],int b,int c[]){
	clear(c);
	for(int i = 0;i < LEN - 1;++i){
		c[i] += a[i] * b;//ֱ�Ӱ�a�ĵ�iλ���Գ���b
		if(c[i] >= 10){
            c[i + 1] += c[i] / 10;//��λ������ֵ
            c[i] %= 10;//��ǰλ���µ�ֵ
		}
	}
}

//�߾���-�߾���
/*
	��ʽ����a*b��ÿһ��ʵ�����Ǽ���a*b[i]*(10^i)
    ��b�ֽ�Ϊ�����������룬����ÿ�����붼�ǵ���������
	�����Ƿֱ���a��ˣ��������ƶ������Ե�λ������Ӽ��ɵõ���
*/
void mul(int a[],int b[],int c[]){
	clear(c);
	for(int i = 0;i < LEN - 1;++i){
		//�������дӵ͵��ߵ�iλ����һ�������˽�λ
		//��i��ѭ��Ϊc[i]��������������p + q = i��a[p]��b[q]�ĳ˻�֮��
		for(int j = 0;j <= i;++j)
			c[i] += a[j] * b[i - j];//�����10��i�η�λ
		if(c[i] >= 10){
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

int *karatsuba_polymul(int n, int *a, int *b) {
  if (n <= 32) {
    // ��ģ��Сʱֱ�Ӽ��㣬��������ݹ������Ч����ʧ
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

  // ���� z1
  // ��ʱ���ģ�������Ϻ�ָ�
  for (int i = 0; i + m <= n; ++i) a[i] += a[i + m];
  for (int i = 0; i + m <= n; ++i) b[i] += b[i + m];
  z1 = karatsuba_polymul(m - 1, a, b);
  for (int i = 0; i + m <= n; ++i) a[i] -= a[i + m];
  for (int i = 0; i + m <= n; ++i) b[i] -= b[i + m];
  for (int i = 0; i <= (m - 1) * 2; ++i) z1[i] -= z0[i];
  for (int i = 0; i <= (n - m) * 2; ++i) z1[i] -= z2[i];

  // �� z0��z1��z2 ��ϻ�ý��
  for (int i = 0; i <= (m - 1) * 2; ++i) r[i] += z0[i];
  for (int i = 0; i <= (m - 1) * 2; ++i) r[i + m] += z1[i];
  for (int i = 0; i <= (n - m) * 2; ++i) r[i + m * 2] += z2[i];

  delete[] z0;
  delete[] z1;
  delete[] z2;
  return r;
}
//Karatsuba �˷�
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

/* �ж�ʣ��ı������Ƿ���Լ�ȥһ������*/
bool greater_eq(int a[],int b[],int last_dg,int len) {
	//�п��ܱ�����ʣ�ಿ�ֱȳ��������������������1λ
	//len�Ǳ�����b�ĳ��ȣ����ⷴ������
	if(a[last_dg + len] != 0) return true;
	//�Ӹ�λ����λ����λ�Ƚ�
	for(int i = len - 1;i >= 0;--i){
		if(a[last_dg + i] > b[i]) return true;
		if(a[last_dg + i] < b[i]) return false;
	}
	return true;//�������
}

/* ģ����ʽ�������� */
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
	}//��������Ϊ0

	/* c���̣�d�Ǳ�������ʣ�ಿ�� */
	for(int i = 0;i < la;++i) d[i] = a[i];
	for(int i = la - lb;i >= 0;--i){
		//�����̵ĵ�iλ
		while(greater_eq(d,b,i,lb)){
			//�߾��ȼ���
			//�����Լ�ȥһ����������ô��
			for(int j = 0;j < lb;++j){
				d[i + j] -= b[j];
				if(d[i + j] < 0) {
					d[i + j + 1] -= 1;
					d[i + j] += 10;;
				}
			}
			c[i] += 1;//�̵Ĵ�λ��1
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

