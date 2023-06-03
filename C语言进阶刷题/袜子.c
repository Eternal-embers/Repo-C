#include<stdio.h>
#define INF 0x7fffffff//int最大值的十六进制表示

int main(){
	int T,i,j;
	scanf("%d",&T);
	int N,res[T];
	for(i = 0;i < T;i++){
		scanf("%d",&N);
 		int a[N];
  		for(j = 0;j < N;j++){
			scanf("%d",&a[j]);
		}
		int r1 = a[0];
		for(j = 0;j < N;j++){
			if(r1 > a[j]) r2 = a[j];
		}
		r2 = 1000000000;
		for(j = 0;j < N;j++){
			if(r2 > a[j] && a[j] != r1 ) r2 = a[j];
		}
		res[i] = r1 + r2;
	}
	for(i = 0;i < T;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}

