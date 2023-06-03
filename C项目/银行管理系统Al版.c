#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100

typedef struct
{
    char name[20];
    char id[20];
    char password[20];
    float balance;
}Account;

Account account[MAX_NUM];
int count = 0;

void menu();
void open_account();
void search_account();
void deposit_account();
void withdraw_account();
void delete_account();

int main()
{
    int choice;
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                open_account();
                break;
            case 2:
                search_account();
                break;
            case 3:
                deposit_account();
                break;
            case 4:
                withdraw_account();
                break;
            case 5:
                delete_account();
                break;
            case 0:
                exit(0);
            default:
                printf("输入有误，请重新输入！\n");
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("");
    printf("                *****************************\n");
    printf("                *                           *\n");
    printf("                *        1.开户             *\n");
    printf("                *        2.查询             *\n");
    printf("                *        3.存款             *\n");
    printf("                *        4.取款             *\n");
    printf("                *        5.销户             *\n");
    printf("                *        0.退出             *\n");
    printf("                *                           *\n");
    printf("                *****************************\n");
    printf("                请输入您的选择：");
}

void open_account()
{
    if(count == MAX_NUM)
    {
        printf("账户已满，无法开户！\n");
        return;
    }
    printf("请输入您的姓名：");
    scanf("%s",account[count].name);
    printf("请输入您的身份证号：");
    scanf("%s",account[count].id);
    printf("请输入您的密码：");
    scanf("%s",account[count].password);
    printf("请输入您的存款金额：");
    scanf("%f",&account[count].balance);
    count++;
    printf("开户成功！\n");
}

void search_account()
{
    int i;
    char id[20];
    printf("请输入您要查询的身份证号：");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("姓名：%s",account[i].name);
            printf("身份证号：%s",account[i].id);
            printf("密码：%s",account[i].password);
            printf("余额：%.2f\n",account[i].balance);
            break;
        }
    }
    if(i == count)
    {
        printf("查无此人！\n");
    }
}

void deposit_account()
{
    int i;
    char id[20];
    float money;
    printf("请输入您要存款的身份证号：");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("请输入您要存款的金额：");
            scanf("%f",&money);
            account[i].balance += money;
            printf("存款成功！\n");
            break;
        }
    }
    if(i == count)
    {
        printf("查无此人！\n");
    }
}

void withdraw_account()
{
    int i;
    char id[20];
    float money;
    printf("请输入您要取款的身份证号：");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            printf("请输入您要取款的金额：");
            scanf("%f",&money);
            if(money > account[i].balance)
            {
                printf("余额不足！\n");
            }
            else
            {
                account[i].balance -= money;
                printf("取款成功！\n");
            }
            break;
        }
    }
    if(i == count)
    {
        printf("查无此人！\n");
    }
}

void delete_account()
{
    int i;
    char id[20];
    printf("请输入您要销户的身份证号：");
    scanf("%s",id);
    for(i=0;i<count;i++)
    {
        if(strcmp(account[i].id,id) == 0)
        {
            int j;
            for(j=i;j<count-1;j++)
            {
                account[j] = account[j+1];
            }
            count--;
            printf("销户成功！\n");
            break;
        }
    }
    if(i == count)
    {
        printf("查无此人！\n");
    }
	}
