#include <stdio.h>
#include <stdlib.h>

#define MAX 32767

typedef struct Graph {
    char* vexs;
    int** arcs;
    int vexNum;
    int arcNum;
}Graph;

Graph* initGraph(int vexNum) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G -> vexs = (char*)malloc(sizeof(char) * vexNum);
    G -> arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i = 0 ; i < vexNum; i++) {
        G -> arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G -> vexNum = vexNum;
    G -> arcNum = 0;
    return G;
}

void createGraph(Graph* G, char* vexs, int* arcs) {
    for (int i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];
        for (int j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);
            if (G -> arcs[i][j] != 0 && G -> arcs[i][j] != MAX)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;
    for (int i = 0; i < G ->vexNum; i++) {
        if (G -> arcs[index][i] > 0 && G -> arcs[index][i] != MAX && !visited[i]) {
            DFS(G, visited, i);
        }
    }
}

void floyd(Graph* G) {
    int d[G -> vexNum][G -> vexNum];//d数组记录vi到vj的最短距离，d数组初始化为G的邻接矩阵
    int p[G -> vexNum][G -> vexNum];//p数组记录vi->vj的最短路径前驱
    /* 初始化d数组和p数组 */
    for (int i = 0; i < G -> vexNum; i++) {
        for (int j = 0; j < G -> vexNum; j++) {
            d[i][j] = G -> arcs[i][j];
            if (G -> arcs[i][j] > 0 && G -> arcs[i][j] != MAX) {
                p[i][j] = i;
            }
            else
                p[i][j] = -1;
        }
    }
    
    /* floyd算法 */
    for (int i = 0; i < G -> vexNum; i++) {//遍历中间节点
        for (int j = 0; j < G -> vexNum; j++) {//遍历起点
            for (int k = 0; k < G -> vexNum; k++) {//遍历终点
                if (d[j][i] + d[i][k] < d[j][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }

    for (int i = 0; i < G -> vexNum; i++) {
        for (int j = 0; j < G -> vexNum; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < G -> vexNum; i++) {
        for (int j = 0; j < G -> vexNum; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* G = initGraph(4);
    int* visited = (int*)malloc(sizeof(int) * G -> vexNum);
    for (int i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    int arcs[4][4] = {
        0, 1, MAX, 3,
        1, 0, 2, 2,
        MAX, 2, 0, 8,
        3, 2, 8, 0
    };
    createGraph(G, "1234", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    floyd(G);
    return 0;
}
