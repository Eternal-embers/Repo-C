/*
	Name: ����ȡ��
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 09/17 13:48
	Description:
*/
#include<stdio.h>

int M[205][205] = {0};//����
int vis[205][205] = {0};//���ʼ�¼
//���������������任
int dx[4] = {0,1,0,-1};//ˮƽ����
int dy[4] = {1,0,-1,0};//��ֱ����

int main(){
	int m,n;//m,nС��200,mΪ������nΪ����
	int i,j;
	scanf("%d %d",&m,&n);
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&M[i][j]);
		}
	}
	i = 0,j = 0;//�����Ͻǿ�ʼ
	int dir = 0;//��ʼ�������£���������ֱ��Ӧ����0��1��2��3
	int sum = m * n;
	printf("%d",M[i][j]);
	vis[i][j] = 1;
	i += dy[dir],j += dx[dir];//ѭ�������Ͻ���һ����ʼ
	int cnt = 1;
	while(cnt < sum){
		//�������Ϸ�λ��
		while(i < 0 || i >= m || j < 0 || j >= n){
				//���˵���һ��λ��
				i -= dy[dir];
				j -= dx[dir];
				//��ת
				dir += 1;
            	dir %= 4;
				//������һ��λ��
				i += dy[dir];
				j += dx[dir];
		}
		//�ж��Ƿ���ʹ�
		if(!vis[i][j]){
			printf(" %d",M[i][j]);
			cnt++;//����
			vis[i][j] = 1;//��¼����
			i += dy[dir];
			j += dx[dir];
		}
        else{
        	//���˵���һ��λ��
			i -= dy[dir];
			j -= dx[dir];
			//��ת
			dir += 1;
            dir %= 4;
			//������һ��λ��
			i += dy[dir];
			j += dx[dir];
		}
	}
	return 0;
}

/*
	����1,���1~25
	5 5
	1 16 15 14 13
	2 17 24 23 12
	3 18 25 22 11
	4 19 20 21 10
	5  6  7  8  9
 */

