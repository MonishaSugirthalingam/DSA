#include <stdio.h>
//queue using two stacks
struct  stack 
{
    int stack1[100];
    int stack2[100];
}s;

void enqueue();
void dequeue();
void display();
void frontrear();
//void top2display();
int static top1=0,top2=0,front=0,rear=0;
int n=5;
int main()
{
    int choice;
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
            frontrear();
        }
        else if(choice==4)
        {
            display();  
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
    return 0;
}

void enqueue()
{
    if(rear==n)
    {
        printf("QUEUE OVERFLOW\n");
    }
    else
    {
        int value;
        rear++;
        printf("Enter the value : ");
        scanf("%d",&value);
        s.stack1[top1]=value;
        top1++;
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
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else
        {
        for(int i=top1-1;i>0;i--)
        {
            s.stack2[top2]=s.stack1[i];
            top2++;
        }
        top1=0;
        for(int i=top2-1;i>=0;i--)
        {
            s.stack1[top1]=s.stack2[i];
            top1++;
        }
        top2=0;
        front++;
        }
    }
}
void display()
{
    if(front==0)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
    for(int i=front-1;i<rear;i++)
    {
        printf("%d ",s.stack1[i]);
    }
    printf("\n");
    }
}
void frontrear()
{
    printf("FRONT : %d REAR : %d\n",front,rear);
}
