#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node*next;
};
struct node *top=NULL;
char *neww;
int in=-1;
void push(char l)
{
   struct node*temp=(struct node*)malloc(sizeof(struct node));
   temp->data=l;
   temp->next=top;
   top=temp;
}
void pop()
{
   if (top == NULL) {
   printf("Stack underflow\n");
   exit(1);
   }
   struct node*temp=top;
   if(temp->data!='(')
   {
   neww[++in]=temp->data;
   }
   top=top->next;
   free(temp);      
}
int isoperand(char v)
{
   return(v>=97 && v<=122) || (v>=65 && v<=90);
}
int incoming(char u)
{
  switch(u)
  {
     case '+':
     return 1;
     case '-':
     return 1;
     case '*':
     case '/':
     return 2;
     case '^':
     return 4;
     default:
     return 0;
  }
 
}
int instack(char t)
{
 switch(t)
  {
     case '+':
     case '-':
     return 1;
     case '*':
     case '/':
     return 2;
     case '^':
     return 3;
     default:
     return 0;
  }
 
}
void infixtopostfix(char*e)
{
  int i=0;
 
  while(e[i]!='\0')
  {
      printf("\npresent character = %c\n",e[i]);
      if(isoperand(e[i]))
      {
        neww[++in]=e[i];
        printf("operand %c is added to print \n",e[i]);
       
      }
      else if(e[i]=='(')
      {
         push(e[i]);
         printf("( is pushed into the stack\n");
      }
      else if(e[i]==')')
      {
        while(top!= NULL && top->data!='(')
        {
        pop();
        }
        pop();
      }
      else
      {
         while(top!=NULL && instack(top->data)>=incoming(e[i]))
         {
          pop();
         }
            push(e[i]);
      }
      i++;
    }
    while(top)
    {
     pop();
    }
    neww[++in]='\0';
  }
int main()
{
    char a[50];
    printf("enter infix expression : ");
    scanf("%s",a);
    neww = (char *)malloc(strlen(a) + 1);
    infixtopostfix(a);
    printf("postfix : ");
    printf("%s\n",neww);
    free(neww);
    return 0;
}
