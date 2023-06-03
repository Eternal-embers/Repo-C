#include<stdio.h>
#include<stdlib.h>
#include "_LeftHeap_H.h"

struct TreeNode{
	int data;
	struct TreeNode *left;//左堆
	struct TreeNode *right;//右堆
	int Npl;//零路径长
};

int findMin(priorityQueue *H){
	return H->data;
}

/* 合并左式堆的驱动例程 */
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2){
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	if(H1->data > H2->data)//将H1转换成根植小的那个
	    return merge1(H2,H1);
	else
		return merge1(H1,H2);
}

/* 合并左式堆的实际例程 */
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2)//H1的根值小于H2的根植
{
	if(H1->left == NULL)//单节点
		H1->left = H2;//H1->right也为空，H1->Npl为0
	else {
		/* 将H1的右子堆和H2合并并成为H1根节点的右孩子 */
		H1->right = merge(H1->right,H2);
		if(H1->left->Npl < H1->right->Npl){
			struct TreeNode *node = H1->left;
			H1->left = H1->right;
			H1->right = node;
		}
		H1->Npl = H1->right->Npl + 1;//新的零路径长是新的右儿子的零路径长加1
	}
	return H1;
}

priorityQueue *insert(int data,priorityQueue *H){
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->data = data;
	node->Npl = 0;
	node->left = node->right = NULL;
	H = merge(node,H);
	return H;
}

priorityQueue *deleteMin(priorityQueue *H){
	if(H != NULL){
		priorityQueue *leftHeap,*rightHeap;
		leftHeap = H->left;
		rightHeap = H->right;
		free(H);
		return merge(leftHeap,rightHeap);
	}
}

void traverseHeap(priorityQueue *H){
	if(H == NULL) return;
	else {
		printf("%d ",H->data);
		if(H->left) traverseHeap(H->left);
		if(H->right) traverseHeap(H->right);
	}
}

int main(){
	//int arr[10] = {12,34,8,29,57,88,21,70,36,96};
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
 	priorityQueue *H = NULL;
	int i;
	for(i = 0;i < 15;i++){
		H = insert(arr[i],H);
	}
	traverseHeap(H);
	return 0;
}

