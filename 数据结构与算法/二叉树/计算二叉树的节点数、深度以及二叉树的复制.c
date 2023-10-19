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

/* 获取二叉树的深度，某节点的深度depth(root) = max(depth(left),depth(right)) + 1 */
int getDepth(TreeNode *T)
{
    if (T == NULL)
        return 0;
    else
    {
        int leftDepth = getDepth(T->lchild);
        int rightDepth = getDepth(T->rchild);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}

/* 获取二叉树的节点数，count(root) = count(left) + count(right) + 1 */
int nodeCount(TreeNode *T)
{
    if (T == NULL)
        return 0;
    else
        return nodeCount(T->lchild) + nodeCount(T->rchild) + 1;
}

/* 获取二叉树的叶子节点数，leaf(root) = leaf(left) + leaf(right) */
int leafCount(TreeNode *T)
{
    if (T == NULL)
        return 0;
    else if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return leafCount(T->lchild) + leafCount(T->rchild);
}

/* 二叉树的复制 */
void copy(TreeNode **T, TreeNode **dest)
{
    if (*T == NULL)
    {
        *(dest) = NULL;
        return;
    }
    else
    {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node->data = (*T)->data;
        (*dest) = node;                        // 复制根节点
        copy(&(*T)->lchild, &(*dest)->lchild); // 递归复制左子树
        copy(&(*T)->rchild, &(*dest)->rchild); // 递归复制右子树
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
    测试用例：
    序列为ABC##D##EF##G##
             A
           /   \
          B      E
         / \    / \
        C   D  F   G
    */
    int index = 0;
    TreeNode *T = createTree("ABCD##E##FG##H##IJ##K##", &index);
    // TreeNode *T = createTree_manual();
    printf("preOrder: ");
    preOrder(T); // 输出ABCDEFGHIJK
    putchar('\n');
    printf("inOrder: ");
    inOrder(T); // 输出DCEBGFHAJIK
    putchar('\n');
    printf("postOrder: ");
    postOrder(T); // 输出DECGHFBJKIA
    putchar('\n');
    printf("depth of tree: %d\n", getDepth(T));
    printf("nodes count of tree: %d\n", nodeCount(T));
    printf("leaf count of tree: %d\n", leafCount(T));
    TreeNode *copyTree;
    copy(&T, &copyTree);
    printf("preOrder of copyTree: ");
    preOrder(copyTree);
}
