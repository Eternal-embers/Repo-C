/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/31 22:55
	Description: FBI��
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
	��FBI���У�ֻ��û��Ҷ�ڵ�Ż���0��1���ַ��������ĸ��ڵ㲻���0��1
	Ϊ�˷�����������������κ�һ���ڵ��ch����Ըýڵ�Ϊ���ڵ�Ĵ�����
 */
void createTree(struct Node **T,char *s){
	int len = strlen(s);
	if(len > 1){
		(*T) = (struct Node *)malloc(sizeof(struct Node));
		(*T)->type = getType(s);
		/* ����ƽ�ָ��������� */
		char *sub1 = subString(s,0,len / 2);
		char *sub2 = subString(s,len / 2,len);
		free(s);//�ͷ�s�ַ����Ŀռ�
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

