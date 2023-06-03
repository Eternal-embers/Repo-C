#include<stdio.h>

/*
	DJB2 哈希：
	DJB2（由Daniel J. Bernstein提出）是一个简单且高效的哈希函数，用于将字符串转换为哈希值。
	DJB2哈希算法以一个较大的质数（例如，5381）为初始值，并通过将每个字符的ASCII码与前一个哈希值相乘后累加，生成最终哈希值。
 	此算法简单高效,碰撞概率较低,是C++ std::string的默认散列算法
*/
int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

int djb2Hash(char *str){
	int hash = 5;
	int i;
	int length = getLength(str);
	for(i = 0;i < length;i++){
		hash = ((hash << 5) + hash) + str[i];//hash * 33 + str[i];
	}
	return hash;
}

int main(){
	printf("%d\n",djb2Hash("abc"));
	printf("%d\n",djb2Hash("cdf"));
	printf("%d\n",djb2Hash("zzz"));
	return 0;
}

