#include<stdio.h>
#include<stdlib.h>
typedef struct PIN
{
	char *p;
	int len;
}PIN;

PIN *initPIN(void)
{
	PIN *s=(PIN *)malloc(sizeof(PIN));
	s->p=NULL;
	s->len=0;
	return s;
}

void put(PIN *s,char *ch)
{
	int len=0,i;
	char *temp=ch;
	while(*temp)
	{
		len++;
		temp++;
	}
	temp=ch;
	s->len=len;
	s->p=(char *)malloc(sizeof(char)*(len+1));
	for(i=0;i<len;i++)
	{
		s->p[i]=*temp;
		temp++;
	}
}

void print_password(PIN *s)
{
	char *pt=s->p;
	int i;
	for(i=0;i<s->len;i++)
	printf("%c",pt[i]);
}

void encrypt1(PIN *s)
{
	int num,i;
	char *pt=s->p;
	printf("Æ«ÒÆÁ¿="); 
	scanf("%d",&num);
	for(i=0;i<s->len;i++)
	{
		*pt=*pt + num;
		pt++;
	}
}

void encrypt2(PIN *s)
{
	int num,i,temp;
	char *pt=s->p;
	printf("Æ«ÒÆÁ¿="); 
	scanf("%d",&num);
	for(i=1;i<=s->len;i++)
	{
		*pt =( (*pt) * (*pt + i ) *(*pt + num) ) % 94 + 33;
		pt++;
	}
}

void encrypt3(PIN *s)
{
	int i,num;
	char *pt=s->p;
	printf("Æ«ÒÆÁ¿=");
	scanf("%d",&num);
	for(i=1;i<=s->len;i++)
	{
		*pt = ( (*pt + i * i) * (*pt + i * i) + num ) % 94  + 33;
		*pt++;
    }
}

int main()
{
	char str[20];
	printf("please enter the string:");
	gets(str);
	PIN *s=initPIN();
	put(s,&str[0]);
	encrypt2(s);
	print_password(s);
	return 0;
}
