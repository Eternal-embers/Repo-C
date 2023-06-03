#include<stdio.h>
#include<memory.h>
struct map
{
char attack[8][8];//记录会被攻击的范围，1代表不被攻击，0代表被攻击 
char queen[8][8];//记录放置皇后的位置，'.'代表没有放置，'Q'代表放置 
}temp[8],solve[100];
        /*{左下  _左  左上  _上  _下  右下  _右  右上} */
static const int dx[8]={ -1 , -1 , -1  , 0  ,  0 ,  1  ,  1 ,  1 };//横坐标方向 
static const int dy[8]={ -1 ,  0 ,  1  , 1  , -1 , -1  ,  0 ,  1 };//纵坐标方向 
int count=0;
/*
      _______ ---->x
    .|_|_|_|_|
    .|_|_|_|_|
    .|_|_|_|_|
    .|_|_|_|_|
    .
    y     [i+dx*m][j+dy*n]==(x,y)
*/
 

void print(void)
{
 	int i,j,k;
	for(i=0;i<8;i++)
	{
	  for(j=0;j<8;j++)
	    printf("%c ",temp[7].attack[i][j]);//打印第i行的attack
	  printf("\t\t");//将attack和queen的打印分隔开 
	  for(k=0;k<8;k++)
	    printf("%c ",temp[7].queen[i][k]);//打印第i行的queen 
	  printf("\n");//打印下一行 
   }
}


void put_queen(int x,int y,int k)
//在第k行放置queen,对attack进行更新 
{
 temp[k].queen[x][y]='Q';
 temp[k].attack[x][y]='0';
 for(int i=0;i<8;i++)//控制八个方向 
     for(int j=1;j<8;j++)//控制延伸量 
     {
     	int nx=x+dx[i]*j;//生成新的行 
     	if(nx<0||nx>=8)break;//判断x方向是否延伸过度 
     	int ny=y+dy[i]*j;//生成新的列 
     	if(ny<0||ny>=8)break;//判断y方向是否延伸过度 
        temp[k].attack[nx][ny]='0';
	 }
}
void backtrack(int k)
{
    //迭代结束
    if (k == 8)//找到一组解
    {
        temp[k]=solve[count];//将结果queen存储至solve
        count++;
        return;
    }
    //一般情况下迭代的代码 
    for (int k=0,i = 0; i < 8; i++)//在第k行中回溯试探皇后可放置的位置
    {
        if (temp[k].attack[k][i] == 0)//判断当前k行第i列是否可以放置皇后
        {
            put_queen(k,i,k);
            backtrack(k + 1);//递归试探k+1行的皇后的位置
        }
        k--;
    }
}

int main()
{
   int k=0;
   while(k<8)
   {
   memset(&temp[k].attack,'1',64);
   memset(&temp[k].queen,'.',64); 
   }
   backtrack(0);
   print();
   return 0; 
}
