#include <stdio.h>
//circular Queue
void enqueue();
void dequeue();
void display();
void displayrearfront();
int static n=5,rear=0,front=0;
struct Queue{
    int q[100];
}s;
int main()
{
    int choice;
    printf("If you want to perform EnQueue Opeartion then PRESS-1\nIf you want to preform DeQueue Operation then PRESS-2\nIf you want to display the current array then PRESS-3\nIf you want to display the rear and front opeartion for the previous Operation then PRESS-4\nIf you want to exit these all Operations then PRESS-5\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice!=5)
    {
        if(choice==1)
        {
            enqueue();
        }
        else if(choice==2)
        {
            dequeue();
        }
        else if(choice==3)
        {
            display();
        }
        else
        {
            displayrearfront();
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
    return 0;
}
void enqueue()
{
    int value;
    if((rear==n && front==1) || rear+1==front)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("Enter the number : ");
        scanf("%d",&value);
        if(rear==n)
        {
            rear=1;
        }
        else
        {
            rear++;
        }
        s.q[rear]=value;
        if(front==0)
        {
            front=1;
        }
        
    }
}
void dequeue()
{
    if(front==0)
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        front=0;
        rear=0;
    }
    else if(front==n) 
    {
        front=1;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(rear<front)
    {
        for(int i=front;i<=n;i++)
        {
            printf("%d ",s.q[i]);
        }
        for(int i=1;i<=front-1;i++)
        {
            printf("%d ",s.q[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",s.q[i]);
        }
        printf("\n");
    }
    
}
void displayrearfront()
{
    printf("REAR : %d FRONT : %d \n",rear,front);
}