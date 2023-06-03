#include<stdio.h>
#include <string.h>
int main() {
	char ch[101];
	int t,len,n,si=-1,j,i;
	char ct;
	scanf("%s",&ch);
	scanf("%d",&t);
	n = strlen(ch)-t;
	for(i = n;i > 0;--i)
	{
		++si;
		ct = 'Z';
		for(j = si;j < strlen(ch)-i+1;++j) {
			if(ch[j] < ct) {
				si = j;
				ct = ch[j];
			}
		}//»¬¶¯´°¿ÚËã·¨
		printf("%c",ch[si]);
	}
	return 0;

}
