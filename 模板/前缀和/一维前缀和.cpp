#include<iostream>

using namespace std;

const int N = 100000;

int s[N];

//����ǰ׺������
s[i] = s[i - 1] + a[i];

//����a[i]��a[j]֮���������ĺ�
sum = s[j] - s[i - 1];
