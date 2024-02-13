#include<iostream>
#include<string.h>

using namespace std;

const int N = 1000005;

char s[N], p[N], ne[N];

int n = strlen(p);
int m = strlen(s);

for(int i = 2, j = 0; i <= n;i++){
	while(j && p[i] != p[j + 1]) j = ne[j];
	if(p[i] == p[j + 1]) j++;
	ne[i] = j;
}

for(int i = 1, j = 0;i <= m;i++){
	while(j && s[i] != p[j + 1]) j = ne[j];
	if(s[i] == p[j + 1]) j++;
	if(j == n){
		printf("%d ", i - n);
		j = ne[j];
	}
}
