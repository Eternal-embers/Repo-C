#include<stdio.h>

int a[200005] = {0};
int res[200005] = {0};
int del[100000] = {0};
int len1 = 0,len2 = 0;
int n;

int main(){
	int i,j,k,out;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < n;i++){
		int flag = 0;
		out = -5;
		for(j = 0;j < len;j++){ //判断加入a[i]是否合法
			if( !(a[i] == a[res[j]]) && !(i + 1 < n && a[i + 1] == a[res[j + 1]]) ){
				out = res[j];//记录造成不合法的索引
				for(k = 0;k < len2;k++){//判断是否在删除序列中
					if(del[k] == out) {
						flag = 1;
						break;
					}
				}
				if(!flag) break;
			}
		}
		if(out == i - 1){//如果是当前检查的索引前一个元素造成的不合法，尝试删除该元素
			del[len2] = out;
			len2++;
		}
		if(j >= len) {
			res[len] = i;
			len++;
		}
  		else {
			if(j - res[len - 1] >= 2){
				len = 0;
				break;//出现间隔不合法
			}
		}
	}
	if(len > 0){
		printf("%d\n",len);
		for(i = 0;i < len;i++){
			printf("%d ",res[i] + 1);
		}
	}
	else
		printf("NO");
	return 0;
}

