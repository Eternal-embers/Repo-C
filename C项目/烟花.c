#include<stdio.h>
#include<windows.h>
void blast(int height){
	int i;
	for(i = 0;i<height;i++)
	printf("\n");
	printf("\n\n\n\n");
	printf("\t     @@@@\n");
	printf("\t   @######@\n");
	printf("\t  @########@\n");
	printf("\t   @######@\n");
	printf("\t     @@@@\n");
}
void upfire(int height){
	int i,j;
	for(i = 45;i>=height;i--){
		for(j = 0;j<=i;j++)
		printf("\n");
	printf("\t       *\n");
	Sleep(50);
	system("cls");
	}
}
int main()
{
	int i;
	system("pause>NULL");
	upfire(15);
	blast(4);
	system("pause>NULL");
	return 0;
}
