/*
	Name: ·���ܺ�
	Copyright:�ӵ���
	Author:�ӵ���
	Date:08/02 09:31
	Description:
	����һ��������������ÿ����㶼�����һ������ֵ��
	�ҳ�·���͵��ڸ�����ֵ��·��������
	·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
	������������ 1000 ���ڵ㣬�ҽڵ���ֵ��Χ�� [-1000000,1000000] ��������
	ʾ����
	root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

    	 10
        /  \
       5   -3
      / \    \
     3   2   11
   	/ \   \
   3  -2   1
   ���� 3���͵��� 8 ��·���У�
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

