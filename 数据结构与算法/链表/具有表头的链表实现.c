#include<stdio.h>
#include "_List_H.h"
typedef struct Node* PtrToNode;//宏定义PtrToNode为struct Node*
typedef PtrToNode List;//List表
typedef PtrToNode Position;//表结点的位置
/* Place in the implementation file*/
struct Node{
	int Element;
	Position Next;
};
int IsEmpty(List L){
	return L->Next == NULL;
}
/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P,List L){
	return P->Next == NULL;
}
/* Return Position of X in L;NULL if not found */
Position Find(int X,List L){
	Position P;
	P = L->Next;
	while(P!=NULL && P->Element != X)
		P = P->Next;
	return P;
}
/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete(int X,List L){
	Position P,TmpCell;
	P = Findprevious(X,L);
	if(!IsLast(P,L)) /* Assumption of header use */
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
/* If X is not found,then Next field of returned */
/* Position is NULL */
/* Assume a header */
Position FindPrevious(int X,List L){
	Position P;
	P = L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}//与Delete一起使用的Find

/* Insert (after legal position) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(int X,List L,Position P){
	Position TmpCell;
	TmpCell = (struct Node*)malloc(sizeof(struct Node));
	if(Tmpcell == NULL)
		printf("Out of space!!!\n");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L){
	Position P,Tmp;
	P = L->Next;    /* Header assumed */
	while(P != NULL){
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
int main(){
	List L;
	L = (struct Node *)malloc(sizeof(struct Node));
	L->Element = 0;
	PtrToNode p1,p2;
	p2 = L;
	p1 = (struct Node*)malloc(sizeof(struct Node));
	scanf("%d",p1->Element);
	while(p1->Element > 0){
		p2->Next = p1;
		p2 = p1;
  		p1 = (struct Node*)malloc(sizeof(struct Node));
  		scanf("%d",p1->Element);
	}
	p2->Next = NULL;
	free(p1);
	p1 = L;
	while(p1){
		printf("%d ",p1->Element);
		p1 = p1->Next;
	}
	return 0;
}
