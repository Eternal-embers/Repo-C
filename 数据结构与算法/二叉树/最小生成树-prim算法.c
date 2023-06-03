#include <stdio.h>
#include <stdlib.h>

/**
 * 图顶点之间不通，那么邻接矩阵的值为MAX
 * 如果顶点是自己本身，那么值为0
 */
#define MAX 32767

typedef struct Graph {
    char* vexs;//指向结点数组
    int** arcs;//指向邻接矩阵的二维数组
    int vexNum;//节点个数
    int arcNum;//边数
}Graph;

//记录U集合的信息
typedef struct Edge {
    char vexs;//记录U集合到最小边的起始节点
    int weight;//记录最小边
}Edge;

/*
 * 当edge.weight = 0时，代表顶点加入到U集合中
 */
Edge* initEdge(Graph* G, int index) {
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G -> vexNum);//总共vexnum条最小边
    int i;
    for (i = 0; i < G ->vexNum; i++) {
        edge[i].vexs = G -> vexs[index];
        edge[i].weight = G -> arcs[index][i];
    }
    return edge;
}//将index所代表的节点加入U集合中

int getMinEdge(Edge* edge, Graph* G) {
    int index;
    int min = MAX;
    int i;
    /* 找一条最小权值的边 */
    for (i = 0; i < G -> vexNum; i++) {
    	//当前节点没有加入U集合且最小值大于此边的权重
        if (edge[i].weight != 0 && min > edge[i].weight) {
            min = edge[i].weight;
            index = i;
        }
    }
    return index;
}//返回终点节点

//以节点index创建最小生成树
void prim(Graph* G, int index) {
    int min;
    int i,j;
    Edge* edge = initEdge(G, index);
    for(j = 0;j < G->vexNum;j++){
        	printf("v%c->v%c %d\tv%c->v%c %d\n",edge[j].vexs,G->vexs[j],edge[j].weight,G->vexs[min],G->vexs[j],G->arcs[min][j]);
	}
    for (i = 0; i < G -> vexNum - 1; i++) {
        min = getMinEdge(edge, G);
        printf("v%c --> v%c, weight = %d\n", edge[min].vexs, G -> vexs[min], edge[min].weight);
        edge[min].weight = 0;
        //将edge用来记录min节点的状态
        for (j = 0; j < G -> vexNum; j++) {
            if (G -> arcs[min][j] < edge[j].weight) {//如果min->j的权值小于此时edge中记录的到j节点的权值
                edge[j].weight = G -> arcs[min][j];//将edge中的到各节点的权值替换为min节点到各节点的权值
                edge[j].vexs = G -> vexs[min];//将节点替换成min节点
            }
        }
        for(j = 0;j < G->vexNum;j++){
        	printf("v%c->v%c %d\tv%c->v%c %d\n",edge[j].vexs,G->vexs[j],edge[j].weight,G->vexs[min],G->vexs[j],G->arcs[min][j]);
		}
		printf("\n");
    }
}

Graph* initGraph(int vexNum) {
	int i;
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G -> vexs = (char*)malloc(sizeof(char) * vexNum);
    G -> arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (i = 0 ; i < vexNum; i++) {
        G -> arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G -> vexNum = vexNum;
    G -> arcNum = 0;
    return G;
}//给图开辟空间

void createGraph(Graph* G, char* vexs, int* arcs) {
	int i,j;
    for (i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];
        for (j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);//导入邻接矩阵
            if (G -> arcs[i][j] != 0 && G -> arcs[i][j] != MAX)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;
    int i;
    for (i = 0; i < G ->vexNum; i++) {
        if (G -> arcs[index][i] > 0 && G -> arcs[index][i] != MAX && !visited[i]) {
            DFS(G, visited, i);
        }
    }
}

int main() {
    Graph* G = initGraph(6);
    int* visited = (int*)malloc(sizeof(int) * G -> vexNum);
    int i;
    for (i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    int arcs[6][6] = {
        0, 6, 1, 5, MAX, MAX,
        6, 0, 5, MAX, 3, MAX,
        1, 5, 0, 5, 6, 4,
        5, MAX, 5, 0, MAX, 2,
        MAX, 3, 6, MAX, 0, 6,
        MAX, MAX, 4, 2, 6, 0
    };//邻接矩阵
    createGraph(G, "123456", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    prim(G, 0);
    return 0;
}
