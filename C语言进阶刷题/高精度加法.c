/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/23 17:28
	Description: 高精度加法练习
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 104

int a[LEN],b[LEN],c[LEN];

void clear(int a[]){
    int i;
    for(i = 0;i < LEN;i++){
      a[i] = 0;
    }
}

void read(int a[]){
    char s[LEN];
    scanf("%s",s);
    int len = strlen(s);
    int i;
    for(i = 0;i < len;i++){
		a[len - i - 1] = s[i] - '0';
	}
}

void print(int a[]){
	int i;
	for(i = LEN - 1;i > 0;--i){
		if(a[i] != 0) break;
	}
	while(i >= 0){
		putchar(a[i--] + '0');
	}
}

void add(int a[],int b[]){
	clear(c);
	int i;
	for(i = 0;i < LEN;i++){
		c[i] += a[i] + b[i];
		if(c[i] >= 10){
			c[i + 1] += 1;
			c[i] -= 10;
		}
	}
}

int main(int argc, char *argv[])
{
  read(a);
  read(b);
  add(a,b);
  print(c);
  return 0;
}

