#include<stdio.h>
#define N 12
int main()
{
	const char * p[N] = {"noble","extensive","uncompitable","extraordinary","concentrate","zealous","expensive","external","expand","absolutely","abnormal","access"};
	const char *temp;
	int i,j;
	for(i = 0;i < N-1;i++){
		for(j = i+1;j < N;j++){
			if(( strcmp(p[i],p[j]) ) > 0){
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			}
		}
	}
	for(i = 0;i < N;i++){
		puts(p[i]);
	}	
	return 0;
}
