#ifndef leftHeap_H

typedef struct TreeNode Heap;
typedef struct TreeNode priorityQueue;
void traverseQueue(priorityQueue *Q,priorityQueue *father,int flag);
priorityQueue *initHeap(int data);
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2);
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2);
priorityQueue *insert(int data,priorityQueue *H);
priorityQueue *deleteMin(priorityQueue *H);

#endif
