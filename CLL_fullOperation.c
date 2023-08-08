#include <stdio.h>
#include <stdlib.h>
//circular linked list
void beginingInsertion();
void endInsertion();
void positionInsertion();
void beginingDeletion();
void endDeletion();
void positionDeletion();
void display();
void searching();

struct CLL
{
    int val;
    struct CLL *next;
}*head;

struct CLL *nnode,*temp,*t;
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
            beginingInsertion();
          }
          else if(choice==12)
          {
            endInsertion(); 
          }
          else if(choice==13)
          {
            positionInsertion();  
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
            beginingDeletion(); 
          }
          else if(choice==22)
          {
            endDeletion(); 
          }
          else if(choice==23)
          {
            positionDeletion();  
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
void beginingInsertion()
{
    int value;
    printf("Enter the value :");
    scanf("%d",&value);
    nnode=(struct CLL*)malloc(sizeof(struct CLL));
    nnode->val=value;
    if(head==0)
    {
        head=nnode;
        nnode->next=head;
    }
    else
    {
        nnode->next=head;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        head=nnode;
    }
}
void endInsertion()
{
    int value;
    printf("Enter the value :");
    scanf("%d",&value);
    nnode=(struct CLL*)malloc(sizeof(struct CLL));
    nnode->val=value;
    if(head==0)
    {
        head=nnode;
        nnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        nnode->next=head;
    }
}
void positionInsertion()
{
   int value,pos;
    printf("Enter the position and value : ");
    scanf("%d %d",&pos,&value);
    nnode=(struct CLL*)malloc(sizeof(struct CLL));
    nnode->val=value;
    if(pos==1)
    {
        if(head==0)
        {
            head=nnode;
            nnode->next=head;
        }
        else
        {
        nnode->next=head;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        head=nnode;
        }
    }
    else
    {
        int count=1,flag=0;
        temp=head;
        while(temp->next!=head && count<pos)
        {
            t=temp;
            temp=temp->next;
            count++;
        }
        if(count==pos)
        {
            nnode->next=temp;
            t->next=nnode;
            flag=1;
        }
        if(flag==0)
        {
            if(head==0)
            {
                head=nnode;
                nnode->next=head;
            }
            else
            {
                int count=1;
                temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                    count++;
                }
                count++;
                if(count==pos)
                {
                    nnode->next=temp->next;
                    temp->next=nnode;
                    
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            printf("position not found\n");
        }
    }
}

void beginingDeletion()
{
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else
    {
        temp->next=head->next;
        head=head->next;
    }
}

void endDeletion()
{
    temp=head;
    while(temp->next!=head)
    {
        t=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
       head=0; 
    }
    else
    {
        t->next=head;
    }
    
}

void positionDeletion()
{
    int pos;
    printf("Enter position which you want to delete : ");
    scanf("%d",&pos);
    //begining deletion
    if(pos==1)
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        if(temp==head)
        {
            head=0;
        }
        else
        {
            temp->next=head->next;
            head=head->next;
        }
    }
    else
    {
    //position deletion
    temp=head;
    int count=1;
    int flag=0;
    while(temp->next!=head && count<pos)
    {
        t=temp;
        temp=temp->next;
        count++;
    }
    if(count==pos)
    {
        if(temp==head)
        {
            printf("CLL is Empty\n");
        }
        else
        {
            t->next=temp->next;
        }
        flag=1;
    }
    if(flag==0)//end deletion
    {
        int count=0;
        temp=head;
        while(temp->next!=head)
        {
            t=temp;
            temp=temp->next;
            count++;
        }
        if(count==pos)
        {
            if(temp==head)
            {
                head=0; 
            }
            else
            {
                t->next=head;
            }
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("Given position is not found\n");
    }
    }
}

void display()
{
   temp=head;
    if(head==0)
    {
       printf("CLL is Empty\n");
    }
    else
    {
        while(temp->next!=head)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        if(temp->next==head)
        {
            printf("%d ",temp->val);
        } 
         printf("\n");
    }
    
}

void searching()
{
    int search;
    printf("Enter the searching value : ");
    scanf("%d",&search);
    int count=0;
    temp=head;
    while(temp->next!=head)
    {
       if(temp->val==search)
       {
           count++;
       }
       temp=temp->next;
    }
    if(temp->next==head && temp->val==search)
    {
        count++;
    } 
    if(count>0)
    {
        printf("Yes..Searching value %d is there in CLL\n",search);
    }
    if(count==0)
    {
        printf("No..Searching value %d is Not there in CLL\n",search);
    }
}
