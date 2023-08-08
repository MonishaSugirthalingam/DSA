#include <stdio.h>
//counting sort
int main()
{
    int x[10]={1,6,2,0,4,8,2,4,5,3};
    int max=x[0];
    int z[10];
    //finding the max element in array
    for(int i=1;i<10;i++)
    {
        if(x[i]>max)
        {
            max=x[i];
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
    for(int i=0;i<10;i++)
    {
        y[x[i]]=y[x[i]]+1;
    }
    //creating the updated array by adding neighbour element
    for(int i=1;i<max+1;i++)
    {
        y[i]=y[i]+y[i-1];
    }
    //sorting steps
    for(int i=10-1;i>=0;i--)
    {
        y[x[i]]=y[x[i]]-1;
        z[y[x[i]]]=x[i];
    }
    //display the sorted array
    for(int i=0;i<10;i++)
    {
        printf("%d ",z[i]);
    }
    return 0;
}
