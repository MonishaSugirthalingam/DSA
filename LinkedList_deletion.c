#include <stdlib.h>
#include <stdio.h>
//starting deletion in LinkedList
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;
int main()
{
    int num,n;
    struct LinkedList *temp,*newalloc,*nullpointer;
    //node creating operation
    printf("Enter the number of nodes that created by you : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
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
    //deletion at front
    int pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        head=head->link;
    }
    //deletion at end 
    else if(pos==n-1)
    {
        temp=head;
        while(temp->link!=0)
        {
            nullpointer=temp;
            temp=temp->link;
        }
        nullpointer->link=temp->link;
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
    //to display the nodes
    temp=head;
    printf("Elements in LinkedList are : ");
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->link;
    }
    return 0;
}
