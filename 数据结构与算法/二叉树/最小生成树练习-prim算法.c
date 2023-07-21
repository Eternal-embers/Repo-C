#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
typedef struct Gragh{
	char *vex;
	int **arc;
	int vexNum;
	int arcNum;
}Gragh;

/* ����ṹ��洢��СȨֵ�ߵĺ�ѡ�� */
typedef struct Edge{
	char *vex;//��¼��ѡ�ߵ����
	int *weight;//�ߵ�Ȩ��,weight[index]��ʾvexָ���index���ڵ�ıߵ�Ȩ��
}Edge;

Gragh* initGragh(int vexNum){
	Gragh *G = (Gragh *)malloc(sizeof(Gragh));
	G->vex = (char *)malloc(sizeof(char) * vexNum + 1);
	G->arc = (int **)malloc(sizeof(int *) * vexNum + 1);
	int i;
	for(i = 0;i < vexNum;i++){
		G->arc[i] = (int *)malloc(sizeof(int) * vexNum + 1);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGragh(Gragh *G,char *vex,int *arcs){
	int i,j;
	for(i = 0;i < G->vexNum;i++){
		G->vex[i] = vex[i];
		for(j = 0;j < G->vexNum;j++){
			//printf("%c -> %c %d\n",vex[i],vex[j],*(arcs + G->vexNum * i + j));
			G->arc[i][j] = *(arcs + G->vexNum * i + j);
			if(G->arc[i][j] != 0 && G->arc[i][j] != INF) G->arcNum++;
		}
	}
	G->arcNum /= 2;
}

void dfs(Gragh *G,int index,int *visited){
	if(visited[index] == 0){
		printf("%c ",G->vex[index]);
		visited[index] = 1;
		int i;
		for(i = 0;i < G->vexNum;i++){
			if(G->arc[index][i] != 0 && G->arc[index][i] != INF){
				dfs(G,i,visited);
			}
		}
	}
}

//����G��Ϊ�˻�ȡͼ�ıߣ�indexָ�����ĸ��ڵ㿪ʼ
Edge *initEdge(Gragh* G,int index){
	Edge *edge = (Edge *)malloc(sizeof(Edge));//��Щ�ߵ��յ�ʼ������ΪG�еĸ��ڵ㣬����edge[index]���յ�Ϊvex[index]
	edge->vex = (char *)malloc(sizeof(char) * G->vexNum);
	edge->weight = (int *)malloc(sizeof(int) * G->vexNum);
	int i;
	for(i = 0;i < G->vexNum;i++){
		edge->vex[i] = G->vex[index];//��ʼ��index�ڵ㿪ʼ��index�ڵ�Ϊ���к�ѡ�ߵ����
		edge->weight[i] = G->arc[index][i];//��ʼ�ĺ�ѡ��Ϊindex�ڵ�����б�
	}
	return edge;
}

int getMin(Gragh* G,Edge *edge){
	int i,min = INF;
	int index;//index��¼Ϊedge�бߵ�����
	for(i = 0;i < G->vexNum;i++){
        if(edge->weight[i] != 0 && min > edge->weight[i]) {
        	min = edge->weight[i];
        	index = i;
		}
	}
	return index;
}//������С���յ���G�е�����

void prim(Gragh *G){
	Edge *edge  = initEdge(G,0);//�ӽڵ�0��ʼ����С��
	int i,j,min;
	for(i = 0;i < G->vexNum - 1;i++){
		min = getMin(G,edge);
		printf("%c -> %c %d\n",edge->vex[min],G->vex[min],edge->weight[min]);
		/* ���º�ѡ�� */
		/* ��G->vex[min]��ָ��ڵ�0��1...G->vexNum�����б���edge�д�ʱ��¼�ĺ�ѡ�߱Ƚ� */
		/* ��ͬ�յ�ı�֮��Ƚ�,��Ȩֵ��С�ı��滻��edge�еı� */
		for(j = 0;j < G->vexNum;j++){
			if(G->arc[min][j] < edge->weight[j]) {
				edge->vex[j] = G->vex[min];
				edge->weight[j] = G->arc[min][j];//�滻�ɱ�vex[min]->vex[i];
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
	int visited[6] = {0,0,0,0,0,0};
	Gragh *G = initGragh(6);
	createGragh(G,"ABCDEF",(int *)arcs);
 	dfs(G,0,visited);
	putchar('\n');
 	prim(G);
	return 0;
}

