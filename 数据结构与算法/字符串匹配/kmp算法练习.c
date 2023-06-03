#include<stdio.h>
#include<stdlib.h>
typedef struct String{
	char *data;
	int len;
}String;

String *initString(void){
	String *s = (String *)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;	
}

void stringAssign(String *s,char* data){
	int len = 0,i;
	if(s->data)free(s->data);
	while(data[len]){
		len++;
	}
	if(len == 0){
		s->data = NULL;
		s->len = 0;
	}
	else{
	s->data = (char *)calloc(len,sizeof(char));
	s->len = len;
	for(i = 0;i <= len;i++)
	s->data[i] = data[i];
	}	
}

void printString(String *s){
	int i = 0;
	for(i=0;i<s->len;i++)
		printf("%c",s->data[i]);
	printf("\n");
}

int *getNext(String *s){
	int *next = (int *)calloc(s->len,sizeof(int));//按需开辟数组
	int i=0,j=-1;
	next[0]=-1;
	while(i < s->len){
		if(j == -1 || s->data[i]==s->data[j]){
			next[++i] = ++j;
		}
		else j = next[j];
	}
	return next;
}

void printNext(int *next,int len){
	int i;
	for(i=0;i < len;i++){
		printf("%d ",next[i]);
	}
	printf("\n");
}

void kmpMatch(String *master,String *sub,int *next){
	int i=0,j=0;
	while(i < master->len && j < sub->len) {
		if(j == -1 || master->data[i] == sub->data[j]){
			i++;
			j++;
		}
		else j = next[j];
	}
	if(j == sub->len){
		printf("kmp match success.\n");
	}	
	else printf("kmp mathc failed\n");
}

int main()
{
	String *s = (String *)malloc(sizeof(String));
	String *s1 = (String *)malloc(sizeof(String));
	s = initString();
	s1 = initString();
	stringAssign(s,"abacbacaabcaababcabcabababac");
	stringAssign(s1,"abababac");
	printString(s);
	printString(s1);
	int *next=getNext(s1);
	printNext(next,s1->len);
	kmpMatch(s,s1,next);
	return 0;
}
