#include<stdio.h>

int a[200005] = {0};
int res[200005] = {0};
int del[100000] = {0};
int len1 = 0,len2 = 0;
int n;

int main(){
	int i,j,k,out;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < n;i++){
		int flag = 0;
		out = -5;
		for(j = 0;j < len;j++){ //�жϼ���a[i]�Ƿ�Ϸ�
			if( !(a[i] == a[res[j]]) && !(i + 1 < n && a[i + 1] == a[res[j + 1]]) ){
				out = res[j];//��¼��ɲ��Ϸ�������
				for(k = 0;k < len2;k++){//�ж��Ƿ���ɾ��������
					if(del[k] == out) {
						flag = 1;
						break;
					}
				}
				if(!flag) break;
			}
		}
		if(out == i - 1){//����ǵ�ǰ��������ǰһ��Ԫ����ɵĲ��Ϸ�������ɾ����Ԫ��
			del[len2] = out;
			len2++;
		}
		if(j >= len) {
			res[len] = i;
			len++;
		}
  		else {
			if(j - res[len - 1] >= 2){
				len = 0;
				break;//���ּ�����Ϸ�
			}
		}
	}
	if(len > 0){
		printf("%d\n",len);
		for(i = 0;i < len;i++){
			printf("%d ",res[i] + 1);
		}
	}
	else
		printf("NO");
	return 0;
}

