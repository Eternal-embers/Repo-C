#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

typedef struct graph{
	char* vex;
	int** arc;
	int vexNum;
	int arcNum;
}Graph;

Graph *initGragh(int vexNum){
	Graph *G = (Graph *)malloc(sizeof(Graph));
	G->vex = (char *)malloc(sizeof(char) * vexNum);
	G->arc = (int **)malloc(sizeof(int *) * vexNum);
	int i;
	for(i = 0;i < vexNum;i++){
		G->arc[i] = (int *)malloc(sizeof(int) * vexNum);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph *G,char *vexs,int *arcs){
	int i,j;
	for(i = 0;i < G->vexNum;i++){
		G->vex[i] = vexs[i];
		for(j = 0;j < G->vexNum;j++){
			G->arc[i][j] = *(arcs + i * G->vexNum + j);
			if(G->arc[i][j] != INF && G->arc[i][j] != 0)
				G->arcNum++;
		}
	}
	G->arcNum /= 2;
}

void dfs(Graph *G,int *visited,int index){
	if(visited[index] == 0){
		printf("%c ",G->vex[index]);
		visited[index] = 1;
		int i;
		for(i = 0;i < G->vexNum;i++){
			if(G->arc[index][i] != INF && G->arc[index][i] != 0)
				dfs(G,visited,i);
		}
 	}
}

void dijkstra(Gragh *G){
	int D[G->vexNum];
}
int main(){
	Graph *G = initGragh(7);
	int arcs[7][7] = {
        0, 12, INF,INF,INF,16, 14,
        12, 0, 10, INF, INF, 7, INF,
        INF, 10, 0, 3, 5, 6, INF,
        INF, INF, 3, 0, 4, INF, INF,
        INF, INF, 5, 4, 0, 2, 8,
        16, 7, 6, INF, 2, 0, 9,
        14, INF, INF, INF, 8, 9, 0
    };
    int visited[7] = {0,0,0,0,0,0,0};
	createGraph(G,"ABCDEFG",(int *)arcs);
	dfs(G,visited,0);
	return 0;
}

