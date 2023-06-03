#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node*next;
}Node;
Node* initlist(void)
{
	Node *list=(Node*)malloc(sizeof(Node));
	list->data=0;
	list->next=NULL;
	return list;
}
void headinsert(Node *list,int data)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=list->next;
	list->next=node;
	list->data++;
}
void tailinsert(Node *list,int data)
{
	Node *head=list;
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	//list=list->next;
	while(list->next)
	{
		list=list->next;
	}
	list->next=node;
	head->data++;
}
void deletelist(Node *list,int data)
{
	Node *pre=list;
	Node *current=list->next;
	while(current)
	{
		if(current->data==data){
		pre->next=current->next;
		free(current);
		break;
	    }
	    pre=current;
	    current=current->next;
	}
	list->data--;
}
void printlist(Node* list)
{
	if(list->next==NULL) {
		printf("Á´±íÎª¿Õ!\n");
		return;
	}
	list=list->next;
	while(list)
	{
		printf("%d ",list->data);
		list=list->next;
	}
	printf("\n");
}
int main()
{
	Node *list=initlist();
	headinsert(list,1);
	headinsert(list,2);
	headinsert(list,3);
	headinsert(list,4);
	tailinsert(list,5);
	tailinsert(list,6);
	tailinsert(list,7);
	tailinsert(list,8);
    printlist(list);
    deletelist(list,3);
    deletelist(list,8);
    printlist(list);
    return 0;
	}
