#include<stdio.h>
#include<time.h>
#define num1 1
#define num2 6
int main()
{
	int rand_num,i;
	float count=0; 
	srand((int)time(NULL));
	for(i=1;i<=120;i++)
	{
	rand_num=rand()%(num2-num1+1)+num1;//返回num1~num2的随机数 
	if(rand_num==3)count++;
	printf("%d ",rand_num);
	if(i%6==0){
	printf("--> %.3f%%\n",count/6*100);
	count=0;
	}		
    }
	return 0;
}
