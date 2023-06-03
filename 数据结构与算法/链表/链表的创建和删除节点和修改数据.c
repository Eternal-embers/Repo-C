#include<stdio.h>
#include<stdlib.h>
#define size sizeof(struct list)
struct list
{
	int data;
	struct list*next;
};
int n=0;
int main()
{
	struct list *head,*p1,*p2,*p,*in;
	int i=1,num;
	//create
	if((p1=(struct list*)malloc(size))==NULL)printf("创建链表失败");
	printf("请输入数据：\n");
    scanf("%d",&p1->data);
    while(p1->data!=0)
	{
		n++;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		if((p1=(struct list*)malloc(size))==NULL)printf("创建链表失败");
		scanf("%d",&p1->data);
	}
	p2->next=NULL;
    //print
    printf("打印链表\n");
    p=head;
    while(p!=NULL)
    {
    	printf("%d ",p->data);
    	p=p->next;
	}
	printf("\n");
	//delete
	p=head;
	printf("num=");
	scanf("%d",&num);
	while(i<num&&p!=NULL)
	{
		in=p;
		p=p->next;
		i++;
	}
	if(p!=NULL)
	{
	in->next=p->next;//notice!!!
	free(p);
    }
    else printf("节点不存在"); 
	//print
    printf("打印链表\n");
    p=head;
    while(p!=NULL)
    {
    	printf("%d ",p->data);
    	p=p->next;
	}
	printf("\n");
	//change
	p=head;
	i=1;
	printf("num=");
	scanf("%d",&num);
	while(i<num&&p!=NULL)
	{
		p=p->next;
		i++;
	}
	if(p!=NULL)
	{
	printf("%d---->",p->data);
	scanf("%d",&p->data);
    }
    else printf("节点不存在"); 
    //print
    printf("打印链表\n");
    p=head;
    while(p!=NULL)
    {
    	printf("%d ",p->data);
    	p=p->next;
	}
	printf("\n");
    return 0;
}
