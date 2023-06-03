#include<stdio.h>
#include<stdlib.h>
int stringLen(char *data){
	int len=0;
	while(data[len]){
		len++;
	}
	return len;
}

char *stringAssign(char *data,int len){
	int i;
	char *str=(char *)calloc(len,sizeof(char));
	for(i=0;i<=len;i++){
		str[i]=data[i];
	}
	return str;
}

void printString(char *data){
	int i=0;
	while(data[i]){
		printf("%c",data[i]);
		i++;
	}
	printf("\n");
}

void stringMatch(char *master,char *sub,int len2){
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
		printf("j=%d\n",j);
	}
	if(j == len2)printf("string match success.\n");
	else printf("string match failed.\n");
}

int main()
{
	int len1=stringLen("ababbabaabbaba");
	int len2=stringLen("abbaba") ;
	char *master=stringAssign("ababbabaabbaba",len1);
	char *sub=stringAssign("abbaba",len2);
	printf("len1=%d ",len1);
	printString(master);
	printf("len2=%d ",len2);
	printString(sub);
	stringMatch(master,sub,len2);
	return 0;
}
