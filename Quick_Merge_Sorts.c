#include <stdio.h>
void Quick_sort();
void Merge_sort();
void swap(int*,int*);
int partition(int q[],int,int);
void quicksort(int q[],int,int);
void merge(int m[],int,int,int);
void merge_sort(int m[],int,int);
void displayfun(int q[]);
int static n;
int main()
{
    int choice;
    printf("If you want to sort the array using QUICK SORT then PRESS-1\nIf you want to sort the array using MERGE SORT then PRESS-2\nIf you want to EXIT then PRESS-3\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=3)
    {
        if(choice==1)
        {
            Quick_sort();
        }
        if(choice==2)
        {
            Merge_sort();
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
}
void Quick_sort()
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
void Merge_sort()
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