#include<iostream>

using namespace std;

void quick_sort(int q[],int l,int r){
	if(l >= r) return;
	
	int x = q[l],i = l - 1,j = r + 1;//x还可以取q[l + r >> 2]，不能取q[r]
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}
	
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

//遍历q数组的不同写法
void quick_sort(int q[],int l,int r){
	if(l >= r) return;

	int x = q[l],i = l - 1,j = r + 1;//x还可以取q[l + r >> 2]，不能取q[r]
	while(i < j){
		do i++; while(q[i] < x);
		do --j; while(q[j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

//取 i 为边界点的写法
void quick_sort(int q[],int l,int r){
	if(l >= r) return;

	int x = q[r],i = l - 1,j = r + 1;//x还可以取q[l + r >> 2]，不能取q[l]
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	quick_sort(q, l, i - 1);
	quick_sort(q, i, r);
}




