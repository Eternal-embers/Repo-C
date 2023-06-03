/*
	左式堆，递归定义，其结构与二叉树类似，但是左式堆是不平衡的二叉树
	Npl(左) >= Npl(右)
	两个单节点左式堆合并可以得到左式堆，依次类推，可以通过递归的合并得到左式堆
    因此合并左式堆也是递归定义，
	如何合并两个左式堆？
    先将其中根植较小的左式堆的右子堆和根植较大的左式堆合并得到新的左式堆，
	再将这个左式堆和原先那个根植较小的左式堆的左子堆合并
	合并得到的左式堆如果Npl(左) < Npl(右)，那么交换左右子堆
 */
#include<stdio.h>
#include<stdlib.h>
#include "leftHeap_H.h"

struct TreeNode{
	int data;
	int Npl;//零路径长
	struct TreeNode *left;//左子堆
	struct TreeNode *right;//右子堆
};

void traverseQueue(priorityQueue *Q,priorityQueue *father,int flag){
	if(father)	printf("%d(%d_%s) Npl:%d\n",Q->data,father->data,flag ? "左" : "右",Q->Npl);
	else printf("%d(null) Npl:%d\n",Q->data,Q->Npl);
 	if(Q->left)
		traverseQueue(Q->left,Q,1);
	if(Q->right)
		traverseQueue(Q->right,Q,0);
}

priorityQueue *initHeap(int data){
	Heap *H = (Heap *)malloc(sizeof(Heap));
	H->data = data;
	H->Npl = 0;
	H->left = NULL;
	H->right = NULL;
	return H;
}

/* 合并H1和H2的驱动例程 */
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2){
	/* 递归终止条件 */
    if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	/* 继续递归合并 */
	if(H1->data > H2->data)//将H1转换成根植小的那个
	    return merge1(H2,H1);
	else
		return merge1(H1,H2);
}

/* 在此函数中，H1的根植小于H2 */
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2){
	/* 合并终止条件 */
	if(H1->left == NULL)//H1为单节点
		H1->left = H2;
	/* 继续递归合并 */
    else{
		H1->right = merge(H1->right,H2);
		if(H1->left->Npl < H1->right->Npl){
			/* 交换左右子堆 */
			Heap *H = H1->left;
			H1->left = H1->right;
			H1->right = H;
		}
		H1->Npl = H1->right->Npl + 1;//更新Npl
	}
	return H1;
}

priorityQueue *insert(int data,priorityQueue *H){
	return merge(initHeap(data),H);
}

priorityQueue *deleteMin(priorityQueue *H){
 	priorityQueue *left,*right;
 	left = H->left;
 	right = H->right;
 	free(H);
	return merge(left,right);
}

int main(){
	//int arr[10] = {12,34,8,29,57,88,21,70,36,96};
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	printf("创建左式堆：\n");
 	priorityQueue *H = NULL;
	int i;
	for(i = 0;i < 15;i++){
		H = insert(arr[i],H);
	}
	traverseQueue(H,NULL,1);
	printf("删除最小元：\n");
	H = deleteMin(H);
	traverseQueue(H,NULL,1);
	return 0;
}

