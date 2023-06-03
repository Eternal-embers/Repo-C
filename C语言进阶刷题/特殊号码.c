#include<stdio.h>
#include<math.h>
int main(){
	int L,R,i,j,t,cnt = 0;
	scanf("%d%d",&L,&R);
	for(i = L;i <= R;i++){
		t = sqrt(i);
		for(j = 2;j <= t;j++) {
			if(i % j == 0) break;
		}
		if(j > t) cnt++;
	}
	
	printf("%d",cnt);
	return 0;
}

