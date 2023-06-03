#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define PIN_addr "D:\\data\\密码管理系统\\PIN_info.txt"
struct password{
    char name[20];
    char account[20];
    char PIN[20];
    struct password *next;
}local;
int n = 0;

struct password *input(void)
{
    struct password *p1,*p2,*head;
    p1=(struct password *)malloc(sizeof(struct password));
    printf("\n\t------输入#结束输入------\n");
    printf("      name        account         PIN\n");
    printf(">> ");
    scanf("%s%s%s",p1->name,p1->account,p1->PIN);
    if(p1->name[0] == '#')
    	return;
    while(1){
        n++;
        if(n == 1)head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct password *)malloc(sizeof(struct password));
        printf(">> ");
  		scanf("%s%s%s",p1->name,p1->account,p1->PIN);
    	if(p1->name[0] == '#') break;
    }
     printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    p2->next = NULL;
    system("pause>NULL");
    return head;
}

void print(struct password *p)
{
	if(p==NULL){
		printf("                不存在任何输入信息\n");
		system("pause>NULL");
		system("cls");
		return;
	}
    printf("                name            account               PIN\n");
    while(p){
        printf("%20s%20s%20s\n\n",p->name,p->account,p->PIN);
        p = p->next;
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    system("pause>NULL");
}

void save(struct password *p){
	if(p==NULL){
		printf("                不存在可保存的输入信息\n");
		system("pause>NULL");
		system("cls");
		return;
	} 
	struct password *head = p;
	FILE *fp = fopen(PIN_addr,"a+");
    while(p){
    	fprintf(fp,"%s %s %s\n",p->name,p->account,p->PIN);
    	p = p->next;
    }
    printf("                save file success\n");
    p = head;
    while(p){
		head = head->next;
		free(p);
		p = head;
	}
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    fclose(fp);
    system("pause>NULL");
}

//int readnum(void){
//	FILE *f = fopen(PIN_addr,"r");;
//	int num;
//  fscanf(f,"%d",&num);
//  return num;
//}

struct password *read(void){
	FILE *fp = fopen(PIN_addr,"a+");
	printf("                 name            account               PIN\n");
	fscanf(fp,"%s%s%s",local.name,local.account,local.PIN);
	while(!feof(fp)){
	printf(" %20s%20s%20s\n\n",local.name,local.account,local.PIN);
	fscanf(fp,"%s%s%s",local.name,local.account,local.PIN);
	}
	printf("                read file success\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fclose(fp);
	system("pause>NULL");
}

/* 获取字符串的长度 */
int getLength(char *str){
	int i = 0;
	int length = 0;
	while(str[i++] != '\0'){
		length++;
	}
	return length;
}

_Bool stringMatch(char *master,char *sub,int length){
	int i=0,j=0;
	while(master[i] && sub[j]){
		if(master[i] == sub[j]){
			i++;
			j++;
		}
		else {
			i=i-j+1;
			j=0;
		}
	}
	if(j == length) return 1;
	else return 0;
}

void search (void){
	_Bool flag = 0;
	char str[30];
	int length;
	printf("\n>>>");
	scanf("%s",str);
	length = getLength(str);
	FILE *fp = fopen(PIN_addr,"a+");
	printf("                 name            account               PIN\n");
	while(!feof(fp)){
		fscanf(fp,"%s%s%s",local.name,local.account,local.PIN);
		if(stringMatch(local.name,str,length) || stringMatch(local.account,str,length)) {
			printf(" %20s%20s%20s\n\n",local.name,local.account,local.PIN);
			flag = 1;
		}
	}
	if(flag == 0) printf("                无搜索结果\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fclose(fp);
	system("pause>NULL");
}
int main()
{
	//登陆身份验证
	char name[20],PIN[20],ch;
	int i;
	start:
	printf("\n\n\n\n\n\n\n");
	printf("    ________________________________________________\n");
	printf("    |>>>>>>>>>>>>>> 密码信息管理系统 <<<<<<<<<<<<<<|\n");
	printf("    |                                              |\n");
	printf("    |                                              |\n");
 	printf("    |                                              |\n");
	printf("    |                                              |\n");
	printf("    |            欢迎您使用密码管理系统！          |\n");
	printf("    |                作者：劣等生                  |\n");
   	printf("    |                                              |\n");
	printf("    |                                              |\n");
	printf("    |                                              |\n");
	printf("    |______________________________________________|\n");
	printf("                        >>start");
	system("pause>NULL");
	system("cls");
	printf("\n\n\n\n\n\t\t请输入用户名：");
	scanf("%s",name);
	if(strcmp(name,"kv")!=0) {
		system("cls");
		printf("\n\n\n\n\n\t\t用户名错误!");
		system("pause>NULL");
		system("cls");
		goto start;
	}
	while(getchar()!='\n');
	printf("\t\t请输入密钥：");
	ch = getch();
	printf("*");
	i = 0;
	do{
		PIN[i++] = ch;
		ch = getch();
		if(ch == '\r') break;
	 	printf("*");
	}while(i < 20);
	PIN[i] = '\0';
	if(strcmp(PIN,"kv")!=0) {
		system("cls");
		printf("\n\n\n\n\n\t\t密钥错误!");
		system("pause>NULL");
		system("cls");
		goto start;
	}
	system("cls");
	//密码系统
    struct password *head = NULL;
    struct password *_head = NULL;
    char option;
    //int num = readnum();
    while(1){
    	printf("\n\n\n");
        printf("________________________________________________________________________\n");
        printf("|                                                                      |\n");
        printf("|>>>>>>>>>>>>>>>>>>>>>>>>>>>>  PIN system  <<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n");
  	    printf("|______________________________________________________________________|\n\n");
   		printf("                 菜单:\n");
  	 	printf("                 0.退出- - - - - - - - - - -0\n\n");
    	printf("                 1.输入- - - - - - - - - - -1\n\n");
   		printf("                 2.检查输入- - - - - - - - -2\n\n");
   		printf("               	 3.保存- - - - - - - - - - -3\n\n");
  	  	printf("                 4.查看- - - - - - - - - - -4\n\n");
   		printf("                 5.搜索- - - - - - - - - - -5\n\n");
    	printf("                 6.查看输入格式- - - - - - -6\n\n");
    	printf(">>");
    	scanf("%c",&option);
    	switch (option)
    	{
    		case '0':return 0;
    		case '1':head=input();break;
    		case '2':print(head);break;
    		case '3':save(head);break;
    		case '4':read();break;
    		case '5':search();break;
    		case '6':printf("[名称]+[账号]+[密码]\n某些特殊情况会有文字提示\n");break;
    		default :printf("                选项错误，请重新输入\n");
		}
		while(getchar()!='\n')continue;
	}
}
