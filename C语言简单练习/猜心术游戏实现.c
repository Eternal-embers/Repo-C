/*
	Name:猜心术游戏
	Copyright:劣等生
	Author:劣等生
	Date:2023/06/23 13:14
	Description: 简单的逻辑判断
*/
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define line; printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
#define pause; system("pause>NULL");
_Bool input(){
	int option;
	while(1){
		printf("\t\t请判断你所选的数是否在其中(1/0)：");
		scanf("%d",&option);
		if(option == 0 || option == 1) break;
		else printf("\t\t输入错误，如果你所选的数在上面四个数中请输入1，否则输入0。\n");
	}
	return option;
}

int main(){
	int x[9];
	int i,option;
	srand(time(NULL));//根据当前时间获取随机数的种子
	/* 产生7个随机数 */
	for(i = 1;i <= 7 ;i++)
		x[i] = rand() % N + 1;//定义随机数的范围是1~N
	/* 开始游戏 */
	printf("\n\n\t\t\t\t>>>猜心术游戏<<<\n\n");
	printf("\t\t请你从下面展示的七个数中选择一个数并记在心里：\n\t\t");
	printf("%d %d %d %d %d %d %d",x[3],x[7],x[1],x[6],x[4],x[2],x[5]);
	pause;
	putchar('\n');
	printf("\t\t好，接下来将从上面七个数中每次随机显示四个数，你需要判断你所选的数是否在其中，如果在则输入1，否则输入0。");
	pause;
	putchar('\n');
	
	/* 第一次判断 */
	line;
	printf("\t\t%d %d %d %d\n",x[3],x[2],x[4],x[1]);//取x1，x2，x3，x4
	option = input();


	if(option == 1){
		/* 第二次判断 */
  		line;
	   	printf("\t\t%d %d %d %d\n",x[2],x[6],x[1],x[7]);//取x1，x2
	 	option = input();
	 	
	 	/* 第三次判断*/
		if(option == 1){
   			line;
			printf("\t\t%d %d %d %d\n",x[5],x[4],x[7],x[1]);//取x1
			option = input();
			/* 判断结果 */
			if(option == 1) printf("\t\t你所选的数是%d\n",x[1]);//x1
			else printf("\t\t你所选的数是%d\n",x[2]);//x2
		}
		else{
			line;
			printf("\t\t%d %d %d %d\n",x[7],x[2],x[3],x[6]);//取x3
   			option = input();
   			/* 判断结果 */
			if(option == 1) printf("\t\t你所选的数是%d\n",x[3]);//x3
			else printf("\t\t你所选的数是%d\n",x[4]);//x4
		}
	}
	else{
		/* 第二次判断 */
		line;
	   	printf("\t\t%d %d %d %d\n",x[6],x[5],x[4],x[2]);//取x5，x6
	 	option = input();

	 	/* 第三次判断*/
		if(option == 1){
			line;
			printf("\t\t%d %d %d %d\n",x[1],x[5],x[3],x[2]);//取x5
			option = input();
			/* 判断结果 */
			if(option == 1) printf("\t\t你所选的数是%d\n",x[5]);//x5
			else printf("\t\t你所选的数是%d\n",x[6]);//x6
		}
		else{
		   	line;
			printf("\t\t%d %d %d %d\n",x[2],x[4],x[3],x[5]);//取x7,已经出结果了
   			option = input();
   			/* 判断结果 */
            printf("\t\t你所选的数是%d\n",x[7]);
		}
	}
	line;
	pause;
	printf("\t\t游戏结束！");
	return 0;
}

