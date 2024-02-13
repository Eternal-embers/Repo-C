#include<iostream>

using namespace std;

int p[N];//p[i]表示编号为i的数的祖宗节点的编号

//查询,对于祖宗节点有p[x] == x
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);//路径压缩，原操作为while(p[x] != x) x = p[x];
	return p[x];//返回x的祖宗节点的编号
}

//合并
void merge(int a, int b){
	p[find(a)] = find(b);//将b的祖宗节点编号作为a的祖宗节点编号
}
