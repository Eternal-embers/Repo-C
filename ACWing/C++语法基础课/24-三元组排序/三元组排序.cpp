#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef struct group{
	int x;
	double y;
	string z;
}group;

int n;
group a[10000];

bool cmp(group g1,group g2){
	return g1.x < g2.x;
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i].x >> a[i].y >> a[i].z;

	sort(a,a + n,cmp);

	for(int i = 0;i < n;i++)
		printf("%d %.2f %s\n",a[i].x,a[i].y,a[i].z.c_str());
	return 0;
}
