#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5//队列的最大容量

typedef struct Graph {
    char* vexs;//结点
    int** arcs;//边
    int vexNum;//结点数
    int arcNum;//边数
}Graph;

typedef struct Queue {
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    return Q;
}

int isFull(Queue* Q) {
   return (Q->rear + 1) % MAXSIZE == Q->front;
}

int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}

int enQueue(Queue* Q, int data) {
    if (isFull(Q)) {
        return 0;
    }
    else {
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int deQueue(Queue* Q) {
    if(isEmpty(Q)) {
        return -1;
    }
    else {
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
}

/* 导入结点，初始化图 */
Graph* initGraph(int vexNum) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    /* 申请一个一维数组存储结点 */
    G -> vexs = (char*)malloc(sizeof(char) * vexNum);
    /* 申请一个二维邻接数组 */
    G -> arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i = 0 ; i < vexNum; i++) {
        G -> arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G -> vexNum = vexNum;//初始化结点数
    G -> arcNum = 0;//初始化边数为0
    return G;
}

/* 导入邻接矩阵，创建图 */
void createGraph(Graph* G, char* vexs, int* arcs) {
    for (int i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];//标识各结点
        for (int j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);//给图的邻接矩阵赋值
            if (G -> arcs[i][j] != 0)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;//由于是无向图，所以边数除2
}

void DFS(Graph* G, int* visited, int index) {
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;//标记访问过的节点
    for (int i = 0; i < G ->vexNum; i++) {
    	//如果连通，且终点未访问过
        if (G -> arcs[index][i] == 1 && !visited[i]) {
            DFS(G, visited, i);//从终点继续深度遍历
        }
    }
}

void BFS(Graph* G, int* visited, int index) {
    Queue* Q = initQueue();
    printf("%c\t", G -> vexs[index]);
    visited[index] = 1;
    enQueue(Q, index);//从任一节点开始入队
    while (!isEmpty(Q)) {//如果队不为空继续遍历
        int i = deQueue(Q);//出队
        /* 遍历该出队节点的所有能到达的终点 */
        for (int j = 0; j < G -> vexNum; j++) {
        	//如果连通且未被访问过
            if (G -> arcs[i][j] == 1 && !visited[j]) {
                printf("%c\t", G -> vexs[j]);//访问该节点
                visited[j] = 1;//标记访问
                enQueue(Q, j);//将其入队
            }
        }
    }
}

int main() {
    Graph* G = initGraph(5);
    int* visited = (int*)malloc(sizeof(int) * G -> vexNum);//标识结点是否被访问过
    for (int i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    createGraph(G, "ABCDE", (int *)arcs);
    DFS(G, visited, 0);
    printf("\n");
    for (int i = 0; i < G -> vexNum; i++)
        visited[i] = 0;
    BFS(G, visited, 0);
    printf("\n");
    return 0;
}
