#include <stdio.h>
#include <stdlib.h>
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
    struct RESULT *next;
}*head;
struct POL2 *temp2,*nnode2;
struct POL1 *temp1,*nnode1;
struct RESULT *nnode,*temp;
int main()
{
    int terms,terms2,power,value,terms1;
    printf("Enter the numbers of terms in first and second polynomial : ");
    scanf("%d %d",&terms1,&terms2);
    if(terms1>=terms2)
    {
        terms=terms1;
    }
    else
    {
        terms=terms2;
    }
    for(int i=terms-1;i>=0;i--)
    {
        nnode1=(struct POL1*)malloc(sizeof(struct POL1));
        nnode1->val=0;
        nnode1->coeffi=i;
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
    printf("Enter the coefficient and exponent for First Polynomial\n");
    for(int i=0;i<terms1;i++)
    {
        printf("Enter the power of x : ");
        scanf("%d",&power);
        printf("Enter the coefficient of x^%d : ",power);
        scanf("%d",&value);
        temp1=head1;
        while(temp1->coeffi!=power)
        {
            temp1=temp1->next;
        }
        temp1->val=value;
    }
    for(int i=terms-1;i>=0;i--)
    {
        nnode2=(struct POL2*)malloc(sizeof(struct POL2));
        nnode2->val=0;
        nnode2->coeffi=i;;
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
    printf("Enter the coefficient and exponent for Second Polynomial\n");
    for(int i=0;i<terms2;i++)
    {
        printf("Enter the power of x : ");
        scanf("%d",&power);
        printf("Enter the coefficient of x^%d : ",power);
        scanf("%d",&value);
        temp2=head2;
        while(temp2->coeffi!=power)
        {
            temp2=temp2->next;
        }
        temp2->val=value;
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
    printf("ADDITION OF GIVEN TWO POLYNOMIAL : ");
    int count=0;
    temp1=head1;
    temp2=head2;
    while(count<terms)
    {
        nnode=(struct RESULT*)malloc(sizeof(struct RESULT));
        nnode->val=temp1->val+temp2->val;
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
        count++;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1=head1;
    temp=head;
    while(temp!=0 && temp1!=0)
    {
        printf("Co-efficient of X^%d %d\n",temp1->coeffi,temp->val);
        temp=temp->next;
        temp1=temp1->next;
    }
    printf("\n");
}

