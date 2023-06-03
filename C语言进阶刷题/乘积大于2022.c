#include<stdio.h>
int main(){
	int arr[30] = { 99, 22, 51, 63, 72, 61, 20, 88, 40, 21,
	 			    63, 30, 11, 18, 99, 12, 93, 16, 7, 53,
	  			    64, 9, 28, 84, 34, 96, 52, 82, 51, 77 };
	int i,j,ans;
	for(i = 0;i < 30;i++)
		for(j = 0;j < 30;j++)
			if(i!=j && arr[i]*arr[j]>=2022) ans++;
	printf("%d",ans);
	return 0;
}
