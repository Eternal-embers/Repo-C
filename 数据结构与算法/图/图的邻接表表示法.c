#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define ERROR -0x7fffffff - 1

typedef struct Arc
{
    int tail;         // 边的尾部顶点的索引
    struct Arc *next; // 下一条与该顶点相连的边
} Arc;

typedef struct Vex
{
    char data; // 节点编号
    Arc *arc;  // 与该节点相连的边
} Vex;

typedef struct Graph
{
    Vex *vex;   // 节点数组
    int vexNum; // 节点数
    int arcNum; // 边数

} Graph;

/* ================= 栈的数据结构实现 ======================= */
typedef struct Queue
{
    int front;
    int rear;
    int data[MAXSIZE];
} Queue;

Queue *initQueue()
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    return Q;
}

int isFull(Queue *Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int isEmpty(Queue *Q)
{
    return Q->front == Q->rear;
}

int enQueue(Queue *Q, int data)
{
    if (isFull(Q))
    {
        return 0;
    }
    else
    {
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int deQueue(Queue *Q)
{
    if (isEmpty(Q))
    {
        return ERROR;
    }
    else
    {
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
}
/* ================= 栈的数据结构实现 ======================= */

/* vexs指向它的节点数组，arcs指向图的邻接矩阵 */
Graph *createGraph(char *vexs, int *arcs, int vexNum)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));    // 申请图的结构体空间
    G->vex = (Vex *)malloc(sizeof(Vex) * vexNum); // 申请节点表的空间
    G->vexNum = vexNum;                           // 初始化节点数量
    G->arcNum = 0;                                // 初始化边数为0
    int i, j;
    for (i = 0; i < vexNum; i++) // 遍历节点表
    {
        G->vex[i].data = vexs[i];                   // 节点编号
        G->vex[i].arc = (Arc *)malloc(sizeof(Arc)); // 申请边表的表头的空间，不存放数据
        G->vex[i].arc->tail = i;                    // 初始化表头的边指向节点本身
        G->vex[i].arc->next = NULL;                 // 初始化表头的边的next为空
        for (j = 0; j < vexNum; j++)                // 遍历所有与节点相连的边
        {
            if (*(arcs + i * vexNum + j))
            {
                Arc *new = (Arc *)malloc(sizeof(Arc)); // 创建一条边
                new->tail = j;                         // 边的尾部为编号为j的节点
                /* 头插法 */
                new->next = G->vex[i].arc->next;
                G->vex[i].arc->next = new;
                G->arcNum++; // 边数加一
            }
        }
    }
    return G;
}

void DFS(Graph *G, int *visited, int index)
{
    printf("%c ", G->vex[index].data);
    visited[index] = 1;
    Arc *p = G->vex[index].arc->next;
    while (p) // 如果相连的节点
    {
        if (!visited[p->tail]) // 如果节点未访问过
            DFS(G, visited, p->tail);
        p = p->next; // 遍历下一个节点
    }
}

void BFS(Graph *G, int index)
{
    Queue *Q = initQueue();
    int visited[G->vexNum], i;
    for (i = 0; i < G->vexNum; i++)
        visited[i] = 0;
    enQueue(Q, index); // 将从编号为index的节点开始
    visited[index] = 1;
    while (!isEmpty(Q))
    {
        index = deQueue(Q); // 获取节点的索引
        printf("%c ", G->vex[index].data);
        Arc *p = G->vex[index].arc->next; // 从节点第一条相连的边开始
        while (p)
        {
            if (!visited[p->tail])
            {
                enQueue(Q, p->tail); // 将边相连的顶点的索引入队
                visited[p->tail] = 1;
            }
            p = p->next;
        }
    }
}

int main()
{
    int arcs[6][6] = {
        0, 1, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1,
        0, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0};
    Graph *G = createGraph("ABCDEF", (int *)arcs, 6);
    int visited[6] = {0}; // 辅助数组
    printf("DFS: ");
    DFS(G, visited, 0);
    putchar('\n');
    printf("BFS: ");
    BFS(G, 0);
    return 0;
}