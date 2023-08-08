#include <stdio.h>
void swap(int*,int*);
int partition(int q[],int,int);
void quicksort(int q[],int,int);
void displayfun(int q[]);
int static n;
int main()
{
    int q[100];
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the array elements one by one : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    printf("ARRAY BEFORE SORTED : ");
    displayfun(q);
    quicksort(q,0,n-1);
    printf("ARRAY AFTER SORTED : ");
    displayfun(q);
    return 0;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int q[],int low,int high)
{
    int pivot=q[low];
    int i=low+1;
    int j=high;
    do{
        while(q[i]<=pivot)
        {
            i++;
        }
        while(q[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(&q[i],&q[j]);
        }
    
    }while(i<j);
    
    swap(&q[low],&q[j]);
    return i;
}
void quicksort(int q[],int low,int high)
{
    int partitionIndex;
    
    if(low<high)
    {
        int partitionIndex=partition(q,low,high);
        quicksort(q,low,partitionIndex-1);
        quicksort(q,partitionIndex+1,high);
    }
}
void displayfun(int q[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}