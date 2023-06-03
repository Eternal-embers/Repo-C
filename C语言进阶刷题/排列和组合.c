#include<stdio.h>
long long arg(int m,int n){
	long long arg_m_n = 1;
	int i;
	for(i = n-m+1;i <= n;i++)
		arg_m_n *= i;
	return arg_m_n;
}//arrangeÅÅÁÐ
long long cmb(int m,int n){
	return arg(m,n)/arg(m,m);
}//combine×éºÏ
int main(){
	return 0;
}
