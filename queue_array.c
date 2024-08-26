#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int arr[5];
int n=5;
//initialze front=rear=-1
int front=-1,rear=-1;

bool isFull()
{
    if(rear==n-1)
    return true;
    else 
    return false;
}
bool isEmpty()
{
    if(front==-1 && rear==-1)
    return true;
    else
    return false;
}
void enqueue(int value)
{
     if(isFull())
     printf("queue full\n");
     else
     if(front==-1)
     {
     front=0;
     }
     arr[++rear]=value;
}
void dequeue()
{
    if(isEmpty())
    printf("queue empty\n");
    else
    front++;

    //deleting the last element
    if(front>rear)
    front=rear=-1;
}
void size_queue()
{
    if(isEmpty())
    printf("queue empty\n");
    else
    printf("size of the queue = %d",rear-front+1);
}
void peek()
{
    if(isEmpty())
    printf("queue empty\n");
    else
    printf("peek element = %d",arr[front]);
}
void display()
{
    if(isEmpty())
    {
    printf("queue empty\n");
    }
    else
    {
    printf("elements are ");
    
    for(int i=front;i<=rear;i++)
    {
        printf("%d  ",arr[i]);
    }}
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