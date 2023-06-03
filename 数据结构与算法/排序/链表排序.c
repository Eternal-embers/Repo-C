#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
int n=0;
Node* createlist(void)
{
 Node *p1,*p2,*head;
 p1=(Node*)malloc(sizeof(Node));
 scanf("%d",&p1->data);
 while(p1->data!=-1)
 {
  n++;
  if(n==1)head=p1;
  else p2->next=p1;
  p2=p1;
  scanf("%d",&p1->data);
 }
 return head;
}
void printlist(Node *list)
{
  while(list)
  {
  	printf("%d",list->data);
  	list=list->next;
  }
}
Node *send(Node *list,int i)
{
	int i;
	for(i=0;i<n;i++)
	list=list->next;
	return list;
}
void sort(Node *head)
{
	Node *p1,*p2,*left,*temp;
	int i,j;
	for(i=0;i<n;i++)
	for(j=n-i-1;j>=0;j++)
	{
	p1=send(j);
	p2=send(j-1);
	if(n==1)
	{
	p2->next=p1->next;
	p1->next=p2;
	}
	else{
	left=send(j-2)
	if(p1->data<p2->data){
	p2->next=p1->next;
	p1->next=p2;
	left->next=p1;
    }
 }
}
int main()
{
	
}
