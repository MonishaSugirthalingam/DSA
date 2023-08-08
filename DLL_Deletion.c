#include <stdio.h>
#include <stdlib.h>
//Deletion
struct DLL 
{
    int val;
    struct DLL *pre;
    struct DLL *next;
}*head;
int main()
{
    int num,n;
    struct DLL *nnode,*temp,*t1;
    printf("How many elements do you want to insert : ");
    scanf("%d",&n);
    printf("Enter the element which you want to insert(one by one) : ");
    for(int i=0;i<n;i++)
    {
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
    //Deletion
    printf("Enter the number which you want to delete : ");
    scanf("%d",&num);
    int flag=0;
    if(head->val==num)
    {
        head=head->next;
        head->next->pre=0;
        flag=1;
    }
    if(flag==0)
    {
        temp=head;
        while(temp->next!=0)
        {
            t1=temp;
            temp=temp->next;
        }
        if(temp->val==num)
        {
            t1->next=0;
            flag=1;
            printf("Deleted item : %d\n",temp->val);
        }
    }
    if(flag==0)
    {
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
    //display
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return 0;
}
