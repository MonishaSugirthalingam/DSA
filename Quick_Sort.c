#include <stdio.h>
void swap(int,int);
int i_iteration(int,int);
int j_iteration(int,int);
int static n;
struct QuickSort
{
    int q[100];
}s;
int main()
{
    
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a=0;int b=n;
    printf("Enter the array elements one by one : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s.q[i]);
    }
    
    int pivot=s.q[a];
    int a=i_iteration(a+1,pivot);
    int b=j_iteration(b-1,pivot);
    printf("a=%d b=%d\n",a,b);
    while(a<b)
    {
        swap(a,b);
        a=i_iteration(a,pivot);
        b=j_iteration(b,pivot);
        printf("a=%d b=%d\n",a,b);
    }
    printf("pivot position - %d\n",a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",s.q[i]);
    }
    return 0;
}
void swap(int a,int b)
{
    int temp;
    temp=s.q[a];
    s.q[a]=s.q[b];
    s.q[b]=temp;
}
int i_iteration(int a,int pivot)
{
    while(s.q[a]<pivot)
    {
        a++;
    }
    return a;
}
int j_iteration(int b,int pivot)
{
    while(s.q[b]>pivot)
    {
        b--;
    }
    return b;
}