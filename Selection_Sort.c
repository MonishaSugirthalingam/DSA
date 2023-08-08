#include <stdio.h>
//selection sort
int main()
{
    int n=10,temp,mid;
    int arr[10]={23,100,78,2,90,2,1,45,900,0};
    for(int i=0;i<n;i++)
    {
        mid=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mid])
            {
                mid=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[mid];
        arr[mid]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
