#include <stdio.h>
#include <stdlib.h>
//stack using linkedlist
void push();
void pop();
void searching();
void display();
void peak();
int static MAX=5;
int static top=0;
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;
struct LinkedList *temp,*nnode;
int main()
{
    int choice;
    printf("If you want to push any elements PRESS-1\nIf you want to pop any elements PRESS-2\nIf you want to search any element PRESS-3\nIf you want to display any element then PRESS-4\nIf you want to known peak element then PRESS-5\nIf you want to exit then PRESS-6\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=6)
    {
       if(choice==1)
       {
           push();
       }
       if(choice==2)
       {
           pop();
       }
       if(choice==3)
       {
           searching();
       }
       if(choice==4)
       {
           display();
       }
       if(choice==5)
       {
           peak();
       }
       printf("Enter your choice : ");
       scanf("%d",&choice);
    }
    return 0;
}
void push()
{
    if(top==MAX)
    {
        printf("STACK IS FULL\n");
    }
    else
    {
        int num;
        printf("Enter the Number which you want to insert : ");
        scanf("%d",&num);
        nnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));
        nnode->val=num;
        if(head==0)
        {
            head=nnode;
        }
        else
        {
            nnode->link=head;
            head=nnode;
        }
        top++;
    }
}
void pop()
{
    if(head==0 || top==0)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        temp=head;
        head=temp->link;
        top--;
    }
}
void searching()
{
    if(head==0)
    {
        printf("STACK IS EMPTY\n");
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
    if(head==0)
    {
        printf("STACK IS EMPTY\n");
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
void peak()
{
    if(head==0)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("Peak element is %d and its position is %d\n",head->val,top);
    }
}