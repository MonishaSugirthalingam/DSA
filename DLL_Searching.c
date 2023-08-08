#include <stdio.h>
#include <stdlib.h>
//searching
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
        nnode->next=head;
        head->pre=nnode;
        head=nnode;
    }
    }
    //Searching
    int search;
    printf("Enter your searching value : ");
    scanf("%d",&search);
    int flag=0;
    temp=head;
    while(temp!=0)
    {
        if(temp->val==search)
        {
            printf("Yes!!!..Searching values is there in DLL\n");
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("No!!..Searching value is not there in DLL\n");
    }
    return 0;
}
