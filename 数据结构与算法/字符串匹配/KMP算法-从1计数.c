#include<stdio.h>
#include<stdlib.h>
int main()
{
	char s[50]="0bbaaaabbababbabaaabbbabbaabababa";
	char s1[10]="0bababa";
	int len=0,len1=0,next[10];
	int i=1,j=0,k;
	while(s[len]){
		len++;
	}
	while(s1[len1]){
		len1++;
	}
	len--;;
	len1--;
	printf("len=%d,len1=%d\n",len,len1);
	//ÇónextÊý×é
	next[1]=0;
	while(i<len1)
	{
		printf("%c %c ",s1[i],s1[j]);
	 	if(j==0 || s1[i]==s1[j]){
	 		next[++i]=++j;
		 }
		 else j=next[j];
		 printf("next[%d]=%d\n",i,next[i]);
	}
	i=1;
	j=1;
	//kmp
	while(i<=len && j<=len1){
		printf("j=%d ",j);
		if(j==1 || s[i]==s1[j]){
			i++;
			j++;
		}
		else {
		j = next [j];
		printf("j=%d",j);
		}
		printf("\n");
	}
	if(j==len1+1){
	printf("kmp match success.\n");
	for(k=i-j+1;k<=len;k++)
	printf("%c",s[k]);
	}
	else printf("kmp match failed\n");
	return 0;
}
