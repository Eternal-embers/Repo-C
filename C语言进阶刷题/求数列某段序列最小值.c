#include<stdio.h>
int main(){
    int n,i,j,k,min,max;
    scanf("%d",&n);
    int a[n+1],ans[n+1];
	for(i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(i = 1;i <= n;i++){
        if(i-k < 1) min = 1;
            else min = i-k;
        if(i+k > n) max = n;
            else max = i+k;
        ans[i] = a[i];
        for(j = min;j <= max; j++)
            if(ans[i] > a[j]) ans[i] = a[j];
    }
    for(i = 1; i <= n;i++)
        printf("%d ",ans[i]);
    return 0;
}
