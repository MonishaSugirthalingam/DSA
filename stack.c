/* AIM : Implement the STACK,PUSH POP PEAK AND DISPLAY OPERATIONS
AUTHOR : MONISHA.S
DATE   : 10.08.22
*/
#include <stdio.h>
//declaration of functions
void push();
void pop();
void display();
void peek();
//initialization and declaration of static variable
int static top=0;
int static n=5;
struct stacking
{
    int stac[5];
}arr;
int main()
{
    int num=0;
    
    printf("If you want push any items then PRESS-1\nIf you want pop any items then PRESS-2\nIf you want to display the array items then PRESS-3\nIf you want to know peak element then PRESS 4\nIf you want to stop the compiler then PRESS-5\n");
    printf("Enter your choice\n");
    scanf("%d",&num);//read a choice from users
    while(num!=5)
    {
    if(num==1)
    {
        push();//calling function push
    }
    if(num==2)
    {
        pop();//calling fuction pop
    }
    if(num==3)
    {
        display();//calling display function
    }
    if(num==4)
    {
        peek();//calling peak function
    }
    printf("Enter your choice\n");
    scanf("%d",&num);//read a choice from user until they press exit
    }
    return 0;
}
void push()//definition of push function
{
    int a,ele,cal=0;
    printf("how many elements do you want to push? ");
    scanf("%d",&ele);
    cal=top+ele;
    if(cal<=5)
    {
    printf("Enter the elements : ");
    for(int i=0;i<ele;i++)
    {
        scanf("%d",&arr.stac[top]);
        top++;
    }
    }
    else
    {
        printf("STACK IS FULL\n");
        if(cal>5 && top<5)
        {
        printf("As of now,You can only push %d elements\n",n-top);
        printf("So,ReEnter the number of elements\n");
        }
    }
}
void pop()//definition of pop function
{
    if(top==0)
    {
        printf("STACK IS EMPTY\n");
    }
    else{
    top=top-1;
    }
}
void display()//definition of display function
{
    if(top==0)
    {
        printf("STACK IS EMPTY\n");
    }
    else{
    for(int i=top-1;i>=0;i--){
        printf("%d\t",arr.stac[i]);
    }
    printf("\n");
    }
}
void peek()//definition of peak function
{
    printf("Peek element is %d \n",arr.stac[top-1]);
}
