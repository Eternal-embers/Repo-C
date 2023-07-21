#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

typedef struct Graph{
	char *vex;
	int **arc;
	int vexNum;
	int arcNum;
}Graph;

typedef struct Edge{
	int start;
	int end;
	int weight;
}Edge;

Graph *initGraph(int vexNum){
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
			G->arc[i][j] = *(arcs + G->vexNum * i + j);
			if(G->arc[i][j] != 0 && G->arc[i][j] != INF)
				G->arcNum++;
		}
	}
	G->arcNum /= 2;
}

void dfs(Graph *G,int index,int *visited){
	if(visited[index] == 0){
		printf("%c ",G->vex[index]);
		visited[index] = 1;
		int i;
		for(i = 0;i < G->vexNum;i++){
			if(G->arc[index][i] != 0 && G->arc[index][i] != INF)
				dfs(G,i,visited);
		}
	}
}

Edge *initEdge(Graph *G){
	Edge *edge = (Edge *)malloc(sizeof(Edge) * G->arcNum);
	int i,j,index = 0;
	for(i = 0;i < G->arcNum;i++)
		edge[i].weight = INF;
	for(i = 0;i < G->vexNum - 1;i++){
		//j从i + 1开始计数能有效避免选取重复的边，因为邻接矩阵沿对角线对称
		//j从i+1计数，最终选取的边数是G->arcNum,不会选取重复的边
		for(j = i + 1;j < G->vexNum;j++){
			if(G->arc[i][j] != INF){
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->arc[i][j];
				index++;
			}
		}
	}
	return edge;
}

void sortEdge(Graph *G,Edge *edge){
	Edge temp;
	int i,j;
	for(i = 1;i < G->arcNum;i++){
		temp = edge[i];
		for(j = i - 1;j >= 0;j--){
			if(temp.weight < edge[j].weight) edge[j + 1] = edge[j];
				else break;
		}
		edge[j + 1] = temp;
	}
}

void kruskal(Graph *G){
	int i,j,start,end;
	int connected[G->vexNum];//连通分量
	for(i = 0;i < G->vexNum;i++){
		connected[i] = i;
	}
	Edge *edge = initEdge(G);
	sortEdge(G,edge);
	for(i = 0;i < G->arcNum;i++){
		start = connected[edge[i].start];//边edge[i]起点的连通分量
		end = connected[edge[i].end];//边edge[i]终点的连通分量
		if(start != end){
			printf("%c -> %c weight = %d\n",G->vex[edge[i].start],G->vex[edge[i].end],edge[i].weight);
			for(j = 0;j < G->vexNum;j++){
				if(connected[j] == end)
					connected[j] = start;
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
	};
	int visited[6] = {0,0,0,0,0,0};
	Graph *G = initGraph(6);
 	createGraph(G,"ABCDEF",(int *)arcs);
 	dfs(G,0,visited);
	putchar('\n');
	kruskal(G);
	return 0;
}

