#include <stdio.h>
#include <stdlib.h>
void minheapsort();
void maxheapsort();
void minheapify();
void maxheapify();
void swap();
void display();
int main()
{
   int choice,N,arr[100];
   printf("Enter the size of the array : ");
   scanf("%d",&N);
   for(int i=0;i<N;i++)
   {
       scanf("%d",&arr[i]);
   }
   printf("If you want to perform MinHeapSort then PRESS-1\nIf ypu want to perform MaxHeapSort then PRESS-2\nIf you want to exit then PRESS-3\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   while(choice!=3)
   {
       if(choice==1)
       {
            minheapsort(arr,N);
            printf("Sorted array(Using MinHeapSort) is\n");
            display(arr,N);
       }
       else if(choice==2)
       {
            maxheapsort(arr,N);
            printf("Sorted array(Using MaxHeapSort) is\n");
            display(arr,N);
       }
       else
       {
           printf("Invalid choice\n");
       }
       printf("Enter your choice : ");
       scanf("%d",&choice);
   }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxheapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<N && arr[left]>arr[largest])
    {
        largest = left;
    }
    if (right<N && arr[right]>arr[largest])
    {
        largest = right;
    }
    if (largest!=i) 
    {
        swap(&arr[i],&arr[largest]);
        maxheapify(arr,N,largest);
    }
}
void maxheapsort(int arr[], int N)
{
    for (int i=N/2-1;i>=0;i--)
    {
        maxheapify(arr,N,i);
    }
    for (int i=N-1;i>=0; i--) 
    {
        swap(&arr[0],&arr[i]);
        maxheapify(arr,i,0);
    }
}
void display(int arr[],int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
void minheapify(int arr[], int N, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<N && arr[left]<arr[smallest])
    {
        smallest = left;
    }
    if (right<N && arr[right]<arr[smallest])
    {
        smallest = right;
    }
    if (smallest!=i) 
    {
        swap(&arr[i],&arr[smallest]);
        minheapify(arr,N,smallest);
    }
}
void minheapsort(int arr[], int N)
{
    for (int i=N/2-1;i>=0;i--)
    {
        minheapify(arr,N,i);
    }
    for (int i=N-1;i>=0; i--) 
    {
        swap(&arr[0],&arr[i]);
        minheapify(arr,i,0);
    }
}