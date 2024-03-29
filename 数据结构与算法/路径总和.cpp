/*
	Name: 路径总和
	Copyright:劣等生
	Author:劣等生
	Date:08/02 09:31
	Description:
	给定一个二叉树，它的每个结点都存放着一个整数值。
	找出路径和等于给定数值的路径总数。
	路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
	二叉树不超过 1000 个节点，且节点数值范围是 [-1000000,1000000] 的整数。
	示例：
	root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

    	 10
        /  \
       5   -3
      / \    \
     3   2   11
   	/ \   \
   3  -2   1
   返回 3。和等于 8 的路径有：
	1.  5 -> 3
	2.  5 -> 2 -> 1
	3. -3 -> 11
*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int val;
	struct Node *left;
	struct Node *right;
};

int pathSum(struct Node *root, int sum) {
  if (root == NULL) return 0;
  return count(root, sum) + pathSum(root->left, sum) +
  pathSum(root->right, sum);
}

int count(struct Node *node, int sum) {
  if (node == NULL) return 0;
  return (node->val == sum) + count(node->left, sum - node->val)
  + count(node->right, sum - node->val);
}

int main(){

	return 0;
}

