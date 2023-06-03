#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define true 1
#define false 0 

//定义棋盘
char board[15][15];
//角色
char role='X';
//落子坐标
char key_x=7,key_y=7;
//棋盘初始化
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

//打印棋盘
void show_board(void)
{
 int i,j;
 system("cls");
 for(i=0;i<15;i++)                                                  
 {
  printf("                   >%2d",i+1);
  for(j=0;j<15;j++)
  {
   printf("  %c",board[i][j]); 
  }
  printf("  <\n\n");
 }
 printf("                   > > > > > > > > > > > > > < < < < < < < < < < < < <\n");
}                                                                             

//落子
void get_key(void)
{
 while(1){
     printf("\33[%d;%dH",key_x*2+1,3*key_y+25);//光标位置，(key_y+1)*2是因为列与列之间有空格
  	 switch(getch())
  	 {
   	    case 'w':key_x>0 && key_x--;break; //上,改变光标位置值
   	    case 'o':key_x>0 && key_x--;break; //上 
   		case 's':key_x<14 && key_x++;break; //下
   		case 'l':key_x<14 && key_x++;break; //下 
   		case 'd':key_y<14 && key_y++;break; //右
   		case ';':key_y<14 && key_y++;break;//右 
   		case 'a':key_y>0 && key_y--;break;//左
   		case 'k':key_y>0 && key_y--;break;//左 
   		case 32://空格
   		if(board[key_x][key_y] == '0')//如果落子位置为空，落子
		   {
   			 board[key_x][key_y]=role;
    		 return;
    	   }
		 if(board[key_x][key_y] == 13)//如果落子位置为空，落子
		   {
   			 board[key_x][key_y]=role;
    		 return;
    	   }
	 }
 }
}

//记录落子位置某个方向，连子的个数
int count_board(int go_x,int go_y)
{
 int count=0,x,y;
 for(x=key_x+go_x,y=key_y+go_y;
  x>=0 && y>=0 && x<15 && y<15;
  x+=go_x,y+=go_y)//向各个反向遍历 
 {
  if(board[x][y]==board[key_x][key_y])
  {
   count++; 
  }
  else break;//一旦遇到其他种类的子，停止遍历 
 }
 return count;
}

//判断五子连珠，是否胜利
_Bool is_win(void)
{
 if(count_board(0,-1)+count_board(0,1)>=4)//左右反向 
 {
  return true; 
 }
 if(count_board(-1,0)+count_board(1,0)>=4)//上下方向 
 {
  return true; 
 }
 if(count_board(-1,-1)+count_board(1,1)>=4)//左上和右下反向 
 {
  return true; 
 }
 if(count_board(1,-1)+count_board(-1,1)>=4)//左下和右上反向 
 {
  return true; 
 }
 return false;
}

int main(int argc,const char* argv[])
{
 int i;
 system("color f0");
 init_board();	//初始化棋盘
 for(i=0;i<=225;i++)
 {
  show_board();	//清屏，打印棋盘
  get_key();	//落子
  if(is_win())	//是否五子连珠
  {
   system("cls");
   show_board();
   system("color 02");
   printf("                   游戏结束，%c赢了\n",role);
   return 0;
  }
  role=role=='X'?'$':'X';//交换角色
 }
} 
