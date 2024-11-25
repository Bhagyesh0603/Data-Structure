#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item)
{
    if(top==SIZE-1)
    {
        printf("Stack overflow\n");
        exit(0);

    }
    else
    {
        top=top+1;
        stack[top]=item;

    }
}
char pop()
{
    char item;
    if (top==-1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    else
    {
        item=stack[top];
        top=top-1;
        return(item);
    }
}
int prec(char ch)
{
    if(ch=='/')
        return(10);
    if(ch=='*')
        return(9);
    if(ch=='+'||ch=='-')
        return(5);
    if(ch=='(')
        return(1);
    else
        return(0);

}
void convert(char infix[SIZE])
{
  int l;
  char ch;
  char item;
  char postfix[SIZE];
  int temp;
  int index=0;
  int position=0;
  l=strlen(infix);
  while(index<l)
  {
    ch=infix[index];
  switch(ch)
  {
      case'(': push(ch );break;
      case')': item=pop();
            while(item!='(')
            {
                postfix[position]=item;
                position++;
                item=pop();
            }break;
      case '+':
      case '-':
      case '*':
      case '/':if(prec(ch)<prec(stack[top]))
                {
                  temp=pop();
                  stack[top]=ch;
                  postfix[position++]=temp;
                }
             else
                {
                 push(ch);
                }break;
      default: postfix[position++]=ch;break;

  }
  index++;
  }
  postfix[position++]='\0';
  printf("The postfix expression is:\n");
  puts(postfix);

}
int main()
{
    char infix[SIZE];
    printf("Enter the infix expression:\n");
    gets(infix);
    convert(infix);
    return (0);
}
