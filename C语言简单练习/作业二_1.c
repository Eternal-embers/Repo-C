#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

typedef char elemtType;
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

_Bool isPalindrome(char s[])
{
    Stack stack;
    stack.top = 0;
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        push(&stack, s[left]);
        left++;
        right--;
    } // push first half of s to the stack
    right++;
    while (!isEmpty(&stack))
    {
        if (pop(&stack) != s[right++])
            return 0;
    }
    return 1;
} // checked

int main()
{
    char s1[20] = "aababcbabaa";
    char s2[20] = "abacddcaba";
    char s3[20] = "abbaabbc";
    printf("%s is palindrome: %s \n", s1, isPalindrome(s1) ? "true" : "false");
    printf("%s is palindrome: %s \n", s2, isPalindrome(s2) ? "true" : "false");
    printf("%s is palindrome: %s \n", s3, isPalindrome(s3) ? "true" : "false");
    return 0;
}