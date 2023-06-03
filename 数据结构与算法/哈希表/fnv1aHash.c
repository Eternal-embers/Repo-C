/*
	FNV-1a 哈希：
	FNV-1a（Fowler-Noll-Vo哈希函数的一种变体）是一个快速且分布良好的哈希函数。
	它通过将哈希值与一个较大的质数（例如，16777619）相乘，并与当前字符的ASCII码异或，生成最终哈希值。
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

int fnv1aHash(char *str){
	const FNV_PRIME = 0x01000193;
	const FNV_OFFSET = 0x811c9dc5;
	int hash = FNV_OFFSET;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash ^= str[i];
		hash *= FNV_PRIME;
	}
	return hash;
}

int main(){
	printf("%x\n",fnv1aHash("aaa"));
	printf("%x\n",fnv1aHash("abc"));
	printf("%x\n",fnv1aHash("zzz"));
	printf("%x\n",fnv1aHash("day"));
	return 0;
}

