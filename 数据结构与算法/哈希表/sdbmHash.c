/*
	SDBM 哈希：
	SDBM（由Sleepycat DBM系统使用）哈希函数与DJB2类似，但采用不同的公式。
	SDBM哈希在每次迭代时将哈希值乘以65599（2^16 + 2^6 - 1），然后将当前字符的ASCII码加到哈希值上。
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

int sdbmHash(char *str){
	int hash = 0;
	int i;
	int length = getLength(str);
	for(i = 0;i < length;i++){
		hash = str[i] + (hash << 6) + (hash << 16) - hash;//str[i] + hash * 65599,65599 = 2^16 + 2^6 - 1
	}
	return hash;
}

int main(){
	printf("%d\n",sdbmHash("abc"));
	printf("%d\n",sdbmHash("cde"));
	printf("%d\n",sdbmHash("zzz"));
	printf("%d\n",sdbmHash("mbmb"));
	return 0;
}

