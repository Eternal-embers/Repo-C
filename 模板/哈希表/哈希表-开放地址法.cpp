#include<iostream>

using namespace std;

const int N = 200005, null = 0x3f3f3f3f;

int find(int x){
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x){
		k++;
		if(k == N) k = 0;
	}
	
	return k;
}

//���� x
h[find(x)] = x;

//��ѯ x
h[find(x)]
