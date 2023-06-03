#include<stdio.h>
#include<string.h>
int main(){
	int count;
	char str[20];
	FILE *fp;
	fp = fopen("D:\\data\\À¶ÇÅ±­.txt","r");
	fscanf(fp,"%s",str);
	while(str[0]!='#'){
		if(str[0]=='#'){
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
			break;
		}
		if(str[0]=='$'){
			count = 0;//¼ÆÊýÆ÷ 
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
			printf("%s\n",str);
		}
			else {
				printf("%20s",str);
				count++;
				if(count%5==0)printf("\n\n");
			}
		fscanf(fp,"%s",str);
	}
	return 0;
}
