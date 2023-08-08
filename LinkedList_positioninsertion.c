#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;

struct LinkedList *temp,*newalloc;
int main()
{
    int num,n;
    printf("Enter the number of nodes that created by you in forward direction: ");
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
            newalloc->link=head;
            head=newalloc;
        }
    }
    int pos;
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
    //to display the nodes
    temp=head;
    printf("Elements in LinkedList are : ");
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->link;
    }
}