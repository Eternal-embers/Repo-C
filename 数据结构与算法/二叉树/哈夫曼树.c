#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff//int最大值的十六进制表示
typedef struct TreeNode{
	int weight;//权重
	int parent;//父节点
	int lchild;//左孩子
	int rchild;//右孩子
}TreeNode;

typedef struct HFTree{
	TreeNode *data;//用一个顺序的二叉树的结构体数组来存储哈夫曼树
	int length;//记录哈夫曼树中的节点数量
}HFTree;

HFTree* initTree(int *weight,int length){
	HFTree* T = (HFTree *)malloc(sizeof(HFTree));//创建一棵哈夫曼树
	T->data = (TreeNode *)malloc(sizeof(TreeNode) * (2 * length - 1));//开辟数据的空间
	T->length = length;
	int i;
	for(i = 0;i < length;i++){
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	return T;
}

int *selectMin(HFTree* T){
	int min = INF;
	int secondMin = INF;
	int minIndex;
	int secondIndex;
	int i;
	for(i = 0;i < T->length;i++){
		if(T->data[i].parent == 0) {//如果是还未用来组建哈夫曼树的节点
			if(T->data[i].weight < min){
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for(i = 0;i < T->length;i++){
		if(T->data[i].parent == 0 && i != minIndex) {//如果是还未用来组建哈夫曼树的节点
			if(T->data[i].weight < secondMin){
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int *res = (int *)malloc(sizeof(int) * 2);//用一个数组来返回两个权值最小的下标
	res[0] = minIndex;
	res[1] = secondIndex;
    return res;
}

void createHFTree(HFTree *T){
	int *res;
	int min;
	int secondMin;
	int length = T->length * 2 - 1;//如果权值列表有length个元素，那么最终的哈夫曼树有2*length - 1个节点
	int i;
	for(i = T->length;i < length;i++){
		res = selectMin(T);
		min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		T->data[i].parent = 0;
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		T->length++;//节点树加一,每次产生的新的节点放在T->data[T->length]处
	}
}

void preOrder(HFTree *T,int index){
	if(index != -1){
		printf("%d ",T->data[index].weight);
		preOrder(T,T->data[index].lchild);
		preOrder(T,T->data[index].rchild);
	}
}
int main(){
	int weight[7] = {5,9,2,7,6,4,10};
	HFTree *T = initTree(weight,7);
	createHFTree(T);
	preOrder(T,T->length - 1);
	printf("\n");
	return 0;
}

