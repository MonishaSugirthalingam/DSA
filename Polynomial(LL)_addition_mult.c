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
struct RESULT *nnode,*temp,*te;
struct ADD *new,*t1,*t2;
void addition();
void multiplication();
int main()
{
    int choice;
    printf("If you want to do ADDITION then PRESS-1\nIf you want to do MULTIPLICATION then PRESS-2\nIf you want to exit then PRESS-3\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=3)
    {
        if(choice==1)
        {
            addition();
        }
        else if(choice==2)
        {
            multiplication();
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("\nIf you want to do ADDITION then PRESS-1\nIf you want to do MULTIPLICATION then PRESS-2\nIf you want to exit then PRESS-3\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
}

void addition()
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
    printf("ADDITION OF GIVEN TWO POLYNOMIAL\n");
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
    head=0;
    head1=0;
    head2=0;
}

void multiplication()
{
   int terms,terms2,power,value,terms1;
    printf("Enter the numbers of terms in first and second polynomial : ");
    scanf("%d %d",&terms1,&terms2);
    printf("Enter the coefficient and exponent of first polynomial\n");
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
    printf("Enter the coefficient and exponent of second polynomial\n");
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
    printf("MULTIPLICATION OF GIVEN TWO POLYNOMIAL\n");
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
    int count=0;
    temp=head;
    while(temp!=0)
    {
        te=temp->next;
        while(te!=0)
        {
            if(te->coeffi==temp->coeffi)
            {
                count++;
            }
            te=te->next;
        }
        temp=temp->next;
    }
    if(count>0)
    {
        temp=head;
        int flag=0;
        while(temp!=0)
        {
            if(final==0)
            {
                new=(struct ADD*)malloc(sizeof(struct ADD));
                new->val=temp->val;
                new->next=0;
                new->coeffi=temp->coeffi;
                final=new;
            }
            else
            {
                t1=final;
                while(t1->next!=0)
                {
                    t1=t1->next;
                    if(t1->coeffi==temp->coeffi)
                    {
                        flag=1;
                        t1->val=t1->val+temp->val;
                    }
                }
                if(flag==0)
                {
                    new=(struct ADD*)malloc(sizeof(struct ADD));
                    new->val=temp->val;
                    new->next=0;
                    new->coeffi=temp->coeffi;
                    t1->next=new;
                }
                flag=0;
            }
            temp=temp->next;
        }
        t1=final;
        while(t1!=0)
        {
            printf("==>Co-efficient of X^%d %d\n",t1->coeffi,t1->val);
            t1=t1->next;
        }
    }
    else
    {
        temp=head;
        while(temp!=0)
        {
            printf("==>Co-efficient of X^%d %d\n",temp->coeffi,temp->val);
            temp=temp->next;
        }
    
    }
    head=0;
    head1=0;
    head2=0;
    final=0;
}