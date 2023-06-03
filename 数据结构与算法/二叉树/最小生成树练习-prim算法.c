#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
typedef struct Gragh{
	char *vex;
	int **arc;
	int vexNum;
	int arcNum;
}Gragh;

/* 这个结构体存储最小权值边的候选边 */
typedef struct Edge{
	char *vex;//记录候选边的起点
	int *weight;//边的权重,weight[index]表示vex指向第index个节点的边的权重
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

//参数G是为了获取图的边，index指定从哪个节点开始
Edge *initEdge(Gragh* G,int index){
	Edge *edge = (Edge *)malloc(sizeof(Edge));//这些边的终点始终依次为G中的各节点，例如edge[index]的终点为vex[index]
	edge->vex = (char *)malloc(sizeof(char) * G->vexNum);
	edge->weight = (int *)malloc(sizeof(int) * G->vexNum);
	int i;
	for(i = 0;i < G->vexNum;i++){
		edge->vex[i] = G->vex[index];//开始从index节点开始，index节点为所有候选边的起点
		edge->weight[i] = G->arc[index][i];//开始的候选边为index节点的所有边
	}
	return edge;
}

int getMin(Gragh* G,Edge *edge){
	int i,min = INF;
	int index;//index记录为edge中边的索引
	for(i = 0;i < G->vexNum;i++){
        if(edge->weight[i] != 0 && min > edge->weight[i]) {
        	min = edge->weight[i];
        	index = i;
		}
	}
	return index;
}//返回最小边终点在G中的索引

void prim(Gragh *G){
	Edge *edge  = initEdge(G,0);//从节点0开始找最小边
	int i,j,min;
	for(i = 0;i < G->vexNum - 1;i++){
		min = getMin(G,edge);
		printf("%c -> %c %d\n",edge->vex[min],G->vex[min],edge->weight[min]);
		/* 更新候选边 */
		/* 将G->vex[min]的指向节点0，1...G->vexNum的所有边与edge中此时记录的候选边比较 */
		/* 相同终点的边之间比较,将权值更小的边替换掉edge中的边 */
		for(j = 0;j < G->vexNum;j++){
			if(G->arc[min][j] < edge->weight[j]) {
				edge->vex[j] = G->vex[min];
				edge->weight[j] = G->arc[min][j];//替换成边vex[min]->vex[i];
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
	};//到自己为0，如果不连通为MAX
	int visited[6] = {0,0,0,0,0,0};
	Gragh *G = initGragh(6);
	createGragh(G,"ABCDEF",(int *)arcs);
 	dfs(G,0,visited);
	putchar('\n');
 	prim(G);
	return 0;
}

