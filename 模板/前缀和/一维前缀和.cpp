#include<iostream>

using namespace std;

const int N = 100000;

int s[N];

//计算前缀和数组
s[i] = s[i - 1] + a[i];

//计算a[i]到a[j]之间所有数的和
sum = s[j] - s[i - 1];
