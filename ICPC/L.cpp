#include<stdio.h>
#include<string.h>

char s[5005];

int main(){
	int i,j,t,T;
	scanf("%d",&T);
	int res[T];
	for(t = 0;t < T;i++){
		scanf("%s",s);
		int len = strlen(s);
		for(i = 0;i < len - 1;i++){
			for(j = i + 1;j < len;j++){
				int left = i;
				int right = j;
				while(left < right){
					if(s[left] != s[right])
						break;
					left++;
					right--;
				}
				if(left == right) res[i]++;
			}
		}
	}
	for(i = 0;i < T;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}

