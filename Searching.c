#include <stdio.h>
int static n=10;
void linear_search();
void binary_search();
struct searching
{
    int arr[10];
}s;
int main()
{
    int choice;
    printf("Enter the array elements one by one : ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&s.arr[i]);
    }
    printf("If you want implement Linear Search then PRESS-1\nIf you want to implement Binary Search then PRESS-2\nIf you want to exit from the perations then PRESS-3\n");
    printf("Enter Your Choice : ") ;
    scanf("%d",&choice);
    while(choice!=3)
    {
       if(choice==1)
       {
           linear_search();
       }
       else 
       {
           binary_search();
       }
       printf("Enter Your Choice : ") ;
       scanf("%d",&choice);
    }
    return 0;
}
void linear_search()
{
    int value,count=0;
    printf("Enter the searching value : ");
    scanf("%d",&value);
    for(int i=0;i<n;i++)
    {
        if(s.arr[i]==value)
        {
            count++;
        }
    }
    if(count>0)
    {
        printf("Yes!!!..%d is there in array\n",value);
    }
    else
    {
        printf("No!!!.%d is not in array\n",value);
    }
}
void binary_search()
{
    int value,mid,flag=0;
    printf("Enter the searching value : ");
    scanf("%d",&value);
    int start=0;
    int end=n;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(s.arr[mid]==value)
        {
            printf("Yes!!!..%d is there in array\n",value);
            flag=1;
            break;
        }
        else
        {
            if(value>s.arr[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    if(flag==0)
    {
        printf("No!!!.%d is not in array\n",value);
    }
}

