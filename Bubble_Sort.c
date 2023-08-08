#include <stdio.h>
//Bubble Sort
int main()
{
    int n=10,temp;
    int arr[10]={23,100,78,2,90,2,1,45,900,0};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
