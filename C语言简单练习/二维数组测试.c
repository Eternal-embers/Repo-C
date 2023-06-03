/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>

int main(){
	int arcs[3][3] = {
		1,2,3,
		4,5,6,
		7,8,9
	};
	int *p1 = arcs;
	printf("%d %d\n",*(*(arcs + 2) + 2),*(p1 + 2 * 3 + 2));
	return 0;
}

