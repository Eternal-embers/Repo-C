#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word{
	char Eng[15];
	char meaning[20];
	struct word *next;
}dict;

void menu(void){
	printf("************************************\n");
	printf(">>>>>>>>>>英语词典排版系统<<<<<<<<<<\n");
	printf("************************************\n");
	printf("      菜单:\n");
	printf("      录入- - - - - - - - - -N\n");
	printf("      删除- - - - - - - - - -D\n");
	printf("      浏览- - - - - - - - - -B\n");
	printf("      排序- - - - - - - - - -S\n");
	printf("      A-Z - - - - - - - - - -P\n");
	printf("      备份- - - - - - - - - -R\n");
	printf("      复习- - - - - - - - - -V\n");
	printf("      打字- - - - - - - - - -T\n"); 
	printf("      退出- - - - - - - - - -Q\n");
	printf("      >>");
}

int input(){
 	int n;
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary.txt","a"))==NULL){
		printf("----打开dictionary.txt失败!----\n");
		return 0;
	}
	printf("- - - - - - - - - - - - - - - - -\n");
	while(dict.Eng[0]!='#'){
		printf("单词：");
		scanf("%s",dict.Eng);
		printf("释义：");
		scanf("%s",dict.meaning); 
		fprintf(fp,"%15s%20s\n",dict.Eng,dict.meaning);
		printf("- - - - - - - - - - - - - - - - -\n");
	}
	while(getchar()!='\n')
		continue;
	fclose(fp);
	return 1;
}

void del(void){
	FILE *fp;
	int n = 0,i;
	struct word *p1,*p2,*head,*pre,*temp;
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("----打开dictionary.txt失败!----\n");
	return;
	}
	p1 = (struct word *)malloc(sizeof(struct word));
	fscanf(fp,"%20s%15s",p1->Eng,p1->meaning);
	printf("读取：\n*%s\n",p1->Eng);//测试 
	while(p1->Eng[0]!='#'){
		n++;
		if(n==1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct word *)malloc(sizeof(struct word));
		fscanf(fp,"%15s%20s\n",p1->Eng,p1->meaning);
		printf("*%s\n",p1->Eng);//测试 
	}
	p2->next = NULL;
	fclose(fp);
	p1 = head;//从链表头部逐个进行检查 
	printf("- - - - - - - - - - - - - - - - -\n");
	while(p1->next!=NULL){
		pre = p1;
		p2 = p1->next;
		//printf("@主串：%s\n",p1->Eng);//测试 
		while(p2!=NULL){
			//printf("$比较串：%s\n",p2->Eng);//测试 
			if(strcmp(p1->Eng,p2->Eng)==0)//如果发现重复的单词 
			{
				temp = p2;
				pre->next = p2->next;//删除结点 
				p2 = p2->next;
				free(temp);//释放空间 
				temp = NULL;
				continue; 
			}
			p2 = p2->next;
			pre = pre->next;
		}
		p1 = p1->next;
		//printf("- - - - - - - - - - - - - - - - -\n");//测试 
	}
	//将处理后的数据重新写入 
	if((fp = fopen("D:\\data\\dictionary.txt","w"))==NULL){
	printf("----打开dictionary.txt失败!----\n");
	return;
	}
	p1 = head;
	printf("写入：\n");
	while(p1!=NULL){
		printf(">>>%s %s\n",p1->Eng,p1->meaning);
		fprintf(fp,"%15s%20s\n",p1->Eng,p1->meaning);
		p1 = p1->next;
	}
	strcpy(dict.Eng,"#");
	strcpy(dict.meaning,"#");
	fprintf(fp,"%15s%20s",dict.Eng,dict.meaning);
	fclose(fp);
	printf("--------删除重复单词成功！--------\n");
	system("pause>NULL");//测试 
}

void scan(void){
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("--------打开dictionary.txt失败!--------\n");
	return;
	}	
	printf("单词                释义\n");
	while(dict.Eng[0]!='#'){
	fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
	printf("%-20s%-s\n\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
}

void sort(){
	FILE *fp;
	int n = 0;
	struct word *p1,*p2,*head,*pt,*pre,*_pre,*after;
	//_pre指向p1前一个结点，pre指向pt前一个结点 
	//after指向p1的后一个结点 
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("      ----打开dictionary.txt失败!----\n");
	return;
	}
	p1 = (struct word *)malloc(sizeof(struct word));
	fscanf(fp,"%15s%20s",p1->Eng,p1->meaning);
	//printf("*读取>>%s %s\n",p1->Eng,p1->meaning);//测试 
	while(p1->Eng[0]!='#'){
		n++;
		if(n==1) head = p1; 
		else p2->next = p1;
		p2 = p1;
		p1 = (struct word *)malloc(sizeof(struct word));
		fscanf(fp,"%15s%20s",p1->Eng,p1->meaning);
		//printf("*读取>>%s %s\n",p1->Eng,p1->meaning);//测试 
	}
	p2->next = NULL;
	fclose(fp);
	//头插法插入一个排序的头结点 
	//printf("@此时头结点：%s %s\n",head->Eng,head->meaning);//测试 
	//printf("&插入新的头结点:");//测试 
	pre = (struct word *)malloc(sizeof(struct word));
	strcpy(pre->Eng,"aaa"); 
	strcpy(pre->meaning,"头");
	pre->next = head;
	head = pre; 
	//printf("%s %s\n",head->Eng,head->meaning);
	printf("- - - - - - - -按A-Z进行排序- - - - - - - -\n");//测试 
	//选择排序
	_pre = head;
	p1 = head->next;//从头结点下一个开始 
	while(p1->next != NULL){
		//printf(" @ 选择位：%s\n",p1->Eng);//测试 
		p2 = p1->next; 
		pt = p1;
		//向后遍历找出单词的字典序最小的那个结点
		while(p2!=NULL){
			if(strcmp(pt->Eng,p2->Eng)>0) pt = p2;//如果单词字典序小于pt->Eng,结点地址赋给pt 
			p2 = p2->next; 
		}
		//printf(" $ 此轮循环的字典序最小词：%s\n",pt->Eng); 
		//找到单词为最小字典序的结点的前一个结点
		if(strcmp(pt->Eng,p1->next->Eng)==0)//如果单词字典序最小的结点在p1后一个结点 
		{
			strcpy(dict.Eng,pt->Eng);
			strcpy(dict.meaning,pt->meaning);
			strcpy(pt->Eng,p1->Eng);
			strcpy(pt->meaning,p1->meaning);
			strcpy(p1->Eng,dict.Eng);
			strcpy(p1->meaning,dict.meaning);
			printf("%s <- - - - -> %s\n",p1->Eng,pt->Eng);
			//printf("- - - - - - - - - - - - - - - - - - - - - -\n");//测试 
			_pre = _pre->next;
			p1 = pt;
			continue;
		}
		else if(strcmp(pt->Eng,p1->Eng)!=0){
			p2 = p1;
			//找出pt的前一个结点 
			while(p2!=NULL){
				if(strcmp(p2->next->Eng,pt->Eng)==0){
					pre = p2;
					break;
				}
			p2 = p2->next;
			}
			//交换结点位置
			if(p1->next==NULL) after = NULL;
				else after = &(*(*p1).next);
			//将p1移动到pt的位置 
			p1->next = pt->next;
			pre->next = p1;
			//将pt移动到p1的位置
			pt->next = &(*after);
			_pre->next = pt;
			printf("%s <- - - - -> %s\n",_pre->next->Eng,pre->next->Eng);//测试 
		}
		_pre = _pre->next;//记录p1前一个结点 
		p1 = pt->next;
		//printf("pt->next->Eng:%s\n",pt->next->Eng);//测试 
		//printf("- - - - - - - - - - - - - - - - - - - - - -\n");//测试 
		//system("pause>NULL");//测试 
	}
	printf("- - - - - - - - - - - - - - - - - - - - - -\n");
	//将排序好的数据存储到文件中
	if((fp = fopen("D:\\data\\dictionary_sort.txt","w"))==NULL){
	printf("----打开dictionary_sort.txt失败!----\n");
	return;
	}
	p1 = head->next;
	printf("写入：\n");
	while(p1!=NULL){
		printf(">>>%s %s\n",p1->Eng,p1->meaning);//测试
		fprintf(fp,"%15s%20s\n",p1->Eng,p1->meaning); 
		p1 = p1->next;
	}
	strcpy(dict.Eng,"#");
	strcpy(dict.meaning,"#");
	fprintf(fp,"%14s%20s",dict.Eng,dict.meaning);
	fclose(fp);
	printf("-------按A-Z存储字典成功!-------\n");
}

void print_sort(void){
	FILE *fp;
	if((fp = fopen("D:\\data\\dictionary_sort.txt","r"))==NULL){
	printf("----打开dictionary_sort.txt失败!----\n");
	return;
	}
	printf("       单词                  释义\n");
	while(dict.Eng[0]!='#'){
	fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
	printf("%15s%20s\n\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
	printf("--------打印成功!--------\n");
} 

void reserve(void){
	FILE *fp,*f;
	if((f = fopen("D:\\data\\dictionary_sort.txt","r"))==NULL){
	printf("----打开dictionary_sort.txt失败!----\n");
	return;
	}
	if((fp = fopen("D:\\data\\back_up.txt","w"))==NULL){
	printf("----打开back_up.txt失败!----\n");
	return;
	}
	while(dict.Eng[0]!='#'){
		fscanf(f,"%15s%20s",dict.Eng,dict.meaning);
		printf("%15s\n",dict.Eng);
		fprintf(fp,"%15s%20s\n",dict.Eng,dict.meaning);
	}
	fclose(fp);
	fclose(f);
	printf("--------备份成功--------\n");
}

void review(void){
	FILE *fp;
	char option[6];
	int i,count,add; 
	system("cls");
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("------打开dictionary.txt失败!------\n");
	return;
	}
	printf("亲，请选择您要复习的单词个数：\n>>");
	scanf("%d",&count);
	for(i = 0;i<count;i++){
		printf(">>>已复习：%d\n",i);
		fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
		printf("单词：%s\n",dict.Eng);
		system("pause>NULL");
		printf("释义:%s\n",dict.meaning); 
		system("pause>NULL");
		system("cls");
	}
	printf("亲，您已经复习了%d个单词\n",count);
	while(1){
		printf("您是否还要继续复习接下来的单词呢？(Y/N)\n如果您要重新复习前面的单词，请跟我说\"好的\"\n>>");
		scanf("%s",option);
		while(getchar()!='\n')
			continue;
		if(option[0]=='Y') {
			printf("亲，请选择您要复习的单词个数：\n>>");
			scanf("%d",&add);
			for(i = 0;i<add;i++){
				printf(">>>已复习：%d\n",i);
				fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
				printf("单词：%s\n",dict.Eng);
				system("pause>NULL");
				printf("释义:%s\n",dict.meaning);
				system("pause>NULL");
				system("cls");
			}
			count+=add;
			printf("恭喜您已复习了%d个单词\n",count);
		}
		else if(strcmp(option,"好的")==0){
			fclose(fp);
			if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
			printf("------打开dictionary.txt失败!------\n");
			return;
			}
			printf("亲，请选择您要复习的单词个数：\n>>");
			scanf("%d",&count);
			for(i = 0;i<count;i++){
				printf(">>>已复习：%d\n",i);
				fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
				printf("单词：%s\n",dict.Eng);
				system("pause>NULL");
				printf("释义:%s\n",dict.meaning); 
				system("pause>NULL");
				system("cls");
			}
			printf("亲，您已经复习了%d个单词\n",count);
		} 
		else {
			printf("感谢亲的光顾，欢迎下次光临!\n");
			return;
		}
	}
}

void typing(void){
	FILE *fp;
	char option[3],prac[20],_prac[20];
	int i,num;
	float t = 0.0;
	system("cls");
	if((fp = fopen("D:\\data\\dictionary.txt","r"))==NULL){
	printf("------打开dictionary.txt失败!------\n");
	return;
	}
	printf("亲，欢迎您使用打字系统，请选择模式(英文/中文/中英):\n");
	printf("英文- - - - - - - - - - - - - -En\n");
	printf("中文- - - - - - - - - - - - - -Ch\n");
	printf("中英- - - - - - - - - - - - - -EC\n>>");
	scanf("%s",option);
	while(getchar()!='\n')
		continue;
	if(strcmp(option,"En")==0){
		printf("亲，请输入您需要练习的单词数:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s\t",dict.Eng);
			scanf("%s",prac);
			while(getchar()!='\n')
				continue;
			if(strcmp(prac,dict.Eng)==0) t++;
		}
		printf("亲，您的正确率是%.2f%%,正确拼写%.0f个，错误拼写%d个\n",(100*t)/num,t,num-t);
	}
	else if(strcmp(option,"Ch")==0){
		printf("亲，请输入您需要练习的单词数:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s\t",dict.meaning);
			scanf("%s",prac);
			while(getchar()!='\n')
				continue;
			if(strcmp(prac,dict.meaning)==0) t++;
		}
		printf("亲，您的正确率是%.2f%%,正确拼写%.0f个，错误拼写%d个\n",(100*t)/num,t,num-t);
	}
	else{
		printf("亲，请输入您需要练习的单词数:\n>>");
		scanf("%d",&num);
		for(i = 0;i<num;i++){
			fscanf(fp,"%15s%20s",dict.Eng,dict.meaning);
			printf("%s %s\t",dict.Eng,dict.meaning);
			scanf("%s%s",prac,_prac);
			while(getchar()!='\n')
				continue;
			printf("- - - - - - - - - - - - - - - - - - - - -\n");
			if(strcmp(prac,dict.Eng)==0 && strcmp(_prac,dict.meaning)==0) t++;
		}
		printf("亲，您的正确率是%.2f%%,正确拼写%.0f个，错误拼写%d个\n",(100*t/num),t,num-t);
	}
	printf("亲,打字练习结束！欢迎您再次光临\n");
	system("pause>NULL");
}

int main(){
	char option;
	while(1){
		menu();
		scanf("%c",&option);
		getchar();
		switch(option){
		case 'N':
		if(input()==1)printf("--------录入成功!--------\n");
			else printf("--------录入失败!--------\n");
		break;
		case 'D':del();break;
		case 'B':scan();break;
		case 'S':sort();break;
		case 'P':print_sort();break;
		case 'R':reserve();break;
		case 'V':review();break;
		case 'T':typing();break;
		case 'Q':printf("\n---------感谢您的使用!---------\n");return 0;
		default:
		printf("----选项输入错误，请重新输入!----\n");
		while(getchar()!='\n')
			continue;
		}
	}
}
