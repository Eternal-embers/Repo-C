/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	void *p = (char *)malloc(sizeof(char) * 5);
	char *pt = (char *)p;
	int i;
	for(i = 0;i < 5;i++)
		*((char *)p + i) = 'b';
	free(p);
    printf("%c\n",pt[2]);
	return 0;
}

