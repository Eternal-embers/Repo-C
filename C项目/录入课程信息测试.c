#include<stdio.h>
int main()
{
	int num;//编号
	char name[30];//课程名称
	char property[7];//课程性质，公开课/选修课/必修课 
	short total_period;//总学时，单位课时 
	short week_lesson;//授课学时，单位课时 
	short test_lesson;//实验学时，单位课时 
	char semester[7];//开课学期,如大一上 
	short credit;//学分
	printf("编号 ->《课程名称》-> 课程性质 -> 总学时 -> 授课学时 -> 实验学时 -> 开课学期 -> 学分\n");
	scanf("%d%30s%6s%hd%hd%hd%6s%hd",&num,name,property,&total_period,&week_lesson,&test_lesson,semester,&credit);
	printf("%-7d %-14s %-12s %-10hd %-10hd %-10hd %-10s %-5hd\n",num,name,property,total_period,week_lesson,test_lesson,semester,credit);
	return 0;
}
