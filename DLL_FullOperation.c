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
struct DLL
{
    int val;
    struct DLL *pre;
    struct DLL *next;
}*head;
struct DLL *temp,*nnode,*t1;
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
    struct DLL *nnode,*temp;
    printf("Enter the element which you want to insert : ");
    scanf("%d",&num);
    nnode=(struct DLL*)malloc(sizeof(struct DLL));
    nnode->pre=0;
    nnode->next=0;
    nnode->val=num;
    if(head==0)
    {
        head=nnode;
    }
    else
    {
        nnode->next=head;
        head->pre=nnode;
        head=nnode;
    }
}
void endinsertion()
{
    int num;
    struct DLL *nnode,*temp;
    printf("Enter the element which you want to insert : ");
    scanf("%d",&num);
    nnode=(struct DLL*)malloc(sizeof(struct DLL));
    nnode->pre=0;
    nnode->next=0;
    nnode->val=num;
    if(head==0)
    {
        head=nnode;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        nnode->pre=temp->next;
        temp->next=nnode;
    }
}
void positioninsertion()
{
    int pos,count=1,num;
    printf("Enter the position : ");
    scanf("%d",&pos);
    printf("Enter the value : ");
    scanf("%d",&num);
    nnode=(struct DLL*)malloc(sizeof(struct DLL));
    nnode->pre=0;
    nnode->next=0;
    nnode->val=num;
    temp=head;
    while(temp->next!=0 && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(count==pos-1)
    {
        nnode->next=temp->next;
        nnode->pre=temp;
        temp->next=nnode;
        nnode->next->pre=nnode;
    }
}
void beginingdeletion()
{
    head=head->next;
    head->next->pre=0;
}
void enddeletion()
{
    temp=head;
    while(temp->next!=0)
    {
        t1=temp;
        temp=temp->next;
    }
    t1->next=0;
    printf("Deleted item : %d\n",temp->val);
}
void positiondeletion()
{
    int num;
    printf("Enter the number which you want to delete : ");
    scanf("%d",&num);
    temp=head;
    while(temp->next!=0 && temp->val!=num)
    {
        t1=temp;
        temp=temp->next;
    }
    if(temp->val==num)
    {
        t1->next=temp->next;
        temp->next->pre=t1;
        printf("Deleted value %d\n",temp->val);
    }
    else
    {
        printf("Deleted item not found\n");
    }
}
void searching()
{
    int search;
    printf("Enter your searching value : ");
    scanf("%d",&search);
    int flag=0;
    temp=head;
    while(temp!=0)
    {
        if(temp->val==search)
        {
            printf("Yes!!!..Searching values is there in DLL\n");
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("No!!..Searching value is not there in DLL\n");
    }
}
void display()
{
    if(head==0)
    {
        printf("DLL is EMPTY\n");
    }
    else
    {
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    }
    
}