/*
	Bernstein的算法:此算法简单高效,碰撞概率较低,是C++ std::string的默认散列算法
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

int Bernstein_Hash(char *str,table_size){
	int hash = 0;
	int length = getLength(str);
	for(i = 0;i < length;i++){
		hash = 33 * hash + str[i];
	}
	hash %= table_size;
	return hash;
}

int main(){
	printf("%d\n",Bernstein_Hash("abcd",1000));
	return 0;
}

