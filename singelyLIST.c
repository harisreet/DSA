#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*insert_b(struct node**head,int value)
{
     struct node*new=(struct node*)malloc(sizeof(struct node));

     new->data=value;

     //point to head
     new->next=*head;

     printf("new node has been inserted at beginning\n");


     *head=new;
     return *head;
}
struct node*insert_e(struct node**head,int value)
{
    struct node*new=(struct node*)malloc(sizeof(struct node));

    new->data=value;
    new->next=NULL;

    struct node*temp=*head;

    //head->NULL 
    if(*head==NULL)
    {
        *head=new;
    }

    else
    {
    
    //traverse to end
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    }
    
    temp->next=new;
    printf("new node has been inserted at end\n");
    return *head;

}
struct node*insert_p(struct node**head,int value,int position)
{
    if(position<0)
    {
      printf("invalid\n");
    }
    if(position==1)
    {
        return insert_b(head,value);
    }
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=value;

    struct node*temp=*head;

    //before position,true
    while(--position >1)
    {
        printf("%d\n",position);
        temp=temp->next;
    }

    //position 0 ponits to 1
    new->next=temp->next;

    //position -1 points to 0
    temp->next=new;
    return *head;
}

struct node*delete_b(struct node**head)
{
  struct node*temp=*head;

  struct node*ptr=temp;

  //delete the first node
  free(ptr);

  //traverse to next node
  temp=temp->next;

  *head=temp;
  return *head;
}

struct node*delete_e(struct node**head)
{
    struct node*temp=*head;

    //1->2->3->NULL

    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    struct node*ptr=temp->next;
    free(ptr);

    temp->next=NULL;

    return *head;

}

struct node*delete_p(struct node**head,int position)
{
   if(position<1)
   {
    printf("invalid\n");
   }

   struct node*temp=*head;

   while(--position>1)
   {
     temp=temp->next;
   }

   //1->2->3->NULL

   struct node*ptr=temp->next;

   temp->next=ptr->next;
   free(ptr);

   return *head;
}

void length(struct node**head)
{
    struct node*temp=*head;
    int count=0;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("LENGTH OF LINKED LIST = %d\n",count);
}

struct node*reverse(struct node**head)
{
  struct node*temp=*head;
  struct node*previous=NULL;
  struct node*nextt=*head;

  //1->2->3->NULL

  //NULL<-3<-2<-1

  while(nextt!=NULL)
  {
    nextt=nextt->next;
    temp->next=previous;
    previous=temp;
    temp=nextt;
  }

  *head=previous;
  return *head;
}
void print(struct node**head)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=*head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main()
{
    struct node*head=NULL;
    int choice,value,x,position;
   
    do
    {
    printf ("enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter value to be inserted at beginning : ");
        scanf("%d",&value);
        head=insert_b(&head,value);
        break;

        case 2:
        printf("enter value to be inserted at end : ");
        scanf("%d",&value);
        head=insert_e(&head,value);
        break;

        case 3:
        printf("enter value to be inserted at the position : ");
        scanf("%d",&value);
        printf("enter  the position : ");
        scanf("%d",&position);
        head=insert_p(&head,value,position);
        break;

        case 4:
        head=delete_b(&head);
        break;

        case 5:
        head=delete_e(&head);
        break;

        case 6:
        printf("enter  the position to delete : ");
        scanf("%d",&position);
        head=delete_p(&head,position);
        break;
        
        case 7:
        length(&head);
        break;

        case 8:
        print(&head);
        break;

        case 9:
        head=reverse(&head);
        break;

    };
    printf("press 0 to continue : ");
    scanf("%d",&x);
    }while(x==0);
     
}