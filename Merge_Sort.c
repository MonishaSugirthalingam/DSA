#include <stdio.h>
void displayfun(int m[]);
void merge(int m[],int,int,int);
void merge_sort(int m[],int,int);
int static n;
int main()
{
    int m[100];
    printf("Ente the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements one by one : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
    printf("ARRAY BEFORE SORTED : ");
    displayfun(m);
    merge_sort(m,0,n-1);
    printf("ARRAY AFTER SORTED : ");
    displayfun(m);
    return 0;
}
void displayfun(int m[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",m[i]);
    }
    printf("\n");
}
void merge(int m[],int mid,int low,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int result[100];
    while(i<=mid && j<=high)
    {
        if(m[i]<m[j])
        {
            result[k]=m[i];
            i++;
            k++;
        }
        else
        {
            result[k]=m[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        result[k]=m[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        result[k]=m[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        m[i]=result[i];
    }
}
void merge_sort(int m[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(m,low,mid);
        merge_sort(m,mid+1,high);
        merge(m,mid,low,high);
    }
}