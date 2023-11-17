#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;//���� 
	struct TreeNode *rchild;//�Һ��� 
}TreeNode;
 
typedef struct stackNode{
	TreeNode *data;//�������ĳ����� 
	struct stackNode *next;//ָ��ջ����һ�ڵ� 
}stackNode;

stackNode *initStack(void){
	stackNode *S = (stackNode *)malloc(sizeof(stackNode));//Ϊջ��ͷ�����ٿռ�,�˿ռ䲻�������
	S->data = NULL;
	S->next = NULL;
	return S;
}

//������ѹջ
void push(TreeNode *T,stackNode *S){
	stackNode *node = (stackNode *)malloc(sizeof(stackNode));//Ϊջ�ڵ㿪�ٿռ�
	//ͷ�巨
	node->data = T;//�Ƚ����ݷ���ջ�ڵ����������
	node->next =  S->next;//��ջ�ڵ�ָ��ջͷ�ڵ�ָ�����һ�ڵ�
	S->next = node;//ջ��ͷ�ڵ��nextָ��ָ�����Ľڵ�
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(stackNode *S){
	if(S->next == NULL)return 1;//���ջ��ͷ�ڵ�����һ�ڵ㣬ջΪ��
	else return 0;
}

//��ջ
stackNode *pop(stackNode *S){
	if(isEmpty(S))return NULL;//���Ϊ�գ����ؿ�ָ��
	else {
		stackNode *node = S->next;//ջָ��ָ��ͷ�ڵ����һ�ڵ�
		S->next = node->next;//ͷ�ڵ��nextָ��ָ����һ�ڵ����һ�ڵ�
		return node;//���س�ջ���Ǹ��ڵ�
	}
}

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index+=1;//ָ���ַ�����ָ��������һ 
	if(ch == '#')*T = NULL;//����ַ�Ϊ#�����ָ��NULL 
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));//Ϊ����ĳ����㿪�ٿռ� 
		(*T)->data = ch;//�����ݷ����������� 
		createTree(&(*T)->lchild,data,index);//�ݹ鴴�������� 
		createTree(&(*T)->rchild,data,index);//�ݹ鴴�������� 
	}
}

//�������ķǵݹ������������ѹջ����ѭ������ڵ�Ϊ��;
//����ÿ��һ��ջ���ж��ҽڵ��Ƿ�Ϊ�գ������Ϊ�գ�ѹջ�ҽڵ� 
void preOrder(TreeNode *T){
	TreeNode *node = T;
	stackNode *S = initStack();//��ȡջ��ͷ�ڵ�
	//�����ڵ㲻Ϊ�գ�����ջ��Ϊ��ʱ���������� 
	while(node || !isEmpty(S)) {
		//���ڵ㲻Ϊ�� 
		if(node){
			printf("%c ",node->data);//��ӡ���ڵ���������д�ŵ����� 
			push(node,S);//����ʱ�����ڵ�ѹջ 
			node = node->lchild;//ָ������ָ��ָ���ʱ������һ�������ĸ��ڵ� 
		}
		//���ڵ�Ϊ�� 
		else{
			node = pop(S)->data;//����ָ��ָ���ջ���Ǹ�ջ�ڵ��������ָ������ڵ� 
			node = node ->rchild;//����ָ��ָ������ڵ�������� 
		}
	}
}

//�������ķǵݹ�����������Ƚ�������ѹջ����ָ���������Ϊ�գ���ջ 
//ÿ��һ��ջ��ӡ�ó�ջ�ڵ�����ݣ�������ڵ��ƶ��Ĺ����з��ʾ�����ÿһ���ڵ�������� 
void inOrder(TreeNode *T){
	TreeNode *node = T;//�������ĸ��ڵ� 
	stackNode *S = initStack();//��ȡջ��ͷ�ڵ�
	//��ָֻ������ڵ㲻Ϊ�ջ�ջΪ��Ϊ��ʱ���������� 
	while(node || !isEmpty(S)){
		//�����ʱָ������ڵ㲻Ϊ�� 
		if(node){
			push(node,S);//����ʱ�����ڵ�ѹ��ջ�� 
			node = node->lchild;//ָ���ʱ���������ĸ��ڵ� 
		}
		//�����ʱָ������ڵ�Ϊ�գ���ջ 
		else{
			node = pop(S)->data;//��ջ������ָ��ָ���ջ�Ǹ��ڵ�������ָ������ڵ� 
			printf("%c ",node->data);//����ջ���Ǹ��ڵ�ĵ����ݴ�ӡ 
			node = node->rchild;//ָ���ʱ���ڵ�������� 
		}
	}
}

int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);//���������� 
	preOrder(T);//���������������
	printf("\n");
	inOrder(T);//��������������� 
	return 0;
}
