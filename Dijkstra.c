#include <stdio.h>
int k[10],dv[10],pv[10],n=5;
int graph[5][5]={{0,5,10,0,0},
                 {0,0,0,2,0},
                 {0,3,0,0,4},
                 {0,0,1,0,8},
                 {0,7,0,2,0},
                };
//int graph[50][50];
int find_source_vertex()
{
    int min,flag=0;
    for(int i=1;i<n;i++)
    {
        if(k[i]==0)
        {
            min=dv[i];//assume min
            break;
        }
    }
    for(int i=2;i<n;i++)
    {
        if(min>dv[i] && k[i]==0)
        {
            min=dv[i];//min
        }
    }
    for(int i=1;i<n;i++)
    {
        if(k[i]==0 && min==dv[i])
        {
            flag=1;
            return i;
        }
    }
    if(flag==0)
    {
       for(int i=1;i<n;i++)
        {
        if(k[i]==0)
        {
            return i;
        }
        } 
    }
    
}
void dijkstra(int s)
{
    int vertex=s;
    k[s]=1;
   
    for(int j=0;j<n;j++)
    {
        if(graph[vertex][j]!=0)
        {
            int sum=dv[s]+graph[vertex][j];
            printf("sum %d dv[s] %d\n",sum,dv[j]);
            if(sum<dv[j])
            {
                dv[j]=sum;
                pv[j]=vertex;
            }
            
        }
    }
}
int main()
{
    /*int num,value,advalue;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the node value : ");
        scanf("%d",&value);
        printf("Enter the number of adjency %d: ",value);
        scanf("%d",&num);
        for(int j=0;j<num;j++)
        {
            printf("Enter the value : ");
            scanf("%d",&value);
            printf("Enter the adjency value : ");
            scanf("%d",&advalue);
            for(int k=0;k<n;k++)
            {
                if(value-1==k)
                {
                    graph[i][k]=advalue;
                }
                if(value-1!=k && graph[i][k]<=0)
                {
                    graph[i][k]=0;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }*/
    for(int i=0;i<n;i++)
    {
        k[i]=0;
        dv[i]=10000;
        pv[0]=0;
    }
    int vertex=0;
    k[0]=1;
    dv[0]=0;
    pv[0]=-1;
    int source=0;
    for(int j=0;j<n;j++)
    {
        if(graph[vertex][j]!=0)
        {
            dv[j]=graph[vertex][j];
            pv[j]=vertex;
        }
    }
    printf("Table Formet Of Shortest Path Algorithm\n\n");
    printf("source vertex : %d\n",source);
    source=find_source_vertex();
    for(int i=0;i<n;i++)
    {
        printf("k=%d\tdv=%d\tpv=%d\n",k[i],dv[i],pv[i]);
            
    }
    for(int i=1;i<n;i++)
    {
        
        source=find_source_vertex();
        printf("source vertex : %d\n",source);
        dijkstra(source);
        for(int i=0;i<n;i++)
        {
            printf("k=%d\tdv=%d\tpv=%d\n",k[i],dv[i],pv[i]);
            
        }
    }
    printf("\nGraph Formet Of Shortest Path Algorithm\n");
    for(int i=1;i<n;i++)
    {
        printf("V%d To V%d ==> %d\n",pv[i]+1,i+1,graph[pv[i]][i]);
    }
    return 0;
}
