/*
 	Bernstein的算法:此算法通过取模减少碰撞,使用33这个质数可以得到比较均匀的散列值,但取模运算降低了性能。
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

int Bernstein_Hash(char *str,int table_size){
	int hash = 0;
	int length = getLength(str);
	int i;
	for(i = 0;i < length;i++){
		hash = 33 * hash + str[i];
	}
	hash %= table_size;
	return hash;
}

int main(){
	printf("%d\n",Bernstein_Hash("birthday",1000));
	printf("%d\n",Bernstein_Hash("usually",1000));
	printf("%d\n",Bernstein_Hash("Titan",1000));
	return 0;
}

