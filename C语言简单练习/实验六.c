#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define ERROR -0x7fffffff - 1

typedef struct Graph
{
    char *vex;  // 节点数组
    int **arc;  // 邻接矩阵
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

Graph *initGraph(int vexNum)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexNum = vexNum;
    G->vex = (char *)malloc(sizeof(char) * vexNum);
    G->arc = (int **)malloc(sizeof(int *) * vexNum); // 开辟一个指针数组
    int i;
    for (i = 0; i < vexNum; i++)
        G->arc[i] = (int *)malloc(sizeof(int) * vexNum); // 指针数组中的每个指针指向一个一维数组
    return G;
}

Graph *createGraph(char *vexs, int *arcs, int vexNum)
{
    Graph *G = initGraph(vexNum); // 初始化对象
    int i, j;
    /* 节点数组 */
    for (i = 0; i < vexNum; i++)
        G->vex[i] = vexs[i];
    /* 边数组 */
    for (i = 0; i < vexNum; i++)
    {
        for (j = 0; j < vexNum; j++)
        {
            G->arc[i][j] = *(arcs + vexNum * i + j);
            if (G->arc[i][j])
                G->arcNum++;
        }
    }
    return G;
}

/* visited为辅助数组用于判断节点是否访问，index表示节点下标 */
void DFS(Graph *G, int *visited, int index)
{
    printf("%c ", G->vex[index]);
    visited[index] = 1;
    int i;
    for (i = 0; i < G->vexNum; i++)
    {
        if (!visited[i] && G->arc[index][i]) // 如果未访问过且<index,i>之间存在边
            DFS(G, visited, i);
    }
}

void BFS(Graph *G, int index)
{
    int visited[G->vexNum], i;
    for (i = 0; i < G->vexNum; i++)
        visited[i] = 0;
    Queue *Q = initQueue();
    enQueue(Q, index);  // 将第一个遍历的节点的索引入队
    visited[index] = 1; // 标记访问过该节点
    while (!isEmpty(Q))
    {
        index = deQueue(Q); // 获取节点的索引
        printf("%c ", G->vex[index]);
        for (i = 0; i < G->vexNum; i++)
        {
            if (!visited[i] && G->arc[index][i])
            {
                enQueue(Q, i);
                visited[i] = 1; // 标记访问过该节点
            }
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