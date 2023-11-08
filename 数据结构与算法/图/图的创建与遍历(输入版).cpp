#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

// 邻接表存储结构
typedef struct EdgeNode {
    int adjvex; // 邻接点域，存储该顶点对应的下标
    int weight; // 权值
    struct EdgeNode *next; // 链域，指向下一个邻接点
} EdgeNode;

typedef struct VertexNode {
    char data; // 顶点域，存储顶点信息
    EdgeNode *firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges; // 图中当前顶点数和边数
} GraphAdjList;

// 建立图的邻接表结构
void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {
        printf("请输入顶点%d：", i + 1);
        scanf(" %c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for (k = 0; k < G->numEdges; k++) {
        printf("请输入边(vi,vj)上的顶点序号：\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j - 1;
        e->next = G->adjList[i - 1].firstedge;
        G->adjList[i - 1].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i - 1;
        e->next = G->adjList[j - 1].firstedge;
        G->adjList[j - 1].firstedge = e;
    }
}

// 遍历标志数组
int visited[MAXVEX];

// 邻接表的深度优先递归算法
void DFS(GraphAdjList G, int i) {
    EdgeNode *p;
    visited[i] = 1;
    printf("%c ", G.adjList[i].data);
    p = G.adjList[i].firstedge;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }
}

// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList G) {
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

// 邻接表的广度遍历算法
void BFSTraverse(GraphAdjList G) {
    int i, j;
    EdgeNode *p;
    int queue[MAXVEX], front = 0, rear = 0;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = 0;
    }
    printf("广度优先遍历：");
    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            printf("%c ", G.adjList[i].data);
            queue[rear++] = i;
            while (front != rear) {
                j = queue[front++];
                p = G.adjList[j].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = 1;
                        printf("%c ", G.adjList[p->adjvex].data);
                        queue[rear++] = p->adjvex;
                    }
                    p = p->next;
                }
            }
        }
    }
}

int main() {
    GraphAdjList G;
    CreateALGraph(&G);
    printf("深度优先遍历：");
    DFSTraverse(G);
    printf("\n");
    BFSTraverse(G);
    printf("\n");
    return 0;
}

