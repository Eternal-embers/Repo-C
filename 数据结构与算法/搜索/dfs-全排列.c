#include<stdio.h>
int ans = 0;
_Bool used[9] = {0,0,0,0,0,0,0,0,0};
void dfs(int deep) {
	if(deep == 9){
		++ans;
		return;
	}
	int i;
	for(i = 0;i != 9;++i){
		if(!used[i]) {
			used[i] = 1;
			++deep;
			dfs(deep);
			/* »Ö¸´ÏÖ³¡ */
			used[i] = 0;//»ØËİ
			--deep;
		}
	}
}
int main(){
	dfs(1);
    printf("%d",ans);
	return 0;
}

