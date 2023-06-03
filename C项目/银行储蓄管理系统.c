#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int N;
int password;

struct consumer
{
	int num;//卡号
	char name[10];//客户名
 int password;//密码
	char address[10];//
	int telephone;//电话
	float money;//存款数目
}consumer[100];

struct Date
{
	int year;
	int month;
	int day;
}Date[100];

struct deposit//存款
{
	int number;
	struct Date acction;
	char category;//种类
	int acction_amount;
	char operator_name[5];
}deposit[100];
struct withdrawal//取款
{
	int number;
	struct Date acction;
	char category;
	int acction_amount;
	char operator_name[5];
}withdrawal[100];

int consumer_amount;//客户数目，全局变量
//---------主菜单--------
void mediu()
{
	printf("\n\n");
	printf("\t\t|============================|\n");
	printf("\t\t|    欢迎使用银行储蓄系统    |\n");
	printf("\t\t|============================|\n");
	printf("\t\t|    1.管理员模式；          |\n");
	printf("\t\t|    2.用户模式；            |\n");
	printf("\n\n");
	printf("\t\t请输入你的身份(输入负数结束运行):");
}

void read(){
	FILE *fp = fopen("D:\\data\\info.dat","rb");
	if(fp==NULL) return;
	int i = 0;
	fread(&consumer[i],sizeof(struct consumer),1,fp);
	while(!feof(fp)){
	printf("%10d %10s %10d %10s %10d %f\n",consumer[i].num, consumer[i].name, consumer[i].password, consumer[i].address, consumer[i].telephone,consumer[i].money);//测试
	i++;
	fread(&consumer[i],sizeof(struct consumer),1,fp);
	}
	consumer_amount = i;
	//printf("%d\n",consumer_amount);//测试
}

//--------开户--------
void open_account()
{
	FILE* fp = fopen("D:\\data\\info.dat", "a");
	int i=0;
	printf("\t\t|================================|\n");
	printf("\t\t|              开户              |\n");
	printf("\t\t|================================|\n");
	printf("\t\t请输入开户数量：");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("请输入第%d名用户编号：\n", i + 1);
		scanf("%d", &consumer[i].num);
		printf("请输入第%d名用户姓名：\n", i + 1);
		scanf("%s", consumer[i].name);
 		printf("请输入第%d名用户支付密码：\n", i + 1);
		scanf("%d", &consumer[i].password);
		printf("请输入第%d名用户地址：\n", i + 1);
		scanf("%s", consumer[i].address);
		printf("请输入第%d名用户电话：\n", i + 1);
		scanf("%d", &consumer[i].telephone);
		printf("请输入第%d名用户账户金额：\n", i + 1);
		scanf("%f", &consumer[i].money);
		system("cls");
	}
	for(i = 0;i<N;i++){
	fwrite(&consumer[i], sizeof(struct consumer), 1, fp);
	}
	fclose(fp);
	fp = NULL;
	printf("\t\t|================================|\n");
	printf("\t\t|            开户成功            |\n");
	printf("\t\t|================================|\n");
	printf("\t\t按任意键继续...\n");
}//complete

//---------查询---------
void make_enquiries()
{
	FILE* fp = fopen("D:\\data\\info.dat", "rb");
	char consumer_name[10];
	struct consumer *p = (struct consumer*)malloc(sizeof(struct consumer));
	printf("\t\t|================================|\n");
	printf("\t\t|              查询              |\n");
	printf("\t\t|================================|\n");
	printf("请输入查询用户姓名:");
	scanf("%s", consumer_name);
	fread(p,sizeof(struct consumer),1,fp);
	while(!feof(fp)){
		if (strcmp(consumer_name, p->name) == 0){
		printf("%10d %10s %10d %10s %10d %f\n",p->num, p->name, p->password, p->address, p->telephone,p->money);
		break;
		}
		fread(p,sizeof(struct consumer),1,fp);
	}
	free(p);
	fclose(fp);
	printf("\t\t按任意键继续...\n");
}//complete

//---------修改-----------
void alter()
{
	FILE *fp =  fopen("D:\\data\\info.dat","wb");
	int n = 0;
	char consumer_name[10];
	printf("\t\t|================================|\n");
	printf("\t\t|          修改用户信息          |\n");
	printf("\t\t|================================|\n");
	printf("\t\t请输入修改用户姓名：\n");
	scanf("%s", consumer_name);
	while(n<consumer_amount){
	if (strcmp(consumer_name, consumer[n].name) == 0)
	{
		printf("\t编号\t姓名\t支取密码\t地址\t电话\t账户金额\n");
		printf("%10d %10s %10d %10s %10d %f\n", consumer[n].num, consumer[n].name, consumer[n].password, consumer[n].address, consumer[n].telephone,consumer[n].money);
		scanf("%d%s%d%s%d%f", &consumer[n].num, consumer[n].name, &consumer[n].password, consumer[n].address, &consumer[n].telephone,&consumer[n].money);
		break;
	}
	n++;
	}
	printf("\t\t|================================|\n");
	printf("\t\t|        修改用户信息成功        |\n");
	printf("\t\t|================================|\n");
	for(n = 0;n<consumer_amount;n++){
	printf("\t%5d\t%5s\t%5d\t%5s\t%5d\t%f\n", consumer[n].num, consumer[n].name, consumer[n].password, consumer[n].address, consumer[n].telephone,consumer[n].money); //测试
	fwrite(&consumer[n], sizeof(struct consumer), 1, fp);
	}
	fclose(fp);

}

//-----------销户-----------
void dele()
{
	int i = 0, k, m;
	int j;
	char consumer_name[5];
	FILE* fp = fopen("xinxi.txt", "r");
	printf("\t\t|================================|\n");
	printf("\t\t|              销户              |\n");
	printf("\t\t|================================|\n");
	while (!feof(fp))
	{
		fread(&consumer[i], sizeof(struct consumer), 1, fp);
		i++;
	}
	fclose(fp);
	printf("\t\t请输入用户姓名:");
	scanf("%s", consumer_name);
	for (j = 0; j < i; j++)
	{
		if (strcmp(consumer_name, consumer[j].name) == 0)
		{
			printf("是否确定销户？（1确定/0返回)");
			scanf("%d", &k);
			if (k == 1)
			{
				for (m = j; m < i; m++)
					consumer[i] = consumer[i + 1];
				i--;
				//fp = fopen("xinxi.txt", "w");
				//for (m = 0; m < i; m++)
				//	fwrite(&consumer[i], sizeof(struct consumer), 1, fp);
				//fclose(fp);
				printf("\t\t|================================|\n");
				printf("\t\t|            销户成功            |\n");
				printf("\t\t|================================|\n");
			}
			else
				printf("返回");
		}
	}
	fclose(fp);
	fp = NULL;
}//实现不了，拿来演示截图即可，不要真的销户

//-----------存款------------

void con_deposit()
{
	int B = 0;
	float account_amount =0;
	printf("请输入存款金额：");
	scanf("%d", &B);
	account_amount = account_amount + B;
	printf("请输入剩余账户金额：%d ", &account_amount);

}

//-----------取款-----------

void con_withdrawal()
{
	int C = 0;
	int account_amount = 0;
	printf("请输入取款金额：");
	scanf("%d", &C);
	account_amount = account_amount + C;
	printf("请输入剩余账户金额：%d ", &account_amount);

}

//-----------管理员模式-------------

	int attendant()
	{
		int j =0;
		printf("\n\n\n\n");
		printf("\t\t|================================|\n");
		printf("\t\t|          管理员模式            |\n");
		printf("\t\t|================================|\n");
		printf("\t\t|          1.开户；              |\n");
		printf("\t\t|          2.查询；              |\n");
		printf("\t\t|          3.修改用户信息；      |\n");
		printf("\t\t|          4.销户；              |\n");
	    printf("\t\t|          5.返回主菜单          |\n");
		printf("请输入你的选择：");
		scanf("%d",&j);
		switch (j)
		{
		   case 1:
		   {
			   open_account();
			   break;
		   }
		   case 2:
		   {
			   make_enquiries();
			   break;
		   }
		   case 3:
		   {
			   alter();
			   break;
		   }
		   case 4:
		   {
			   int delete();
			   break;
		   }
		   case 5:
		   {
			   mediu();
			   break;
		   }
		}
		printf("\n\n");
		return j;
	}

//-----------用户模式---------

	int con()
	{
		int y = 0;
		printf("\n\n\n\n");
		printf("\t\t|================================|\n");
		printf("\t\t|            用户模式            |\n");
		printf("\t\t|================================|\n");
		printf("\t\t|            1.查询；            |\n");
		printf("\t\t|            2.存款；            |\n");
		printf("\t\t|            3.取款；            |\n");
		printf("\t\t|            4.返回主菜单        |\n");
		printf("请输入你的选择：");
		scanf("%d",&y);
		switch (y)
		{
		case 1:
		{
			make_enquiries();
			break;
		}
		case 2:
		{
			con_deposit();
			break;
		}
		case 3:
		{
			con_withdrawal();
			break;
		}
		case 4:
		{
			mediu();
			break;
		}
		}
		 printf("\n\n");
         return y;
	}

//------------主函数-------------

	int main()
	{
	read();
    int x = 1;
    while(x>0){
	mediu();
	scanf("%d", &x);
    switch (x){
		case 1:
  		{
			attendant();//管理员
			break;
		}
		case 2:
		{
			con();//用户
			break;
		}
		if(x>=0)
		{
			printf("\n输入失败，请再次选择身份:\n");
			break;
		}
	  	}
	}
		return 0;
	}
