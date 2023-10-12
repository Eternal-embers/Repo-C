/*
	Name: 虚位密码技术
	Copyright:劣等生
	Author:劣等生
	Date: 10/05 09:58
	Description:
*/
#include<stdio.h>

_Bool verify(char *password,char *text){
	int i = 0,j = 0;
	while(text[i] != '\0' && password[j] != '\0'){
		if(text[i] == password[j]) {
			i++;
			j++;
		}
		else{
			i = i - j + 1;
			j = 0;
		}
	}
	if(password[j] == '\0') return 1;
	else return 0;
}

int main(){
	char password[12] = "210503";
	char text[20];
	scanf("%s",text);
	printf("%s",verify(password,text) ? "密码匹配成功" : "密码不匹配");
	return 0;
}


