/*
	Name:B-树
	Copyright:劣等生
	Author:劣等生
	Date: 09/10 19:52
	Description:
*/
#include<stdio.h>
#define KeyType int
#define m 3
typedef struct BTNode{
	int keynum;//节点中关键字的个数，即节点的大小
	struct BTNode *parent;//指向双亲节点
	KeyType k[m];//关键字向量
	struct BTNode *ptr[m];//子树指针向量
}BTNode,*BTree;//B-树节点和B-树的类型

typedef struct{
	BTNode *pt;//找到的节点
	int i;//1~m，在节点中的关键字序号
	int tag;//B-树的查找结果类型
}Result;//B-树的查找结果类型

Result *createResult(BTNode *pt,int i,int tag){
	Result res = (Result *)malloc(sizeof(Result));
	res->i = i;
	res->pt = p;
	res->tag = tag;
}

Result *SearchBTree(BTree T,KeyType key){
	//在m阶B-树T上查找关键字key，返回结果(pt,i,tag)
	//若查找成功，则特征值tag = 1，指针pt指向节点中第i个关键字等于key
	//否则特征值tag = 0，等于key的关键字应插入在指针pt所值节点的第i个和第i + 1个关键字之间
	BTNode *p = T;//p指向待差节点
	BTree q = NULL;//q指向p的双亲
	int found = 0;//判断是否查找到key
    int i = 0;
    while(p && !found){
    	i = search(p,key);//在0~keynum中查找i,使得p->k[i] <= key < p->k[i + 1]
    	if(i > 0 && p->k[i] == key) found = 1;//找到关键字
    	else{
    		q = p;
    		p = p->ptr[i];
		}
	}
	return createResult(q,i,found);//返回查找结果，如果查找不成功返回的是key的插入位置信息
}
int main(){

	return 0;
}

