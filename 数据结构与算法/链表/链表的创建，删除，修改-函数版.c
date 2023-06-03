#include<stdio.h>
#include<stdlib.h>
#define size sizeof(struct list)
struct list
{
	int data;
	struct list*next;
};
int n=0;
struct list* create(void)
{
    struct list *head,*p1,*p2;
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
	printf("链表生成成功\n");
	return head;
}

void print(struct list* pt)
{
	printf("打印链表\n");
    while(pt!=NULL)
    {
    	printf("%d ",pt->data);
    	pt=pt->next;
	}
	printf("\n");
}

void delet(struct list* d)
{
	struct list *in;
	int i=1,num;
	printf("list-num=");
	scanf("%d",&num);
	while(i<num&&d!=NULL)
	{
		in=d;
		d=d->next;
		i++;
	}
	if(num==n)
	{
		in->next=NULL;
		free(d);
	}
	else if(d!=NULL)
	{
	in->next=d->next;//notice!!!
	free(d);
    }
    else printf("节点不存在\n"); 
}

void change(struct list *cg)
{
	int i=1,num; 
	printf("list-num=");
	scanf("%d",&num);
	while(i<num&&cg!=NULL)
	{
		cg=cg->next;
		i++;
	}
	if(cg!=NULL)
	{
	printf("%d---->",cg->data);
	scanf("%d",&cg->data);
    }
    else printf("节点不存在\n"); 
}
int main()
{
	struct list *h;
	h=create();
	print(h);
	delet(h);
	print(h);
	change(h);
	print(h);
    return 0;
}
