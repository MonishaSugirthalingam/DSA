#include <stdio.h>
#include <stdlib.h>
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
    printf("Enter the value which your are search : ");
    scanf("%d",&num);
    temp=head;
    int flag=0;
    while(temp!=0)
    {
        if(temp->val==num)
        {
            printf("Yes!!..the searching value %d  is there in linkedlist",num);
            flag=1;
            break;
        }
        temp=temp->link;
    }
    if(flag==0)
    {
        printf("No!!..the searching value %d is not there in linkedlist",num);
    }
    return 0;
}
