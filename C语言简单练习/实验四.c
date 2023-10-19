#include <stdio.h>
#include <stdlib.h>
#define elementType char

typedef struct TreeNode
{
    elementType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

/* 手动创建二叉树 */
TreeNode *createTree_manual()
{
    int value; // 根节点的值
    printf("root node: ");
    scanf("%c", &value);
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
    if (value == '#')
        return NULL;
    else
    {
        TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
        T->data = value;
        printf("the left node of root [%c] - ", T->data);
        T->lchild = createTree_manual();
        printf("the right node of root [%c] - ", T->data);
        T->rchild = createTree_manual();
        return T;
    }
}

TreeNode *createTree(char *data, int *index)
{
    char ch = data[*index];
    (*index)++;
    if (ch == '#')
        return NULL;
    else
    {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)); // 创建节点
        node->data = ch;
        node->lchild = createTree(data, index); // 创建左子树
        node->rchild = createTree(data, index); // 创建右子树
        return node;                            // 返回根节点
    }
}

/* 先序遍历，根左右 */
void preOrder(TreeNode *T)
{
    if (T)
    {
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

/* 中序遍历,根左右 */
void inOrder(TreeNode *T)
{
    if (T)
    {
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

/* 后序遍历，左右根 */
void postOrder(TreeNode *T)
{
    if (T)
    {
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

int main()
{
    /*
    创建如下二叉树：
                A
              /   \
             B     I
           /   \  / \
          C    F J   K
        /  \  / \
        D   E G  H

    */
    /*
             A
           /   \
          B      E
         / \    / \
        C   D  F   G
    */
    int index = 0;
    // TreeNode *T = createTree("ABCD##E##FG##H##IJ##K##", &index);
    TreeNode *T = createTree_manual();
    printf("preOrder: ");
    preOrder(T); // 输出ABCDEFGHIJK
    putchar('\n');
    printf("inOrder: ");
    inOrder(T); // 输出DCEBGFHAJIK
    putchar('\n');
    printf("postOrder: ");
    postOrder(T); // 输出DECGHFBJKIA
    putchar('\n');
}