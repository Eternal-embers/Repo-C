#include"stdio.h"
#include"windows.h"    //用于获取窗口的句柄与屏幕控制
#include"conio.h"      //用于获取键盘输入的内容
#include"string.h"  
#include"stdlib.h"   
/*两个结构体*/
/*用于存用户信息*/ 
typedef struct usepeople
{
    char name[20];//用户名 
    char mm[20];//密码 
    struct usepeople *next;
}U;
/*输出历史记录*/ 
struct history
{
    char NAME[20];
    int SCORE;
}s[10];
//定义全局变量
int o;    //保存排行榜分数
char j[20];     //保存排行榜用户名
int h,w;   //定义画面的高和宽 
int p_x,p_y;       // 定义我方飞机的位置
int e_x,e_y;       // 定义敌方飞机的位置 
int b_x,b_y;       //定义子弹的位置 
int score;         //得分
int f;              //定义飞机的状态
int num=1;          //控制排名的数量  (我设置的是8个)     
void gotoxy(int x,int y);              //光标移动到(x,y)位置 
void menu1(U *h,int num);                       //菜单功能   
int color(int c);                       //更改文字颜色
void explation();                    //游戏右侧显示 
void tip();                         //游戏说明
void seescore();                      //分数显示 
void startup();                      //游戏初始化 
void show();                        //显示游戏画面 
void Fly();                         //定义函数来控制子弹和敌人的移动 
void Planefly() ;                   //定义函数来控制飞机的移动和子弹的发射
void gameover(U *h);                  //设计游戏结束界面
U * createpeople(U *h);           //用于注册用户的信息
void create(U *h);                //建立第一个注册信息 
void History_inf(struct history s[],int num); //用于遍历输出挑战者信息
void insert(U *h);            //在结尾加入注册后的玩家账号 
U* search(U *h,char *name);  //用于判断用户的用户名是否正确 
void deletenum(U *h,char name[]);//注销用户信息 
void iregister(U *h);        //注册页面 
void dengru(U *h,int num);   //登入页面 
void log_in(U *h);               //保存用户信息 
void msort(struct history *a,int n);    //记录冒泡排序 
int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return 0;
}
//注销用户信息
void deletenum(U *h,char name[])
{
    U *p=h->next;
    while(p&&strcmp(p->name,name)!=0)
    {
        h=p;
        p=p->next;
    }
    if(p)
    {
        h->next=p->next;
        free(p);
    }
}
/*设置光标的位置*/
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*光标的隐藏*/
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1,0};//第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/*进行冒泡排序*/ 
void msort(struct history *a,int n)
{
    int i,f;
    for(i=1;i<num;i++)
    {
        for(f=num;f>i;f--)
        {
            if(s[f].SCORE>s[f-1].SCORE)
            {
                o=a[f].SCORE;
                a[f].SCORE=a[f-1].SCORE;
                a[f-1].SCORE=o;
                strcpy(j,a[f].NAME);
                strcpy(a[f].NAME,a[f-1].NAME);
                strcpy(a[f-1].NAME,j);
            }
        }
    }
}
//用于遍历输出挑战者信息
void History_inf(struct history s[],int num,U* h)
{
	int i; 
    system("cls");
    if(num==1)
    {
        gotoxy(1,1);
        printf("你还没有记录");
    }
    
    for(i=1;i<num;i++)   //这里的for是用来逐一输出每一个用户的数据 
    {
        gotoxy(15,3+2*i);
        printf("%d:用户名:%s   ",i,s[i].NAME);
        printf("得分:%d   ",s[i].SCORE);
    
    }
        gotoxy(1,28);
        printf("请注意最多保存8次记录");
        getch();
        system("cls");
        menu1(h,num);  //看完以后返回开始界面 
} 
//建立第一个注册信息 
void create(U *h)
{
    U *p,*q=h;
    char name[20];
    printf("请输入用户名:\n");
    gotoxy(39,12);
    scanf("%s",name);
    while(strcmp(name,"OVER"))
    {
        p=(U*)malloc(sizeof(U));
        strcpy(p->name,name);
        char mm[20];
        gotoxy(39,13);
        printf("请输入密码:（换行输入OVER结束）\n"); 
        gotoxy(39,14);
        scanf("%s",mm);
        strcpy(p->mm,mm);
        q->next=p;
        q=p;
        gotoxy(39,15);
        scanf("%s",name);
    }
    q->next=NULL;
}
 
U* search(U *h,char *name)
{
    while(h=h->next,h)
    {if(!strcmp(h->name,name))  return h;}
    return NULL;
}
 
U * createpeople(U *h)
{
    U *q;
    q=(U*)malloc(sizeof(U));
W:    printf("输入你要注册的用户名：\n");
    scanf("%s",q->name);
    if(search(h,q->name)) {system("cls");printf("该用户名已存在！！！\n");_getch();system("cls");goto W;}
    printf("输入你的密码：\n");
    scanf("%s",q->mm);
    q->next=NULL;
    return q;
}
//在结尾加入注册后的玩家账号 
void insert(U *h)  
{
    U *q,*temp;
    q=createpeople(h);
    while(h=h->next,h){if(h->next==NULL)break;}temp=h;
    q->next=temp->next;
    temp->next=q;
}
/*游戏说明*/
void tip()    
{
    gotoxy(30,5);printf("w向上，s向下，a向左，d向右，按空格射击");
    gotoxy(30,10) ;printf("你击落一架敌机可得1分"); 
    gotoxy(30,15);    printf("如果你被敌机撞上就会死亡");
}                     
void menu1(U *h,int num)                       //菜单功能   
{
    int n;
    gotoxy(37,10);
    printf("飞 机 大 战"); 
    gotoxy(15,20);
    printf("输入数字1：开始游戏") ;
    gotoxy(55,20);
    printf("输入数字2：查看规则");
    gotoxy(15,22);
    printf("输入数字3：查看挑战榜"); 
    gotoxy(55,22);
    printf("输入数字4：退出游戏"); 
    gotoxy(15,24);
    printf("输入数字5：注销账号");
    gotoxy(55,24);
    printf("输入数字6：请你签到"); 
    gotoxy(37,25);
    printf("请输入你的选择："); 
     scanf("%d",&n);
     switch(n)
     {
         case 1:
             {
                 system("cls"); 
             }break;
        case 2:
            {
                system("cls");
                tip(); 
                printf("\n");
                gotoxy(30,17);
                printf("输入1 ，返回主页");
                int a=0; 
                scanf("%d",&a);
                if(a==1) {system("cls");menu1(h,num);}
            }break;
        case 3:
            {
                 History(s,num,h);    
            }break;
        case 4:
            {
                system("cls");
                printf("你确定要退出游戏吗？\n");
                printf("确定输入1,不确定输入2\n");
                int a=0;
                scanf("%d",&a);
                if(a==1)    exit(0);
                else {system("cls");menu1(h,num);}
            }break;
        case 5:
            {
                char name[20];
                    system("cls");
                    printf("输入要删除在帐号:");
                    scanf("%s",name);
                    deletenum(h,name);
                    printf("输入1 ，返回主页");
                int a=0; 
                scanf("%d",&a);
                if(a==1)
                 {
                   system("cls");
                   if(h->next==NULL)
                    {iregister(h);dengru(h,num);}
                    else dengru(h,num);menu1(h,num);
                 }    
            }break;
        case 6:
            {
                system("cls");log_in(h);
                gotoxy(42,12);printf("请输入任意键继续！！！\n");
                _getch();
                system("cls");
                menu1(h,num);
            }break;
            default:
            {
                gotoxy(37,25);
                printf("请看清楚条件\n");
                _getch();
                system("cls");
                menu1(h,num);
            }break;
     }
} 
void startup()      //游戏初始化 
{
    h=20; //高为20 
    w=50; //宽为50
    score=0; //得分初始化 
    f=1;  //飞机的状态
    p_x=w/2; //飞机x的位置 
    p_y=h-4; //飞机y的位置
    e_x=2+rand()%w-2;
    e_y=0; 
    b_x=p_x;
    b_y=0;
    HideCursor();   //隐藏光标 
}
/*显示游戏画面*/
void show()
{
    int i,j;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(f==0)     break;
            else
            {
            if((i==0)||(j==0)||(i==h-1)||(j==w-1))   printf("+");
            else if((i==p_y)&&(j==p_x))     printf("A");
            else if((i==b_y)&&(j==b_x))       printf("!");
            else if((i==e_y)&&(j==e_x))       printf("@");
            else printf(" ");
            }    
        }
    printf("\n");
    }
    if((p_x==e_x)&&(p_y==e_y))    f--;
}               
/*分数显示  */ 
void seescore(int num)
{
    gotoxy(56,5);printf("w向上，s向下，a向左，d向右，按空格射击");
    gotoxy(56,7);printf("A为您的战机"); 
    gotoxy(56,8);printf("@为敌机");
    gotoxy(2,21);printf("你的得分为%d",score);
    s[num].SCORE=score;
} 
 /*用循环控制敌机的飞行速度*/ 
void Fly()
{
     static int speed=0;
     if(speed<10) speed++;
     if(speed==10)   
     {
         if(e_y<h)   e_y++;
         else { e_y=0;e_x=2+rand()%w-2;}
        speed=0;
     }
}
void b_Fly()
{
     if(b_y>0)     b_y--;//控制子弹的飞行效果 
     if((b_y==e_y)&&(b_x==e_x))      {score++;e_y=0;e_x=2+rand()%w-2;b_y=0;}
}
/*控制飞机的移动*/ 
void Planefly() 
{
    char input;
    if(kbhit()) //kbhit函数是判断是否有输入 
    {
        input=getch(); //将输入的值传入input里面 
        if((input=='w')&&(p_y>1)) //如果按下wsad则相应移动飞机的位置 
        {
            p_y--;
        }
        if((input=='s')&&(p_y<h-2))
        {
            p_y++;
        }
        if((input=='a')&&(p_x>1))
        {
            p_x--;
        }
        if((input=='d')&&(p_x<w-2))
        {
            p_x++;
        }
        if((input==' ')&&(b_y==0))
        {
            b_x=p_x;
            b_y=p_y;
        }
    }
}          
void gameover(U *h)//游戏结束提示 
{
    system("cls");int a;
    gotoxy(39,14);printf("输入1继续打飞机，输入2结束游戏");
    scanf("%d",&a);
    switch(a)
    {
        case 1:{system("cls");}break;
        case 2:{system("cls");exit(0);}break;
        default:{system("cls");printf("请看清楚要求！");_getch();gameover(h);}break;
    }
} 
 
/*登入与注册*/ 
void iregister(U *h)
{
    char name[20];
    char mm[20];
    gotoxy(51,6);    printf("注册") ;
    gotoxy(39,11);     create(h);//注册
    gotoxy(39,16);
    printf("注册成功！！！(按任意键登入)\n");
    HideCursor();
    _getch();system("cls");
} 
void dengru(U *h,int num)
{
    char name[20];char mm[20];
o:  gotoxy(39,16);
    printf("请输入用户名：\n");
    gotoxy(39,17);
    scanf("%s",name);
    strcpy(s[num].NAME,name);//将用户名存入结构体数组 
    gotoxy(39,18);
    printf("请输入密码：\n");
    gotoxy(39,19);
    scanf("%s",mm);
    if(!search(h,name))  
    {
     system("cls");gotoxy(39,16);printf("没有该用户信息，请先注册！！！(按任意键继续)");
     _getch();system("cls") ;insert(h);system("cls"); goto o; 
    }
    U *temp=search(h,name);//判断密码 
    if(strcmp(temp->mm,mm)) 
    {system("cls");gotoxy(39,17);printf("密码错误，请重新输入！（按任意键继续）");_getch();system("cls") ;dengru(h,num);} 
    else{gotoxy(39,20);printf("登入成功!!!(按任意键开始游戏)");_getch();system("cls");} 
}   
void log_in(U *h) {
    FILE*fp;
    char name[20];char time[20];
    if ((fp = fopen("d:\\informeation storage.txt", "a+")) == NULL) {
        printf("文件不存在，创建成功");
    }
M:    gotoxy(36,9);
    printf("为了为您的账号签到，请再次输入账号\n");
    gotoxy(42,10);
    scanf("%s", name);
    if(!search(h,name))  {gotoxy(42,11);printf("输入错误，请重新输入");_getch();system("cls");goto M;    }
    fputs(name, fp);
    gotoxy(36,11);
    printf("请输入登入的时间\n");
    gotoxy(42,12);
    scanf("%s", time);
    fputs(time, fp);
    fclose(fp);
}
int main ()
{
    system("mode con cols=100 lines=30");  //创建宽100高30的程序界面大小
    U *head=(U*)malloc(sizeof(U)); //建立一个带头的链表 
    iregister(head); L:dengru(head,num);menu1(head,num);startup();//初始化
    while(1)
    {
        gotoxy(0,0);show();seescore(num);
        if(f==0)//判断飞机的状态 
        {
            gameover(head);s[num].SCORE=score;num++;if(num==10) num=1;
            msort(s,num+1);
            goto L;
        }
        b_Fly();Fly();Planefly(); 
    }
    return 0;
 } 
