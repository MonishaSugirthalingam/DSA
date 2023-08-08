/* AIM : To Implement the ORDERED LIST OPERATIONS - DELETING SEARCHING INSERTING AND DISPLAY
AUTHOR : MONISHA.S
DATE   : 10.08.22
*/
//declaration of each functions
#include <stdio.h>
void inserting();
void deleting();
void searching();
void display();
//declaration and initialization of top and MAXSIZE of array
int static top=0;
int static n=15;
//To creating a structure
struct ordered_list
{
    int arr[50];
}s;
int main()
{
    int num;
    printf("If you want insert any items then PRESS-1\nIf you want delete any items then PRESS-2\nIf you want to search any items then PRESS-3\nIf you want to display the elements then PRESS-4\nIf you want to stop the compiler then PRESS-5\n");
    printf("Enter your choice\n"); //read the choice
    scanf("%d",&num);
    while(num!=5) // while loop until exit condition
    {
    if(num==1)
    {
        inserting();// invoke the inserting function
    }
    if(num==2)
    {
        deleting();// invoke the deleting function
    }
    if(num==3)
    {
        searching();// invoke the searching function
    }
    if(num==4)
    {
        display();// invoke the display function
    }
    printf("Enter your choice\n");
    scanf("%d",&num);
    }
}
//definition of inserting function
void inserting()
{
    int index,value,oldvalue;
    printf("Enter the value :"); //read the value
    scanf("%d",&value);
    if(top>=n)
    {
       printf("STACK IS FULL"); //condition for stack overflow
    }
    else{
       if(top==0)
       {
           s.arr[top]=value;
           top++;
       }
       if(top>0 && s.arr[top-1]<value)
       {
           s.arr[top]=value;
           top++;
       }
       if(top>0 && s.arr[top-1]>value) //insert the value with respect to the increasing order
       {
           int max=0;
           int i=top-1;
           while(max!=1 && i>=0)
            {
               if(s.arr[i]<value) //search each elements and fix the max++ when the input greater then the other element in stack
               {
                   max++;
               }
               i--;
            }
            if(i<0)
            {
                index=0;//if  index less then the zero means all elements less then the given value,so insert given value in first position
            }
            else
            {
                index=i+2;//else position equal to index one
            }
            for(int i=index;i<=top;i++) //assign the array in lenear order
            {
                oldvalue=s.arr[i];
                s.arr[i]=value;
                value=oldvalue;
            } 
            top++;
       }
       
    }
    
}
//deleting function definition
void deleting()
{
    int index;
    if((top+n)==0)
    {
        printf("STACK UNDERFLOW\n");// condition for stack underflow
    }
    else{ //else compute the deleting operation
    top--;
    printf("Enter the index of the deleting number :");
    scanf("%d",&index); // read the index position of deleting element
    for(int i=index;i<top+n;i++)
    {
        s.arr[i]=s.arr[i+1];
    }
    }
}
//searching function definition
void searching()
{
    int value,count=0;
     if((top+n)==0)
    {
        printf("STACK UNDERFLOW\n");//condition for stack underflow
    }
    else{
        printf("Enter the searching element :"); //read the searching element
        scanf("%d",&value);
        for(int i=0;i<top+n;i++)
        {
            if(s.arr[i]==value)
            {
                count++;
            }
        }
        if(count>0)
        {
            printf("Yes, Number %d is there !!\n",value); //if the given input is there in stack then print this statement
        }
        else{
            printf("No..Number %d is not in the array\n",value);//else print this
        }
    }
}
//display fnction definition
void display()
{
    if(top==0)
    {
        printf("STACK IS EMPTY\n"); // condition for stack underflow
    }
    else{
    for(int i=top-1;i>=0;i--){ //display the each and every element in stack
        printf("%d\t",s.arr[i]);
    }
    printf("\n");
    }
}
