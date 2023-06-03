#include <stdio.h>
#include <stdlib.h>
int main(){
    int long long a,b,k,d;
    scanf("%lld %lld",&a,&b);
    if(b>a){
        d=b-a;
        k=d-b%d;
    }
    else{
        d=a-b;
        k=d-a%d;
    }
	//设b>a,由更相减损法得gcd(a+k,b+k) = gcd(b + k,a - b)
	//当k = b - b % (a - b)时为使得b + k为a - b的倍数的最小值
	//此时a+k和b+k的最大约数数即为a - b,使得gcd(a+k,b+k)尽可能的达到最大了，同时k也为最小的可取值
    printf("%lld",k);
}
