#ifndef _LeftHeap_H

typedef struct TreeNode priorityQueue;
int findMin(priorityQueue *H);
priorityQueue *merge(priorityQueue *H1,priorityQueue *H2);
priorityQueue *merge1(priorityQueue *H1,priorityQueue *H2);
priorityQueue *insert(int data,priorityQueue *H);
priorityQueue *deleteMin(priorityQueue *H);
void traverseHeap(priorityQueue *H);

#endif
