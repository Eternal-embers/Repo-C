/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/31 22:55
	Description: FBI树
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char type;
	struct Node *left;
	struct Node *right;
};
char *s;

char getType(char *p){
	int sum = 0;
	int i,len = strlen(p);
	for(i = 0;i < len;i++)
		sum += (p[i] - '0');
	if(sum == 0) return 'B';
	else if(sum == len) return 'I';
	else return 'F';
}

char *subString(char *str,int start,int end){
	int i,j;
	char *s = (char *)malloc(sizeof(char) * (end - start + 1));
	for(i = 0,j = start;i < end - start;i++,j++)
		s[i] = str[j];
	s[i] = '\0';
	return s;
}

/*
	在FBI树中，只有没有叶节点才会存放0、1的字符，其他的根节点不存放0、1
	为了方便输出，我们设置任何一个节点的ch存放以该节点为根节点的串类型
 */
void createTree(struct Node **T,char *s){
	int len = strlen(s);
	if(len > 1){
		(*T) = (struct Node *)malloc(sizeof(struct Node));
		(*T)->type = getType(s);
		/* 将串平分给左右子树 */
		char *sub1 = subString(s,0,len / 2);
		char *sub2 = subString(s,len / 2,len);
		free(s);//释放s字符串的空间
		createTree(&(*T)->left,sub1);
		createTree(&(*T)->right,sub2);
	}
	else {
		(*T) = (struct Node *)malloc(sizeof(struct Node));
		(*T)->left = NULL;
		(*T)->right = NULL;
		(*T)->type = getType(s);
		return;
	}
}

void postTraverse(struct Node *T){
	if(T){
  		postTraverse(T->left);
  		postTraverse(T->right);
		printf("%c",T->type);
	}
}

int main(){
	s = (char *)malloc(sizeof(char) * 1050);
	int N;
	scanf("%d",&N);
	scanf("%s",s);
 	struct Node *T;
	createTree(&T,s);
	postTraverse(T);
	return 0;
}

