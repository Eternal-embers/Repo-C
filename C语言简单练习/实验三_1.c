#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

typedef unsigned elemtType;
typedef struct node
{
    elemtType elem[MAXSIZE];
    int top;
} Stack;

_Bool isEmpty(Stack *stack)
{
    return stack->top == 0;
}

void push(Stack *stack, elemtType key)
{
    stack->elem[stack->top++] = key;
}

elemtType pop(Stack *stack)
{
    return stack->elem[--stack->top];
}

elemtType getTop(Stack *stack)
{
    return stack->elem[stack->top - 1];
}

void decimalToHex(unsigned x)
{
    Stack stack;   // 栈
    stack.top = 0; // 初始化
    while (x)
    {
        push(&stack, x % 16);
        x /= 16;
    }
    while (!isEmpty(&stack))
    {
        if (getTop(&stack) >= 10)
            printf("%c", 'A' + pop(&stack) - 10);
        else
            printf("%d", pop(&stack));
    }
    putchar('\n');
}

int main()
{
    int x;
    printf("please input a number: ");
    scanf("%d", &x);
    printf("%d -> ", x);
    if (x > 0)
        decimalToHex(x);
    else
    {
        printf("-");
        decimalToHex(-x);
    }
}