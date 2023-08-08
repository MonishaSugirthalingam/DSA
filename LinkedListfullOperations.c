#include <stdio.h>
#include <stdlib.h>
//linkedlist operations
void begininginsertion();
void endinsertion();
void beginingdeletion();
void enddeletion();
void positioninsertion();
void positiondeletion();
void display();
void searching();
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;
struct LinkedList *temp,*nnode,*nullpointer,*newalloc;
int main()
{
    int choice;
    printf("If you want to Insert any elements then PRESS-1\nIf you want to delete any element PRESS-2\nIf you want to search any element PRESS-3\nIf you want to display all elements then PRESS-4\nIf you want to exit then PRESS-5\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=5)
    {
       if(choice==1)
       {
          printf("Beginning Insertion=> PRESS 11\nEnding Insertion=> PRESS 12\nPosition Insertion=> PRESS 13\n");
          printf("Enter your choice : ");
          scanf("%d",&choice);
          if(choice==11)
          {
            begininginsertion();
          }
          else if(choice==12)
          {
            endinsertion(); 
          }
          else if(choice==13)
          {
            positioninsertion();  
          }
          else
          {
              printf("Choice Invalid\n");
          }
       }
       else if(choice==2)
       {
           printf("Begining Deletion=> PRESS 21\nEnd Deletion=> PRESS 22\nPosition Deletion=> PRESS 23\n");
           printf("Enter your choice : ");
           scanf("%d",&choice);
          if(choice==21)
          {
            beginingdeletion(); 
          }
          else if(choice==22)
          {
            enddeletion(); 
          }
          else if(choice==23)
          {
            positiondeletion();  
          }
          else
          {
              printf("Choice Invalid\n");
          }
       }
       else if(choice==3)
       {
           searching();
       }
       else if(choice==4)
       {
           display();
       }
       else
       {
           printf("Invalid Choice\n");
       }
       printf("For Insertion ==> PRESS-1\nFor Deletion ==> PRESS-2\nFor Searching ==> PRESS-3\nFor Display ==> PRESS-4\nFor Exit ==> PRESS-5\n");
       printf("Enter your choice : ");
       scanf("%d",&choice);
    }
    return 0;
}
void begininginsertion()
{
    int num,n;
    struct LinkedList *temp,*newalloc;
    
    printf("Enter the value : ");
    scanf("%d",&num);
    newalloc=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    newalloc->val=num;
    newalloc->link=0;
    if(head==0)
    {
        head=newalloc;
    }
    else
    {
        newalloc->link=head;
        head=newalloc;
    }
}
void endinsertion()
{
    int num,n;
    struct LinkedList *temp,*newalloc;
    printf("Enter the value : ");
    scanf("%d",&num);
    newalloc=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    newalloc->val=num;
    newalloc->link=0;
    if(head==0)
    {
        head=newalloc;
    }
    else
    {
        temp=head;
        while(temp->link!=0)
        {
            temp=temp->link;
        }
        temp->link=newalloc;
    }
}
void positioninsertion()
{
    int pos,num;
    printf("Enter the position of nodes which you want to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the value : ");
    scanf("%d",&num);
    newalloc=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    int count=1;
    if(pos==0)
    {
        newalloc->link=head;
        newalloc->val=num;
        head=newalloc;
    }
    else
    {
        temp=head;
        while(temp->link!=0 && count<pos)
        {
            temp=temp->link;
            count++;
        }
        if(count==pos)
        {
            newalloc->val=num;
            newalloc->link=temp->link;
            temp->link=newalloc;
        }
    }
}
void beginingdeletion()
{
    head=head->link;
}
void enddeletion()
{
    temp=head;
    while(temp->link!=0)
    {
        nullpointer=temp;
        temp=temp->link;
    }
    nullpointer->link=temp->link;
}
void positiondeletion()
{
    int pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d",&pos);
    int flag=0;
    temp=head;
    if(pos==1)
    {
        head=head->link; 
        flag=1;
    }
    else
    {
        int count=1;
        temp=head;
        while(temp->link!=0 && count<pos)
        {
            nullpointer=temp;
            temp=temp->link;
            count++;
        }
        if(count==pos)
        {
            nullpointer->link=temp->link;
        }
        else
        {
            printf("Given postion not in LinkedList\n");
        }
    }
}
void searching()
{
    int num;
    printf("Enter the value which your are search : ");
    scanf("%d",&num);
    temp=head;
    int flag=0;
    while(temp!=0)
    {
        if(temp->val==num)
        {
            printf("Yes!!..the searching value %d  is there in linkedlist\n",num);
            flag=1;
            break;
        }
        temp=temp->link;
    }
    if(flag==0)
    {
        printf("No!!..the searching value %d is not there in linkedlist\n",num);
    }
}
void display()
{
    if(head==0)
    {
        printf("LinkedList is EMPTY\n");
    }
    else{
    temp=head;
    printf("Elements in LinkedList are : ");
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->link;
    }
    printf("\n");
    }
}
