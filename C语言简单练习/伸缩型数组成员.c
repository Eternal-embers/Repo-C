#include<stdio.h>
#include<string.h> 
#define N 5
struct PersonInfo{
	long long phone;
	struct PersonInfo *next;
	char name[];
};
int main()
{
	int i;
	char *p;
	char temp[12];
	struct PersonInfo *p1,*p2,*head;
	for(i = 0;i<N;i++){
		system("cls");
		memset(temp,sizeof(char),12);
		printf(">>>%d\n",i+1);
		printf("please input your name:\n>>");
		scanf("%s",temp);
		p1 = (struct PersonInfo*)malloc(sizeof(struct PersonInfo)+strlen(temp)+1);
		strcpy(p1->name,temp);
		printf("please input your phone number:\n>>");
		scanf("%lld",&p1->phone);
		if(i==0)head = p2= p1;
		else p2->next = p1;
		p2 = p1;
	}
	p1 = head;
	printf(" name             phone\n");
	for(i = 0;i<N;i++){
		printf(" %-12s%lld\n",p1->name,p1->phone);
		p1 = p1->next;
	}
	return 0;
}
