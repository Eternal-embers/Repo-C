#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 0x7fffffff

typedef struct TreeNode
{
    int weight;
    int parent, lchild, rchild;
} Node;

typedef struct HFTree
{
    Node *node; // 节点数组
    int length; // 哈夫曼树的节点数
} HFTree;

/* 初始化哈夫曼树，将初始权值载入哈夫曼树中 */
HFTree *initTree(int w[], int length)
{
    HFTree *T = (HFTree *)malloc(sizeof(HFTree));
    T->node = (Node *)malloc(sizeof(Node) * (2 * length - 1)); // 创建大小(2 * length - 1)的节点数组
    T->length = length;                                        // 哈夫曼树的length初始化为权值数目
    int i;
    for (i = 0; i < length; i++)
    {
        T->node[i].weight = w[i];
        T->node[i].parent = 0;
        T->node[i].lchild = -1;
        T->node[i].rchild = -1;
    }
    return T;
} // checked

/* 从剩余节点中挑选2个最小的节点，返回包含这两个节点索引的数组 */
int *selectMin(HFTree *T)
{
    int min = INF, secondMin = INF; // 初始化最小值为无穷大
    int minIndex, secondIndex;
    int i;
    for (i = 0; i < T->length; i++)
    {
        if (T->node[i].parent == 0) // 节点未被选过
        {
            if (T->node[i].weight < min)
            {
                min = T->node[i].weight;
                minIndex = i;
            }
        }
    }
    for (i = 0; i < T->length; i++)
    {
        if (T->node[i].parent == 0 && i != minIndex)
        {
            if (T->node[i].weight < secondMin)
            {
                secondMin = T->node[i].weight;
                secondIndex = i;
            }
        }
    }
    /* 打包两个最小值到数组中 */
    int *res = (int *)malloc(sizeof(int) * 2);
    res[0] = minIndex;
    res[1] = secondIndex;
    return res;
} // checked

/* 创建哈夫曼树，参数w[]为一个存储权值的数组 */
struct HFTree *createHuffmanTree(int w[], int length)
{
    int size = (2 * length) - 1;
    HFTree *T = initTree(w, length); // 初始化哈夫曼树
    int i;
    for (i = T->length; i < size; i++)
    {
        int *res = selectMin(T);
        int min = res[0], secondMin = res[1];
        T->node[i].weight = T->node[min].weight + T->node[secondMin].weight;
        T->node[i].lchild = min;
        T->node[i].rchild = secondMin;
        T->node[i].parent = 0; // 标识新生成的节点的parent为0
        T->node[min].parent = i;
        T->node[secondMin].parent = i;
        T->length++; // 权值列表的数目更新
    }
    return T;
}

/* 先序遍历 */
void preOrder(HFTree *T, int index)
{
    if (index != -1)
    {
        printf("%d ", T->node[index].weight);
        preOrder(T, T->node[index].lchild);
        preOrder(T, T->node[index].rchild);
    }
}

/* 中序遍历 */
void inOrder(HFTree *T, int index)
{
    if (index != -1)
    {
        preOrder(T, T->node[index].lchild);
        printf("%d ", T->node[index].weight);
        preOrder(T, T->node[index].rchild);
    }
}

/* 后序遍历 */
void postOrder(HFTree *T, int index)
{
    if (index != -1)
    {
        preOrder(T, T->node[index].lchild);
        preOrder(T, T->node[index].rchild);
        printf("%d ", T->node[index].weight);
    }
}

/* 表格形式打印哈夫曼树 */
void traverseTree(HFTree *T)
{
    int i;
    printf("%8s%8s%8s%8s%8s\n", "index", "weight", "parent", "lchild", "rchild");
    for (i = 0; i < T->length; i++)
        printf("%8d%8d%8d%8d%8d\n", i, T->node[i].weight, T->node[i].parent, T->node[i].lchild, T->node[i].rchild);
}

/* 获取深度 */
int getDepth(HFTree *T, int index)
{
    if (index == -1)
        return 0;
    else
    {
        int m = getDepth(T, T->node[index].lchild);
        int n = getDepth(T, T->node[index].rchild);
        return m > n ? m + 1 : n + 1;
    }
}

// tree为满二叉树的数组，treeIndex为当前节点在满二叉树数组中的索引，index为哈夫曼树中当前节点的索引
void createFullTree(HFTree *T, int *tree, int treeIndex, int index)
{
    if (index != -1)
    {
        tree[treeIndex] = T->node[index].weight;
        createFullTree(T, tree, 2 * treeIndex + 1, T->node[index].lchild); // 左子树
        createFullTree(T, tree, 2 * treeIndex + 2, T->node[index].rchild); // 右子树
    }
}

/* 打印空格 */
void printSpace(int space)
{
    int i;
    for (i = 0; i < space; i++)
        printf(" ");
}

/* 以树形打印哈夫曼树 */
void printTree(HFTree *T)
{
    int depth = getDepth(T, T->length - 1); // 获取树的深度
    int size = pow(2, depth) - 1;           // 深度为depth的满二叉树的节点数
    int tree[size];                         // 存储哈夫曼树中节点在满二叉树中的索引
    int i;
    for (i = 0; i < size; i++) // 初始化满二叉树中所有节点为空，标识为-1
        tree[i] = -1;
    tree[0] = T->length - 1;                   // 将根节点放置在满二叉树中
    createFullTree(T, tree, 0, T->length - 1); // 根据哈夫曼树创建满二叉树数组
    /* 打印树形二叉树 */
    int index = 0;                     // 满二叉树数组中根节点的索引
    int space = pow(2, depth - 1) * 2; // 空格数目
    int start = 0;                     // 每层第一个左孩子的索引
    for (i = 0; i < depth; i++, space /= 2, start = 2 * start + 1)
    {
        int bias = (pow(2, depth) - pow(2, i + 1)) / pow(2, i); // 空格偏置
        int end = start + pow(2, i);
        printSpace(space / 2);
        for (index = start; index < end; index++) // 打印第i + 1层
        {
            printSpace(bias);
            if (tree[index] != -1)
                printf("%2d", tree[index]);
            else
                printf("  ");
            printSpace(space);
        }
        printf("\n\n");
    }
}

int main()
{
    // int w[10] = {4, 2, 9, 11, 7, 5, 6, 4, 0, 10}; // 测试用例一
    int w[7] = {5, 9, 2, 7, 6, 4, 10}; // 测试用例二
    HFTree *T = createHuffmanTree(w, 7);
    printf("preOrder: ");
    preOrder(T, T->length - 1); // 先序遍历
    printf("\ninOrder: ");
    inOrder(T, T->length - 1); // 中序遍历
    printf("\npostOrder: ");
    postOrder(T, T->length - 1); // 后序遍历
    printf("\nshow the table of Huffman Tree: \n");
    traverseTree(T); // 以表格形式打印哈夫曼树
    printf("print Huffman tree in the shape of tree:  \n");
    printTree(T); // 以树形打印哈夫曼树
}