#include<stdio.h>
int main(){
    int w,n,ans;
    scanf("%d%d",&w,&n);
    ans = (w+n) % 7;
    if(ans==0) printf("7");
    else printf("%d",ans);
    return 0;
}
