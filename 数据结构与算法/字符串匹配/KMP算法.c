#include<stdio.h>
#include<stdlib.h>
typedef struct String{
	char *data;
	int len;
}String;

String * initString(){
	String *  s = (String *)malloc(sizeof(String));
	s->data = NULL;
	s->len=0;
}

void StringAssign(String* s,char* data){
	if(s->data)	free(s->data);
	int len=0,i; 
	char* temp=data;
	while(*temp){
		len++;
		temp++;
	}
	if(len==0){
		s->data = NULL;
		s->len = 0;
	}
	else {
		temp = data;
		s->len = len;
		s->data = (char *)malloc(sizeof(char)*(len+1));//按需开辟数组 
		for( i=0;i <= len; i++,temp++){
		s->data[i] =*temp;
		}
	}
}

void printString(String *s){
	int i;
	for( i=0; i < s->len; i++){
		printf(i == 0 ? "%c" : "->%c",s->data[i]);
	}
	printf("\n");
}

int* getNext(String* s){
	int * next =(int *)calloc(s->len+1,sizeof(int));//开辟next数组 
	int i=0,j=-1;
	next[0]=-1;//回溯的终止点
	while( i < s->len-1){
		if( j==-1 || s->data[i] == s->data[j]){
			next[++i]=++j;//指针后移一位，next数组记录匹配状态
		}
		else j=next[j];//回溯
		printf("i=%d,j=%d,next[%d]=%d\n",i,j,i,next[i]);
	}
	return next;
}

void printNext(int *next,int len){
	int i;
	for( i=0; i < len; i++){
		printf(i == 0 ? "%d" : "->%d",next[i]);
	}
	printf("\n");
}


int kmpMatch(String *master,String *sub,int *next){
	int i=0;
	int j=0;
	while(i < master->len && j < sub->len)	{
		if(j == -1 || master->data[i] == sub->data[j]){
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if(j == sub->len){
		printf("kmp match success.\n");
		return i - j;
	}
	else {
		printf("kmp match failed.\n");
		return -1;
	}
}

int main()
{
	String *s = initString();//主串 
	String *s1 = initString();//模式串
	StringAssign(s,"aaabbaaababbb");
	StringAssign(s1,"aaabab");
	printString(s);
	printString(s1);
	int *next = getNext(s1);
	printNext(next,s1->len);
	int pos = kmpMatch(s,s1,next);
	printString(s);
	int i;
	for(i = 0;i < pos;i++)
		printf("   ");
	printString(s1);
	return 0;
}
