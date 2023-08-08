#include <stdio.h>
#include <stdlib.h>
//Queue using linkedlist
void enqueue();
void dequeue();
void searching();
void display();
void frontrear();
int static MAX=5;
int static front=0;
int static rear=0;
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;
struct LinkedList *temp,*nnode;
int main()
{
    int choice;
    printf("If you want to enqueue any elements PRESS-1\nIf you want to dequeue any elements PRESS-2\nIf you want to search any element PRESS-3\nIf you want to display all elements then PRESS-4\nIf you want to known front and rear elements then PRESS-5\nIf you want to exit then PRESS-6\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=6)
    {
       if(choice==1)
       {
          enqueue();
       }
       else if(choice==2)
       {
           dequeue();
       }
       else if(choice==3)
       {
           searching();
       }
       else if(choice==4)
       {
           display();
       }
       else if(choice==5)
       {
           frontrear();
       }
       else
       {
           printf("Wrong choice enter again\n");
       }
       printf("Enter your choice : ");
       scanf("%d",&choice);
    }
    return 0;
}
void enqueue()
{
    if(rear==MAX)
    {
        printf("Queue is Full\n");
    }
    else{
    int num;
    printf("Enter the Number which you want to insert : ");
    scanf("%d",&num);
    nnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    rear=rear+1;
    nnode->val=num;
    nnode->link=0;
    if(head==0)
    {
        head=nnode;
    }
    else
    {
        temp=head;
        while(temp->link!=0)
        {
            temp=temp->link;
        }
        temp->link=nnode;
    }
    if(front==0)
    {
        front++;
    }
    }
}
void dequeue()
{
    if(head==0 || front==0 || rear==0)
    {
        printf("Queue IS EMPTY\n");
    }
    else if(front==rear)
    {
        front=0;
        rear=0;
        head=0;
    }
    else
    {
        temp=head;
        head=temp->link;
        front++;
    }
}
void searching()
{
    if(front==0)
    {
        printf("Queue IS EMPTY\n");
    }
    else
    {
        int search,flag=0;
        printf("Enter the searching element which you are search : ");
        scanf("%d",&search);
        temp=head;
        while(temp!=0)
        {
            if(temp->val==search)
            {
            printf("Yes!...searching element %d is there\n",search);
            flag=1;
            break;
            }
            temp=temp->link;
        }
        if(flag==0)
        {
            printf("No!!..searching element %d is Not there\n",search);
        }
    }
    
}
void display()
{
    if(head==0 || front==0)
    {
        printf("Queue IS EMPTY\n");
    }
    else
    {
        temp=head;
        while(temp!=0)
        {
            printf("%d ",temp->val);
            temp=temp->link;
        }
        printf("\n");
    }
}
void frontrear()
{
    if(front==0)
    {
        printf("FRONT : %d REAR : %d\n",front,rear);
    }
    else
    {
        printf("FRONT : %d REAR : %d\n",front,rear);
    }
}