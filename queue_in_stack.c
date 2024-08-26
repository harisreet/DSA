#include<stdio.h>
#include<stdlib.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
void push1(int v)
{
    if(top1==N-1)
    return;
    else
    s1[++top1]=v;
}
void pop1()
{
    if(top1==-1)
    return;
    while(top1!=-1)
    {
    push2(s1[top1]);
    top1--;
    }
}
void push2(int h)
{

    if(top2==N-1)
    return;
    else
    s2[++top2]=h;
}
void pop2()
{
    if(top2==-1)
    return;
    top2--;
    while(top2!=-1)
    {
        push1(s2[top2]);
        top2--;
    }
}
void dequeue()
{
    if(top1==-1)
    printf("queue empty\n");
    pop1();
    pop2();
}
void enqueue(int d)
{
    if(top1==N-1)
    printf("queue full\n");
    push1(d);
}
void peek()
{ 
    if(top1==-1)
    {
    printf("queue empty\n");
    return;
    }
    printf("peek element = %d\n",s1[0]);
}
void size_queue()
{
    if(top1==-1)
    {
    printf("queue empty\n");
    return;
    }
    printf("size = %d\n",top1+1);
}
void display()
{
    printf("elements are ");
    for(int i=0;i<=top1;i++)
    {
       printf("%d  ",s1[i]);
    }
    printf("\n");
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
       display();
       break;

    };
    printf("press 0 ");
    scanf("%d",&x);
    }while(x==0);
}