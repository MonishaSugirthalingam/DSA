#include <stdio.h>
//Binary Search
int main()
{
    int value,mid;
    int arr[10]={23,56,78,90,100,120,450,500,890,10000};
    printf("Enter the searching value : ");
    scanf("%d",&value);
    int n=10;
    int start=0;
    int end=n;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==value)
        {
            printf("Yes!!!..%d is there in array",value);
            break;
        }
        else
        {
            if(value>arr[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
    return 0;
}
