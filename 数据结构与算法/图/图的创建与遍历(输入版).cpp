#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

// �ڽӱ�洢�ṹ
typedef struct EdgeNode {
    int adjvex; // �ڽӵ��򣬴洢�ö����Ӧ���±�
    int weight; // Ȩֵ
    struct EdgeNode *next; // ����ָ����һ���ڽӵ�
} EdgeNode;

typedef struct VertexNode {
    char data; // �����򣬴洢������Ϣ
    EdgeNode *firstedge; // �߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges; // ͼ�е�ǰ�������ͱ���
} GraphAdjList;

// ����ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("�����붥�����ͱ�����\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {
        printf("�����붥��%d��", i + 1);
        scanf(" %c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for (k = 0; k < G->numEdges; k++) {
        printf("�������(vi,vj)�ϵĶ�����ţ�\n");
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

// ������־����
int visited[MAXVEX];

// �ڽӱ��������ȵݹ��㷨
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

// �ڽӱ����ȱ�������
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

// �ڽӱ�Ĺ�ȱ����㷨
void BFSTraverse(GraphAdjList G) {
    int i, j;
    EdgeNode *p;
    int queue[MAXVEX], front = 0, rear = 0;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = 0;
    }
    printf("������ȱ�����");
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
    printf("������ȱ�����");
    DFSTraverse(G);
    printf("\n");
    BFSTraverse(G);
    printf("\n");
    return 0;
}

