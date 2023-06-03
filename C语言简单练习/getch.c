#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
char key_x=7,key_y=7;
char board[15][15];
void init_board(void)
{
 int i,j;
 for(i=0;i<15;i++)
 {
  for(j=0;j<15;j++)
  {
   board[i][j]='0'; 
  }
 }
}
void print()
{
	int i,j;
	system("cls");
	for(i=0;i<15;i++){
	for(j=0;j<15;j++){
	printf("  %c",board[i][j]);
	}
	printf("\n\n");
	}
}
void getxy(void)
{
	while(1){
	 printf("\033[%d;%dH",key_x*2,3*key_y+3);//光标位置，(key_y+1)*2是因为列与列之间有空格
  	 switch(getch())
  	 {
   	    case 'w':key_x>0 && key_x--;break; //上，改变光标位置值
   	    case 'o':key_x>0 && key_x--;break; //上 
   		case 's':key_x<14 && key_x++;break; //下
   		case 'l':key_x<14 && key_x++;break; //下 
   		case 'd':key_y<14 && key_y++;break; //右
   		case ';':key_y<14 && key_y++;break;//右 
   		case 'a':key_y>0 && key_y--;break;//左
   		case 'k':key_y>0 && key_y--;break;//左
	 }
	}
}
int main()
{
	init_board();
	while(1){
	 print();
     getxy();
 }
	return 0;
}
