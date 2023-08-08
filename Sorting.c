#include <stdio.h>
void insertion_sort(int);
void bubble_sort(int);
void selection_sort(int);
void counting_sort(int);
struct sorting
{
    int arr[50];
}s;
int main()
{
    int choice,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the array elements one by one : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s.arr[i]);
    }
    printf("If you want to perform Insertion Sort then PRESS-1\nIf you want to perform Bubble Sort then PRESS-2\nIf you want to perform Selection Sort then PRESS-3\nIf you want to perform Counting Sort then PRESS-4\nIf you want to exit from these opeartions then PRESS-5\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=5)
    {
        if(choice==1)
        {
            insertion_sort(n);
        }
        else if(choice==2)
        {
            bubble_sort(n);
        }
        else if(choice==3)
        {
            selection_sort(n);
        }
        else
        {
            counting_sort(n);
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
    return 0;
}
void insertion_sort(int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        int temp=s.arr[i];
        int j=i-1;
        while(j>=0 && s.arr[j]>temp)
        {
            s.arr[j+1]=s.arr[j];
            j--;
        }
        s.arr[j+1]=temp;
    }
    printf("After Sorting the Given array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s.arr[i]);
    }
    printf("\n");
}
void bubble_sort(int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s.arr[i]>s.arr[j])
            {
                temp=s.arr[i];
                s.arr[i]=s.arr[j];
                s.arr[j]=temp;
            }
        }
    }
    printf("After Sorting the Given array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s.arr[i]);
    }
    printf("\n");
}
void selection_sort(int n)
{
    int temp,mid;
    for(int i=0;i<n;i++)
    {
        mid=i;
        for(int j=i+1;j<n;j++)
        {
            if(s.arr[j]<s.arr[mid])
            {
                mid=j;
            }
        }
        temp=s.arr[i];
        s.arr[i]=s.arr[mid];
        s.arr[mid]=temp;
    }
    printf("After Sorting the Given array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s.arr[i]);
    }
    printf("\n");
}
void counting_sort(int n)
{
    int max=s.arr[0];
    int z[10];
    //finding the max element in array
    for(int i=1;i<n;i++)
    {
        if(s.arr[i]>max)
        {
            max=s.arr[i];
        }
        z[i]=0;
    }
    //Create an counting array with max+1 size
    int y[max+1];
    //initialize the counting array with value 0
    for(int j=0;j<max+1;j++)
    {
        y[j]=0;
    }
    //increase the value of each element in counting array with respect to the x array elements
    for(int i=0;i<n;i++)
    {
        y[s.arr[i]]=y[s.arr[i]]+1;
    }
    //creating the updated array by adding neighbour element
    for(int i=1;i<max+1;i++)
    {
        y[i]=y[i]+y[i-1];
    }
    //sorting steps
    for(int i=n-1;i>=0;i--)
    {
        y[s.arr[i]]=y[s.arr[i]]-1;
        z[y[s.arr[i]]]=s.arr[i];
    }
    //display the sorted array
    printf("After Sorting the Given array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",z[i]);
    }
    printf("\n");
}