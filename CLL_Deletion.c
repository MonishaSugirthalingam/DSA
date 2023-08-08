#include <stdio.h>
#include <stdlib.h>
//deletion
struct CLL
{
    int val;
    struct CLL *next;
}*head;
struct CLL *temp,*nnode,*t;
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
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        nnode->next=head;
        }
    }
    //deletion
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
        temp->next=head->next;
        head=head->next;
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
            t->next=temp->next;
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
                t->next=head;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("Given position is not found\n");
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