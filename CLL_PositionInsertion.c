#include <stdio.h>
#include <stdlib.h>
struct CLL
{
    int val;
    struct CLL *next;
}*head;
struct CLL *nnode,*t,*temp;
int main()
{
    int num;
    printf("Enter the number of inputs which you want to insert : ");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
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
    //display
    temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->val);
        temp=temp->next;
        
    }
    if(temp->next==head)
    {
        printf("%d ",temp->val);
    } 
}