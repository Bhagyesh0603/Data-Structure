// Write a program to evaluate a given postfix expression using stacks
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int stack[100];
int top = -1;
int solve(char postfix[])
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char current = postfix[i];
        if (isdigit(current))
        {
            stack[++top] = (current - '0');
        }
        else
        {
            int a = stack[top--];
            int b = stack[top--];
            int result;
            switch (current)
            {
            case '+':
                result = (b + a);
                break;
            case '-':
                result = (b - a);
                break;
            case '*':
                result = (b * a);
                break;
            case '/':
                result = (b / a);
                break;
            }
            stack[++top] = result;
        }
    }
    int ans = stack[top];
    return stack[top];
}
int main()
{
    char postfix[25];
    printf("Enter postfix Expression :- ");
    scanf("%s", &postfix);
    printf("%d", solve(postfix));
}
