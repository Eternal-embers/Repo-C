#include<iostream>

using namespace std;

void quick_sort(int q[],int l,int r){
	if(l >= r) return;
	
	int x = q[l],i = l - 1,j = r + 1;//x������ȡq[l + r >> 2]������ȡq[r]
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}
	
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

//����q����Ĳ�ͬд��
void quick_sort(int q[],int l,int r){
	if(l >= r) return;

	int x = q[l],i = l - 1,j = r + 1;//x������ȡq[l + r >> 2]������ȡq[r]
	while(i < j){
		do i++; while(q[i] < x);
		do --j; while(q[j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

//ȡ i Ϊ�߽���д��
void quick_sort(int q[],int l,int r){
	if(l >= r) return;

	int x = q[r],i = l - 1,j = r + 1;//x������ȡq[l + r >> 2]������ȡq[l]
	while(i < j){
		while(q[++i] < x);
		while(q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}

	quick_sort(q, l, i - 1);
	quick_sort(q, i, r);
}




