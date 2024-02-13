#include<iostream>

using namespace std;

const int N = 100005;

//head为头节点的索引，idx为下一个插入点的索引
int head, idx;

//e[] 存储节点的值， ne[] 存储节点的next指针
int e[N], ne[N];

//初始化
void init(){
    head = -1;
    idx = 0;
}

//将 x 插入到头节点的后面
void add_to_head(int x){
	e[idx] = x, ne[idx] = ne[head], ne[head] = idx++;
}

//将 x 插入到第 k 个插入的节点的后面
void add(int k, int x){
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

//将第 k 个插入的节点的后面的节点删除
void remove(int k){
	ne[k] = ne[ne[k]];
}

