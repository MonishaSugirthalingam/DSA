#include <stdio.h>
#include <stdlib.h>
//begining insertion
struct CLL
{
    int val;
    struct CLL *next;
}*head;
struct CLL *temp,*nnode;
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