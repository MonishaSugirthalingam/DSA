#include <stdio.h>

int main()
{
    int a[10]={2,9,7,4,1,8,4};
    int max=a[0];
    for(int i=1;i<7;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    int size=max+1;
    int b[max+1];
    for(int i=0;i<size;i++)
    {
      b[i]=0;  
    }
    for(int i=0;i<7;i++)
    {
        b[a[i]]=b[a[i]]+1;
    }
    
    for(int i=1;i<size;i++)
    {
        b[i]=b[i-1]+b[i];
    }
    for(int i=7-1;i>=0;i--)
    {
        int position=a[i];
    }
    for(int i=0;i<7;i++)
   {
      printf("%d ",a[i]);
    }
}