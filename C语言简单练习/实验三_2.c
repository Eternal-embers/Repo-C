#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ERROR -128

typedef char elemtType;
typedef struct Queue
{
    elemtType *elem;
    unsigned size;
    int front, rear;
} Queue;

Queue *createQueue(unsigned size) // size为真实队列的最多大小，而队列的元素项数最大为size + 1
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->elem = (elemtType *)malloc(sizeof(elemtType) * (size + 1)); // 保留一个位置，MAXSIZE 为 size + 1
    Q->front = Q->rear = 0;
    Q->size = size + 1;
    return Q;
}

_Bool isFull(Queue *Q)
{
    return (Q->rear + 1) % Q->size == Q->front;
}

_Bool isEmpty(Queue *Q)
{
    return Q->front == Q->rear;
}

_Bool enQueue(Queue *Q, elemtType key)
{
    if ((Q->rear + 1) % Q->size == Q->front) // 队满
        return 0;
    Q->elem[Q->rear] = key;
    Q->rear = (Q->rear + 1) % Q->size;
    return 1;
}

elemtType deQueue(Queue *Q)
{
    if (Q->front == Q->rear) // 队空
        return ERROR;
    elemtType e = Q->elem[Q->front];
    Q->front = (Q->front + 1) % Q->size;
    return e;
}

unsigned getLength(Queue *Q)
{
    return (Q->rear - Q->front + Q->size) % Q->size;
}

elemtType getTop(Queue *Q)
{
    return Q->elem[(Q->rear - 1 + Q->size) % Q->size];
}

/*
    过江渡船每次能载10辆车过江，过江车辆分为客车类和货车类，上渡船有如下规定：
    同类车先到先上船；
    客车先于货车上渡船，且每上4辆客车，才允许上一辆货车；
    若等待的客车不足4辆，则以货车代替；
    若无货车等待，允许客车都上船。
*/

/* 用P表示客车，用T表示货车,n表示所有车的数量 */
void ferryManage(unsigned n)
{
    Queue *P = createQueue(100);   // 客车队列，最大成员数为100
    Queue *T = createQueue(100);   // 货车队列，最大成员数为100
    Queue *ship = createQueue(10); // 过江渡船队列，最多载10辆车
    int i;

    srand(time(NULL)); // 用时间戳作为随机种子
    printf("generate car sequences: ");
    /* 随机生成n辆车 */
    for (i = 0; i < n; i++)
    {
        char car = (rand() % 2) ? 'P' : 'T'; // 随机生成一辆车辆，P为客车，T为货车
        printf("%c ", car);
        if (car == 'P')
            enQueue(P, car);
        else
            enQueue(T, car);
    }
    putchar('\n');
    unsigned pNum = 0; // pNum记录渡船队列上的客车数量，tNum记录渡船队列上的货车数量
    int flag = 0;      // 标识P队列和T队列的状态
    flag += !isEmpty(P) + !isEmpty(T) * 2;
    while (flag)
    {
        switch (flag)
        {
        case 0: // 等待队列都为空
            break;
        case 1: // 客车队列非空，货车队列为空
        {
            while (!isFull(ship) && !isEmpty(P)) // 船队列未满，客车队列非空
            {
                enQueue(ship, deQueue(P)); // 客车上船
                printf("P get on board, %d buses left, 0 trucks left\n", getLength(P));
            }
            break;
        }
        case 2: // 客车队列为空，货车队列非空
        {
            while (!isFull(ship) && !isEmpty(T)) // 船队列未满，货车队列非空
            {
                enQueue(ship, deQueue(T)); // 客车上船
                printf("T get on board, 0 buses left, %d trucks left\n", getLength(T));
            }
            break;
        }
        case 3: // 客车队列和货车队列都非空
        {
            if (getLength(P) < 4) // 客车不足4辆，货车代替客车上船
            {
                enQueue(ship, deQueue(T)); // 货车上船
                printf("T get on board, %d buses left, %d trucks left\n", getLength(P), getLength(T));
                pNum++; // 货车代替客车
            }
            else
            {
                enQueue(ship, deQueue(P)); // 客车上船
                printf("P get on board, %d buses left, %d trucks left\n", getLength(P), getLength(T));
                pNum++;
                if (pNum > 0 && pNum % 4 == 0) // 每上四辆客车才允许上一辆货车
                {
                    enQueue(ship, deQueue(T)); // 货车上船
                    printf("T get on board, %d buses left, %d trucks left\n", getLength(P), getLength(T));
                }
            }
            break;
        }
        }
        /* 如果船满则将车运走 */
        if (isFull(ship))
        {
            printf("off the ship: ");
            while (!isEmpty(ship))
                printf("%c ", deQueue(ship)); // 下船
            putchar('\n');
            pNum = 0;
        }
        flag = !isEmpty(P) + !isEmpty(T) * 2; // 更新队列状态的标识
    }

    /* 最后一趟船中的车下船 */
    if (!isEmpty(ship))
    {
        printf("off ship: ");
        do
        {
            printf("%c ", deQueue(ship)); // 下船
        } while (!isEmpty(ship));
        putchar('\n');
    }
}

int main()
{
    unsigned n;
    printf("please input the number of cars: ");
    scanf("%d", &n);
    ferryManage(n);
}