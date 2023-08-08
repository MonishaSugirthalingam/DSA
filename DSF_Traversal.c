#include <stdio.h>

int output[100];
int stack[100];
int node[100]={0,1,2,3,4};

int graph [15][15] = {
        {0,1,0,0,1},
        {1,0,1,1,1},
        {0,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
        
    };
int stackcount=0;
int outcount=0;
void outputfun(int);
void stackfun(int);
int main()
{
    int n,num,value;
    /*printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the node value : ");
        scanf("%d",&value);
        s.node[i]=value;
        printf("Enter the number of adjency %d: ",s.node[i]);
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            printf("Enter the value : ");
            scanf("%d",&value);
            for(int k=0;k<n;k++)
            {
                if(value-1==k)
                {
                    s.graph[i][k]=1;
                }
                else if(value-1!=k && s.graph[i][k]==1)
                {
                    s.graph[i][k]=1;
                }
                else
                {
                    s.graph[i][k]=0;
                }
            }
        }
    }*/
    stack[0]=node[0];
    stackcount=1;
    //printf("stack %d\n",stack[0]);
    outputfun(stack[0]);
    
    for(int i=0;i<outcount;i++)
    {
        printf("%d ",output[outcount]);
    }
    return 0;
}
int check1(int a)
{
    int flag=0;
    if(stackcount==0)
    {
        return 0;
    }
    else
    {
        printf("stack elements : ");
        for(int i=0;i<stackcount;i++)
        {
            printf("%d ",stack[i]);
            if(stack[i]==a)
            {
                flag=1;
                return 1;
            }
        }
        if(flag==0)
        {
            return 0;
        }
        printf("\n");
    }
}
int check2(int a)
{
    int flag=0;
    if(outcount-1==0)
    {
        return 0;
    }
    else
    {
        printf("output elements : ");
        for(int i=0;i<outcount;i++)
        {
            printf("%d ",output[i]);
            if(output[i]==a)
            {
                flag=1;
                return 1;
            }
        }
        if(flag==0)
        {
            return 0;
        }
        printf("\n");
    }
}
void stackfun(int num)
{
    
    for(int j=0;j<5;j++)
    {
        if(graph[num][j]==1)
        {
            printf("1's %d\n",j);
            int re1=check1(j);
            int re2=check2(j);
            printf("re %d %d\n",re1,re2);
            if(re1==0 && re2==0)
            {
                stack[stackcount]=j;
                printf("stack %d \n",stack[stackcount]);
                stackcount++;
            }
        }
        
    }
    printf("call %d \n",stack[stackcount-1]);
    outputfun(stack[stackcount-1]);
}

void outputfun(int num)
{
    output[outcount]=num;
    printf("In output elements : ");
    for(int i=0;i<outcount;i++)
    {
        printf("%d ",output[i]);
    }
    printf("\n");
    outcount++;
    stackcount--;
    if(outcount<=5)
    {
        stackfun(output[outcount-1]);
    }
}
