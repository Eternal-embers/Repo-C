#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char board[15][15];//定义棋盘
char role='X';//初始角色为X，另一角色为$
char x=7,y=7;//初始化棋子坐标(7,7),光标位置(x,y) 

void init_board(void)//初始化棋盘 
{
	int i,j;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			board[i][j]='0';
} 

void show_board()//打印棋盘 
{
	int i,j;
	system("cls");
	for(i=0;i<15;i++)
	{
		printf("                            >>%2d",i+1);//每行开头20个空格，调整棋盘位置 
		for(j=0;j<15;j++)
			printf("  %c",board[i][j]);
		printf("  <<\n\n");
	}
	printf("                            > > > > > > > > > > > > > < < < < < < < < < < < < < <\n");
} 

void get_key(void)//获取棋子,光标位置(x,y),可以在光标所在位置下棋 
{
	while(1)
	{
		printf("\033[%d;%dH",2*x+1,3*y+35); 
		switch( getch() )
		{
			//role=X 
			case 'w': x>0 && x--; break;//上 
			case 's': x<14 && x++; break;//下 
			case 'a': y>0 && y--; break;//左 
			case 'd': y<14 && y++; break;//右 
			//role=$
			case 'o': x>0 && x--; break;//上
			case 'l': x<14 && x++; break;//下 
			case 'k': y>0 && y--; break;//左
			case ';': y<14 && y++; break;//右 
			case 32 : {
				if(board[x][y] == '0')//如果该位置没有棋子
				{
				board[x][y]=role;
				return;
				}
			}
			case 13 :{
				if(board[x][y] == '0')//如果该位置没有棋子
				{
				board[x][y]=role;
				return;
				}
			}
		}
	} 
}

int count(go_x,go_y)//遍历得到某方向上连珠个数 
{
	char X=x,Y=y;//从棋子放置位置开始遍历 
	int count=0;//记录连珠个数 
	while(X>=0 && Y>=0 && count<5)//如果没有触碰边界或是没有出现五个连珠情况，继续遍历 
	{
	if( board[X][Y] == board[X+go_x][Y+go_y] )count++;//连珠则继续遍历 
	else break;//不连珠停止遍历 
	X+=go_x;
	Y+=go_y;
	}
	return count;
} 

_Bool is_win(void)
{
	if( count(1,0)+count(-1,0) >=4 )return 1;//上下 
	if( count(0,1)+count(0,-1) >=4 )return 1;//左右
	if( count(1,-1)+count(-1,1) >=4 )return 1;//左上和右下
	if( count(1,1)+count(-1,-1) >=4 )return 1;//右上和左下
	return 0; //全部方向上都不存在五个连珠情况，继续游戏 
}

int main()
{
	int i;
	init_board();
	system("color f0"); 
	for(i=0;i<225;i++)//总共225个棋位 
	{
		show_board();
		get_key();
		if( is_win() )//判定是否有人胜利
		{
			
			system("color 02");
			show_board();
			printf("                                                %c 赢得比赛\n                                                ",role);
			system("pause");
			return 0;
		} 
		role=(role=='X')?'$':'X';//交换角色 
	}
}
