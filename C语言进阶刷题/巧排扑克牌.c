#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
  int data;
  struct stack *next;
}stack;
int main(int argc, char *argv[])
{
  char board[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};//这里用0代替10 
  int i;
  stack *p,*head,*tail,*temp;
  head = (stack *)malloc(sizeof(stack));
  head->data = board[12];
  head->next = NULL;
  for(i=11;i>=0;i--){
    p = (stack *)malloc(sizeof(stack));
    p->data = board[i];
    tail = head;
    if(tail->next==NULL){
    p->next = head;//头插
    head = p;
    }
    //找尾部
    else{
      while(tail->next!=NULL){
      printf("%c ",tail->data);//
      tail = tail->next;
      }
      printf("%c",tail->data);//
      printf("\n");//
      tail->next = p;//入栈尾
      p->next = head;//顶置尾
      temp = head;
      head = head->next;//头部下一结点成为新的头结点
      temp->next = NULL;
    }
  }
  p = head;
  while(p->next!=NULL){
  if(p->data=='0')printf("10, ");
  else printf("%c, ",p->data);
  p = p->next;
  }
  printf("%c",p->data);
  return 0;
}
