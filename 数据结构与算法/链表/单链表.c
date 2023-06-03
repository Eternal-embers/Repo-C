#include <stdio.h>
#include <stdlib.h>
#define size sizeof(struct list)
struct list
{
  int mark;
  struct list*next;
};
int main(int argc, char *argv[])
{
  int n,i,j;
  struct list *p1,*p2,*head,*p,*left;
  head=p2=p1=(struct list*)malloc(size);
  p1->mark=1;
  for(i=2;i<=10;i++)
  {
    p1=(struct list*)malloc(size);
    p1->mark=i;
    p2->next=p1;
    p2=p1;
  }
  scanf("%d",&n);
  int t[n];
  for(i=0;i<n;i++)
  scanf("%d",&t[i]);
  for(i=0;i<n;i++)
  {
  	p=head;
     for(j=1;j<10;j++){
       left=p;
       p=p->next;
       if(p->mark==t[i]){
       left->next=p->next;
       p->next=head;
       head=p;
       break;
       }
    for(j=0;j<10;j++){
        printf("%d ",p->mark);
        p=p->next;
        }
    printf("\n");
    }
  return 0;
}
