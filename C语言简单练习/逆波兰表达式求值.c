/* 未完成，待修正 */
#include <stdio.h>
#define stack struct Node

typedef struct Node
{
    char type; //'v'为value,'o为operator
    union
    {
        int value;
        char operator;
    };
    struct Node *next;
} node;

stack *createStack()
{
    node *head = (node *)malloc(sizeof(struct Node));
    head->type = 'v'; // 头节点的数据记录节点数
    head->value - 0;
    head->next = NULL;
    return head;
}

_Bool isEmpty(stack *s)
{
    if (s->next == NULL)
        return 1;
    else
        return 0;
}

void push(char type, int data, stack *s)
{
    node *p = (node *)malloc(sizeof(struct Node));
    p->type = type;
    if (type == 'v')
        p->value = data;
    else
        p->operator=(char) data;
    p->next = s->next;
    s->next = p;
    s->value++;
}

char getTopType(stack *s)
{
    return s->next->type;
}

int top(stack *s)
{
    if (s->next->type == 'v')
        return s->next->value;
    else
        return s->next->operator;
}

int pop(stack *s)
{
    if (isEmpty(s))
        return NULL;
    int data;
    if (getTopType(s) == 'v')
        data = s->next->value;
    else
        data = s->next->operator;
    node *p = s->next;
    s->next = s->next->next;
    free(p);
    s->value--;
    return data;
}

void clear(stack *s)
{
    while (!isEmpty(s))
    {
        node *p = s->next;
        s->next = s->next->next;
        free(p);
    }
    s->value = 0;
}

int getLevel(char operator)
{
    if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '+' || operator== '-')
        return 1;
}

/* 逆波兰表达式求值 */
stack *getantiPolish(char *expression)
{
    /* 转换为逆波兰表达式 */
    printf("The antiPolish expression: ");
    char operator[50], top = 0; // 临时符号栈
    stack *s = createStack();   // 逆波兰表达式栈
    int i = 0;                  // 用于遍历expression
    char ch = expression[i];
    while (expression[i] != '\0')
    {
        ch = expression[i];
        if (ch == ' ') // 跳过空格
            i++;
        else if (ch >= '0' && ch <= '9')
        {
            unsigned value = 0;  // 只允许处理正数
            int nums[20], j = 0; // 数组模拟栈

            /* 获取数的所有位上的数字 */
            do
            {
                nums[j] = expression[i] - '0';
                i++, j++;
                ch = expression[i];
            } while (ch >= '0' && ch <= '9');

            /* 计算数的值 */
            unsigned digit = 1;
            for (j = j - 1; j >= 0; j--)
            {
                value += nums[j] * digit;
                digit *= 10;
            }
            printf("%d ", value); // 输出数值
            push('v', value, s);
        }
        else
        {
            if (top == 0) // 符号栈为空直接入栈
                operator[top++] = ch;
            else
            {
                int level1 = getLevel(ch); // 获取运算符优先级
                int level2 = getLevel(operator[top - 1]);
                if (level1 >= level2) // 当前扫描到的运算符大于栈顶元素的运算符
                    operator[top++] = ch;
                else // 符号出栈进入逆波兰表达式中
                {
                    do
                    {
                        push('o', operator[--top], s);
                        printf("%c ", operator[top]);
                        level2 = getLevel(operator[top - 1]);
                    } while (top > 0 && level1 <= level2);
                    operator[top++] = ch;
                }
            }
            i++;
        }
    }
    /* 处理符号栈中剩余的运算符 */
    while (top > 0)
    {
        push('o', operator[--top], s);
        printf("%c ", operator[top]);
    }
    putchar('\n');

    return s; // 返回逆波兰表达式
}

int antiPolishEvaluate(stack *s)
{
    stack *
        printf("Calculation process:\n");
    int data;
    while (!isEmpty(s))
    {
        if ()
            // 从values栈获取两个值进行运算
            unsigned value1 = values[--top];
        unsigned value2 = values[--top];

        // 输出运算符
        // 四则运算
        switch (queue[k])
        {
        case '+':
            res = (value2 + value1);
            printf("%d + %d = %d\n", value2, value1, res);
            break;
        case '-':
            res = (value2 - value1);
            printf("%d - %d = %d\n", value2, value1, res);
            break;
        case '*':
            res = (value2 * value1);
            printf("%d * %d = %d\n", value2, value1, res);
            break;
        case '/':
            res = (value2 / value1);
            printf("%d / %d = %d\n", value2, value1, res);
            break;
        }
        values[top++] = res; // 将计算结果push到数值栈
    }
}

int main()
{
    char *expression = "12 + 6 * 12 - 120 / 3";
    int res = antiPolishoEvealuate(expression);
    printf("result: %s = %d", expression, res);
    return 0;
}
