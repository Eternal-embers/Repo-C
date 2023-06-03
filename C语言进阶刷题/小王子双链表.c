#include <stdio.h>
#include <stdlib.h>
typedef struct list{
  int data;
  struct list *pre;
  struct list *next;
}list;

int main(int argc, char *argv[])
{
  int M,i,j;
  list *p1,*head,*p;
  head = (list *)malloc(sizeof(list));
  head->data = 0;
  head->pre = head;
  head->next = head;
  for(i = 1;i<11;i++){
    p1 = (list *)malloc(sizeof(list));
    p1->data = i;
    p1->pre = head->pre;
    p1->next = head;
    head->pre->next = p1;
    head->pre = p1;
  } 
  scanf("%d",&M);
  int arr[M];
  for(i = 0;i<M;i++){
  	scanf("%d",&arr[i]);
  }
  p = head;
  for(i = 0;i<M;i++){
    while(p->data!=arr[i]){
     p = p->next;
    }//找到要在放头部的那个结点 
    p->pre->next = p->next;
    p->next->pre = p->pre;
    p->next = head->next;
    p->pre = head;
    head->next->pre = p;
    head->next = p; 
    while(p!=head){
    printf("%d ",p->data);
    p = p->next;
    }
    printf("\n");
  }

  return 0;
}
