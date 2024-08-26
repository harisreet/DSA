#include<stdio.h>
#include<stdlib.h>
struct stack1
{
    int value;
    struct stack1*next;
};
struct stack2
{
    int value;
    struct stack2*next;
};
struct stack1*top1=NULL;
struct stack2*top2=NULL;
void push1(int h)
{
  struct stack1*ptr=(struct stack1*)malloc(sizeof(struct stack1));
  ptr->value=h;
  if(top1==NULL)
  {
    top1=ptr;
    top1->next=NULL;
  }
  else
  {
    ptr->next=top1;
    top1=ptr;
  }
}
void push2(int g)
{
    struct stack2*ptr=(struct stack2*)malloc(sizeof(struct stack2));
  ptr->value=g;
  if(top2==NULL)
  {
    top2=ptr;
    top2->next=NULL;
  }
  else
  {
    ptr->next=top2;
    top2=ptr;
  }
}
void pop1()
{
    if(top1==NULL)
    {
        return;
    }
    struct stack1*ptr=top1;
    while(top1!=NULL)
    {
    top1=top1->next;
    push2(ptr->value);
    }
}
void pop2()
{
    if(top2==NULL)
    {
        return;
    }
    struct stack2*ptr=top2;
    top2=top2->next;
    while(top2!=NULL)
    {
    top2=top2->next;
    push1(ptr->value);
    }
}
void enqueue(int f)
{
    push1(f);
}
void dequeue()
{
    pop1();
    pop2();
}
void peek()
{
   if(top1==NULL)
    {
        return;
    }
    struct stack1*temp=top1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     printf("peek element = %d\n",temp->value);
}
void size_queue()
{
    if(top1==NULL)
    {
        return;
    }
    int c=0;
    struct stack1*temp=top1;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
     printf("size = %d\n",c);
}

void display(struct stack1*top1)
{
    if(top1==NULL)
    {
        return;
    }
    //recursive function
    display(top1->next);
    //each recursive return print the data of the current node
    printf("%d ",top1->value);
   
}
int main()
{
   int choice,data,x;
    printf("1.enqueue  2.dequeue  3.peek  4.size  5.display\n");
    do
    {
    printf("enter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
       
       case 1:
       printf("enter value : ");
       scanf("%d",&data);
       enqueue(data);
       break;

       case 2:
       dequeue();
       break;

       case 3:
       peek();
       break;

       case 4:
       size_queue();
       break;

       case 5:
       printf("elements are ");
       display(top1);
        printf("\n");
       break;

    };
    printf("press 0 ");
    scanf("%d",&x);
    }while(x==0);
}