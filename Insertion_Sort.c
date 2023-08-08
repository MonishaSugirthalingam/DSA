#include <stdio.h>
//insertion sort
int main()
{
    int n=10,temp,mid;
    int arr[10]={23,100,78,2,90,2,1,45,900,0};
    
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
