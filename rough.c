#include <stdio.h>
#include <stdlib.h>
//Multiplication
struct POL1
{
    int val;
    int coeffi;
    struct POL1 *next;
}*head1;
struct POL2
{
    int val;
    int coeffi;
    struct POL2 *next;
}*head2;
struct RESULT
{
    int val;
    int coeffi;
    struct RESULT *next;
}*head;
struct ADD
{
    int val;
    int coeffi;
    struct ADD *next;
}*final;
struct POL2 *temp2,*nnode2;
struct POL1 *temp1,*nnode1;
struct RESULT *nnode,*temp;
struct ADD *t1,*t2;
int main()
{
    int terms,terms2,power,value,terms1;
    printf("Enter the numbers of terms in first and second polynomial : ");
    scanf("%d %d",&terms1,&terms2);
    for(int i=terms1-1;i>=0;i--)
    {
        nnode1=(struct POL1*)malloc(sizeof(struct POL1));
        printf("Enter the power of x : ");
        scanf("%d",&power);
        printf("Enter the coefficient of x^%d : ",power);
        scanf("%d",&value);
        nnode1->val=value;
        nnode1->coeffi=power;
        nnode1->next=0;
        if(head1==0)
        {
            head1=nnode1;
        }
        else
        {
            temp1=head1;
            while(temp1->next!=0)
            {
                temp1=temp1->next;
            }
            temp1->next=nnode1;
        }
    }
    for(int i=terms2-1;i>=0;i--)
    {
        nnode2=(struct POL2*)malloc(sizeof(struct POL2));
        printf("Enter the power of x : ");
        scanf("%d",&power);
        printf("Enter the coefficient of x^%d : ",power);
        scanf("%d",&value);
        nnode2->val=value;
        nnode2->coeffi=power;;
        nnode2->next=0;
        if(head2==0)
        {
            head2=nnode2;
        }
        else
        {
            temp2=head2;
            while(temp2->next!=0)
            {
                temp2=temp2->next;
            }
            temp2->next=nnode2;
        }
    }
    printf("POLYNOMIAL ONE \n");
    temp1=head1;
    while(temp1!=0)
    {
        printf(" ==> Co-efficient of x^%d %d\n",temp1->coeffi,temp1->val);
        temp1=temp1->next;
    }
    printf("\n");
    printf("POLYNOMIAL SECOND\n");
    temp2=head2;
    while(temp2!=0)
    {
        printf(" ==> Co-efficient of x^%d %d \n",temp2->coeffi,temp2->val);
        temp2=temp2->next;
    }
    printf("\n");
    printf("MULTIPLICATION OF GIVEN TWO POLYNOMIAL : ");
    temp1=head1;
    temp2=head2;
    while(temp1!=0)
    {
        temp2=head2;
        while(temp2!=0)
        {
            nnode=(struct RESULT*)malloc(sizeof(struct RESULT));
            nnode->val=temp1->val*temp2->val;
            nnode->coeffi=temp1->coeffi+temp2->coeffi;
            nnode->next=0;
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
                temp->next=nnode;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    struct ADD *new;
    new=(struct ADD*)malloc(sizeof(struct ADD));
    new->val=head->val;
    new->coeffi=head->coeffi;
    new->next=0;
    final=new;
    temp=head->next;
    while(temp!=0)
    {
       new=(struct ADD*)malloc(sizeof(struct ADD)) ;
       t1=final;
       while(t1!=0)
       {
           if(t1->coeffi==temp->coeffi)
           {
               new->coeffi=t1->coeffi;
               new->val=t1->val+temp->val;
           }
           t1=t1->next;
       }
       temp=temp->next;
    }
    t2=final;
    while(t2!=0)
    {
        printf("%d %d\n",t2->val,t2->coeffi);
        t2=t2->next;
    }
    temp=head;
    while(temp!=0)
    {
        printf("==>Co-efficient of X^%d %d\n",temp->coeffi,temp->val);
        temp=temp->next;
    }
    
}
