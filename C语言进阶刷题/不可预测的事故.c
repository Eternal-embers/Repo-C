#include<stdio.h>
int n;
void f(int *p1,int *p2,int x){
	int cnt = 0;
	int h = 17,m = 0;
	while(1){
		for(m = 0;m < 60;m++){
			if(cnt == x) {
				*p1 = h % 24;
				*p2 = m;
				return;
			}
			cnt++;
		}
		h++;
	}
}

int main(){
	scanf("%d",&n);
	int h[n],m[n],x[n],i;
	for(i = 0;i < n;i++){
		scanf("%d",&x[i]);
	}
	for(i = 0;i < n;i++){
		f(&h[i],&m[i],x[i]);
	}
	for(i = 0;i < n;i++){
		printf("%02d:%02d\n",h[i],m[i]);
	}
	return 0;
}

