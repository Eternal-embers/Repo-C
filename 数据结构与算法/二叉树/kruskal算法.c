/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description:
*/
#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
#define INF 0x7fffffff

typedef struct Edge{
	int start;//���
	int end;//�յ�
	int weight;//Ȩֵ
}Edge;

void kruskal(char *vex,int **arc,int index){
	int vexNum = strlen(vex);//�ڵ���Ŀ
	int connect[vexNum];//��ͨ����
	int i,j,arcNum = 0;
	
	//��ȡ����
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
			if(arc[i][j] != 0 && arc[i][j] != INF)
				arcNum++;
		}
	}
	
	//��ʼ����ͨ����
	for(i = 0;i < vexNum;i++)
		connect[i] = i;//��ʼ���ڵ����ͨ�������ڱ���
		
	Edge edge[arcNum],t;//�ߵļ���
	int cnt = 0;
	//��ʼ����
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
   			if(arc[i][j] != 0 && arc[i][j] != INF){
				edge[cnt].start = i;
				edge[cnt].end = j;
				edge[cnt].weight = arc[i][j];
				cnt++;
   			}
		}
	}
	
	/*
	for(i = 0;i < arcNum;i++){
		printf("%c->%c %d\n",vex[edge[i].start],vex[edge[i].end],edge[i].weight);
	}
	*/

	
	//�������򣬶Աߵļ��ϰ���С��������
	for(i = 1;i < arcNum;i++){
		t = edge[i];
		for(j = i - 1;j >= 0;j--){
			if(t.weight < edge[j].weight) //���Ųλ
				edge[j + 1] = edge[j];
			else break;
		}
		edge[j + 1] = t;
	}
	
	for(i = 0;i < arcNum;i++)
		printf("%d ",edge[i].weight);
	putchar('\n');
	
	//kruskal�㷨ʵ����С������
	for(i = 0;i < arcNum;i++){
		//��ȡ��ʼ�ߵ������յ����ͨ����
        int start = connect[edge[i].start];
        int end = connect[edge[i].end];
		if(start != end){ //��ͨ������ͬ���γɻ�
			printf("%c->%c %d\n",vex[edge[i].start],vex[edge[i].end],edge[i].weight);
			//��������ͨ����Ϊend�Ľڵ����ͨ��������Ϊvex[start]
			for(j = 0;j < vexNum;j++){
				if(connect[j] == end)
					connect[j] = start;//��ʾ��end�ڵ�Ϊ��ͨ�����Ľڵ���뵽��������
			}
		}
	}
}

int main(){
	int arcs[6][6] = {
		  0,  6,  1,  5,INF,INF,
		  6,  0,  5,INF,  3,INF,
		  1,  5,  0,  5,  6,  4,
		  5,INF,  5,  0,INF,  2,
	  	INF,  3,  6,INF,  0,  6,
	  	INF,INF,  4,  2,  6,  0
	};//���Լ�Ϊ0���������ͨΪINF
	int *p[6];
	int i;
	for(i = 0;i < 6;i++)
		p[i] = (int *)arcs[i];
	int **arc= p;
 	kruskal("ABCDEF",arc,0);
	return 0;
}

