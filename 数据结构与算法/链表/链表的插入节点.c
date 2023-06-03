#include<stdio.h>
#include<stdlib.h>
#define size sizeof(TYPE)
#define TYPE struct list
TYPE
{
	int data;
	TYPE*next;
};
int n=0;
TYPE* create(void)
{
    TYPE *head,*p1,*p2;
	if((p1=(TYPE*)malloc(size))==NULL)printf("创建链表失败");
	printf("请输入数据：\n");
    scanf("%d",&p1->data);
    while(p1->data!=0)
	{
		n++;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		if((p1=(TYPE*)malloc(size))==NULL)printf("创建链表失败");
		scanf("%d",&p1->data);
	}
	p2->next=NULL;
	printf("链表生成成功\n");
	return head;
}

void print(TYPE* pt)
{
	printf("打印链表\n");
    while(pt!=NULL)
    {
    	printf("%d ",pt->data);
    	pt=pt->next;
	}
	printf("\n");
}

void insert(TYPE *it)
{
	int i=1,num;
	TYPE *ip;
	printf("在第num项后插入节点，num=");
	scanf("%d",&num);
	while(i<num&&it!=NULL)
	{
	it=it->next;
	i++;
	}
    if((ip=(TYPE *)malloc(size))==NULL)printf("创建节点成功\n");
    printf("请输入要插入的数据:");
    scanf("%d",&ip->data);
    ip->next=it->next;
	it->next=ip; 
}

int main()
{
	TYPE* head;
	head=create();
	print(head);
	insert(head);
	print(head); 
}
