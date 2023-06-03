#include <stdio.h>
#include <stdlib.h>
struct student{
  int num;
  int Chinese;
  int Math;
  int English;
  int score;
};
int main(int argc, char *argv[])
{
  int n,i,j,k;
  scanf("%d",&n);
  struct student stu[n+1];
  struct student temp;
  for(i = 1;i<=n;i++){
  	stu[i].num = i;
    scanf("%d%d%d",&stu[i].Chinese,&stu[i].Math,&stu[i].English);
    stu[i].score = 0;
    stu[i].score = stu[i].Chinese + stu[i].Math + stu[i].English;
  }
  //Ñ¡ÔñÅÅĞò
  for(i =1;i<=5;i++){
    k = i;
    for(j = i+1;j<=n;j++){
      if(stu[k].score < stu[j].score) k = j;
		else if(stu[k].score==stu[j].score && stu[k].Chinese < stu[j].Chinese) k = j;
			else if(k > j) k = j;
	}
	if(k!=i){
	temp = stu[k];
	stu[k] = stu[i];
	stu[i] = temp;
	}
  }
  for(i = 1;i<=5;i++)
	printf("%d %d\n",stu[i].num,stu[i].score);
  return 0;
}
