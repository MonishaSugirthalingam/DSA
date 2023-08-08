#include <stdlib.h>
#include <stdio.h>
//End insertion in LinkedList
struct LinkedList
{
    int val;
    struct LinkedList *link;
}*head;
int main()
{
    int num,n;
    struct LinkedList *temp,*newalloc;
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
