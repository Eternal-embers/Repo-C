#include <stdio.h>
#define MAXSIZE 1000
#define ERROR -0x7fffffff - 1

typedef int elemtType;
typedef struct Queue
{
    elemtType elemt[MAXSIZE];
    int front, rear;
} Queue;

_Bool enQueue(Queue *Q, int key)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) // 队满
        return 0;
    Q->elemt[Q->rear] = key;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

elemtType deQueue(Queue *Q)
{
    if (Q->front == Q->rear) // 队空
        return ERROR;
    elemtType e = Q->elemt[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    printf("%d ", e);
    return e;
}

int main()
{
    Queue Q;
    Q.front = 0, Q.rear = 0;
    int m, n, i;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    int cnt = 0;
    for (i = 1; i <= n; i++)
    {
        enQueue(&Q, i);
    }
    printf("sequence: ");
    for (cnt = 1; cnt < n; cnt++) // 报数n-1轮
    {
        // 报数
        for (i = 1; i < m; i++) // 报数1~(m-1)
        {
            int elemt = deQueue(&Q);
            enQueue(&Q, elemt);
        }
        deQueue(&Q); // 报数m的出队
    }
    printf("\nMonkey King: %d", deQueue(&Q));
    return 0;
}