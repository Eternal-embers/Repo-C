#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
typedef struct TreeNode{
	int value;//权值
	int parent;
	int lchild;
	int rchild;
}TreeNode;

typedef struct HFTree{
	TreeNode *node;//用顺序表存储二叉树的所有结点
	int length;//记录结点个数
}HFTree;

HFTree *initHFTree(int *weight,int length){
	HFTree *T = (HFTree *)malloc(sizeof(HFTree));
	T->node = (TreeNode *)malloc(sizeof(TreeNode) * (2 * length - 1));//length个权值能构造一棵结点树为2*length-1的哈夫曼树
	int i;
	for(i = 0;i < length;i++){
		T->node[i].value = weight[i];
		T->node[i].parent = -1;//未参与组成哈夫曼树的结点的parent初始化为-1
		T->node[i].lchild = -1;//空的左孩子为-1
		T->node[i].rchild = -1;//空的右孩子为-1
	}
	T->length = length;
	return T;
}

int *selectMin(HFTree *T){
	int firstMin;
	int secondMin;
	int firstMinValue = INF;
	int secondMinValue = INF;
	int i;
	for(i = 0;i < T->length;i++){
		if(T->node[i].parent == -1){//如果还没有参与组成哈夫曼树
			if(T->node[i].value < firstMinValue) {
				firstMin = i;
				firstMinValue = T->node[i].value;
			}
		}
	}
	for(i = 0;i < T->length;i++){
		if(T->node[i].parent == -1){//如果还没有参与组成哈夫曼树
			if(T->node[i].value < secondMinValue && i != firstMin){
				secondMin = i;
				secondMinValue = T->node[i].value;
			}
		}
	}
	int *res = (int *)malloc(sizeof(int)*2);
	res[0] = firstMin;
	res[1] = secondMin;
	return res;
}

void createHFTree(HFTree *T){
	int i;
	int *res;
	int length = T->length * 2 - 1;
	for(i = T->length;i < length;i++){
		res = selectMin(T);
		T->node[T->length].value = T->node[res[0]].value + T->node[res[1]].value;
		T->node[T->length].lchild = res[0];
		T->node[T->length].rchild = res[1];
		T->node[T->length].parent = -1;
		T->node[res[0]].parent = T->length;
		T->node[res[1]].parent = T->length;
		T->length++;
	}
}

void preOrder(HFTree *T,int index){
	if(index != -1){
		printf("%d ",T->node[index].value);
		preOrder(T,T->node[index].lchild);
		preOrder(T,T->node[index].rchild);
	}
}

int main(){
	int weight[10] = {4,2,9,11,7,5,6,4,0,10};
	HFTree *T = initHFTree(weight,10);
	createHFTree(T);
	preOrder(T,T->length - 1);
	printf("\n");
	return 0;
}
