#include <stdio.h>
#include <stdlib.h>

struct endpalindrome
{
   char letters;
   struct endpalindrome *next;
}*head1;
struct beginpalindrome
{
    char letters;
    struct beginpalindrome *next;
}*head2;
struct endpalindrome *nnode1,*temp1;
struct beginpalindrome *nnode2,*temp2;
void createlist(char s[]);
void checkpalindrome();
int main()
{
    char word[50];
    printf("Enter the word : ");
    scanf("%s",word);
    createlist(word);
    checkpalindrome();
    return 0;
}
void createlist(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        nnode1=(struct endpalindrome*)malloc(sizeof(struct endpalindrome));
        nnode1->letters=s[i];
        nnode1->next=0;
        
        nnode2=(struct beginpalindrome*)malloc(sizeof(struct beginpalindrome));
        nnode2->letters=s[i];
        nnode2->next=0;
        
        if(head1==0 && head2==0)
        {
            head1=nnode1;
            head2=nnode2;
        }
        else
        {
            nnode2->next=head2;
            head2=nnode2;
            
            temp1=head1;
            while(temp1->next!=0)
            {
                temp1=temp1->next;
            }
            temp1->next=nnode1;
        }
    }
}

void checkpalindrome()
{
    int count1=0;
    int count2=0;
    temp1=head1;
    temp2=head2;
    while(temp1!=0 && temp2!=0)
    {
        if(temp1->letters==temp2->letters)
        {
            count1++;
        }
        temp1=temp1->next;
        temp2=temp2->next;
        count2++;
    }
    if(count1==count2)
    {
        printf("Yes..Given word is a Palindrome\n");
    }
    else
    {
        printf("No..Given word is not a palindrome\n");
    }
}