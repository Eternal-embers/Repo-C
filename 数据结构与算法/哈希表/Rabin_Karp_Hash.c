/*
	Rabin Karp算法: 该算法通过选取两个不同的质数p和m,并引入p的幂进行散列,效果很好,是字符串匹配算法 Rabin Karp 算法的基石,但较为复杂。
*/

#include<stdio.h>

int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

int Rabin_Karip_Hash(char *str){
	int hash = 0;
	const int p = 31;
	const int m = 1e9 + 9;
	int p_pow = 1;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash = ((hash + (str[i] - 'a' + 1)) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash;
}
int main(){
	printf("%d\n",Rabin_Karip_Hash("aaa"));
	printf("%d\n",Rabin_Karip_Hash("happy"));
	printf("%d\n",Rabin_Karip_Hash("blue"));
	printf("%d\n",Rabin_Karip_Hash("car"));
	return 0;
}

