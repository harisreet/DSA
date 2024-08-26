#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100];
int indexx=-1;
struct stack
{
    char v;
    struct stack*next;
};
struct stack *top=NULL;
void push(char l)
{
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->v=l;
    if(top==NULL)
    {
        top=ptr;
        ptr->next=NULL;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}
 void pop()
{
    if(top==NULL)
    {
        return;
    }
  struct stack*ptr=top;
  top=top->next;
  if(ptr->v !='(')
  {
   a[++indexx]=ptr->v;
  }
   free(ptr);
}
int incoming(char g)
{
    switch(g)
    {
        case '+':
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 4;
        break;
        default:
        return 0;
    }
}
int instack(char f)
{
    switch(f)
    {
        case '+':
        case '-':
        return 1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        case '^':
        return 3;
        break;
        default:
        return 0;
    }
}
int isOperand(char m)
{
    return (m>=65 && m<=90) || (m>=97 && m<=122);
}
void infix_prefix(char b)
{
    if(isOperand(b))
    {
      a[++indexx]=b;
    }
    else if(b=='(')
    {
        push(b);
    }
    else if(b==')')
    {
        while(top->v=='(')
        {
            pop();
        }
        pop();
    }
    else 
    {
        while(top!=NULL && instack(top->v)>=incoming(b))
        {
        pop();
        }
        push(b);
    }
}
int main()
{
    char q[100], w[100];
    printf("enter infix experssion :");
    scanf("%s",q);
    int n=strlen(q);
    int k=0;
    for(int i=n-1;i>=0;i--)
    {
          if(q[i]=='(')
          {
            w[k++]=')';
          }
          else if(q[i]==')')
          {
            w[k++]='(';
          }
          else
          {
            w[k++]=q[i];
          }
    }
    w[k]='\0';
    printf("reverse infix = %s\n",w);
    for(int i=0;i<n;i++)
    {
    infix_prefix(w[i]);
    }
    while(top)
    {
        pop();
    }
    a[++indexx]='\0';
    printf("reverse postfix expersion =%s\n",a);
    printf("prefix expersion = ");
    for(int i=indexx-1;i>=0;i--)
    {
        printf("%c",a[i]);
    }
}