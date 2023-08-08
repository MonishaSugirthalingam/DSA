#include <stdio.h>
#include <stdlib.h>
//Ending Insertion
struct DLL 
{
    int val;
    struct DLL *pre;
    struct DLL *next;
}*head;
int main()
{
    int num,n;
    struct DLL *nnode,*temp;
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
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return 0;
}
