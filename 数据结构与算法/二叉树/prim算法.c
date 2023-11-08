#include<stdio.h>
#include<string.h>
#define INF 0x7fffffff

typedef struct Edge{
    int start;//�ߵ����
    int weight;//�ߵ�Ȩֵ
}Edge;

/* vexΪ�ڵ����飬arcΪ�ڽӾ���indexָ��ĳ�ڵ���������ʾ�Ӹýڵ�������С������ */
void prim(char *vex,int **arc,int index){//prim�㷨Ϊ�ӵ㷨
	int vexNum = strlen(vex);//�ڵ���Ŀ
	Edge edge[vexNum];//edge[index]��¼��ǰ��ѡ�ڵ��е�index�ڵ����С��
    int i,j,dest;
    for(i = 0;i < vexNum;i++){
    	edge[i].start = index;//�ߵ���㶼Ϊindex�ڵ�
		edge[i].weight = arc[index][i];//��ʼ��edgeΪindex�ڵ㵽���ڵ��Ȩֵ
	}
	/*
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
			printf("%10d ",arc[i][j]);
		}
		putchar('\n');
	}
	*/
    for(i = 0;i < vexNum - 1;i++){//��vexNum - 1������뵽����
    	//ѡȡ��ǰ��ѡ�ڵ㵽���нڵ����̱�
		int min = 0x7fffffff;
        for(dest = 0;dest < vexNum;dest++){//����������destΪ�յ����С��
			if(edge[dest].weight != 0 && edge[dest].weight < min){
				index = dest;
				min = edge[dest].weight;
			}
		}
		printf("%c -> %c %d\n",vex[edge[index].start],vex[index],edge[index].weight);
		printf("edge��");
		
		//index�ڵ�������У�����edge����
		for(dest = 0;dest < vexNum;dest++){
			if(arc[index][dest] < edge[dest].weight){
				edge[dest].start = index;
				edge[dest].weight = arc[index][dest];
			}
			printf("%d ",edge[dest].weight);
		}
        printf("\n\n");
		
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
	prim("ABCDEF",arc,0);
	return 0;
}

