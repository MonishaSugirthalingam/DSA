/* AIM  : To Implement the Unordered List Operations INSERTING DELETING SEARCHING AND DISPLAY
AUTHOR  : MONISHA.S
DATE    : 10.08.22
*/
#include <stdio.h>
//declaration of functions
void inserting();
void deleting();
void searching();
void display();
//declaration and initialization static variable 
int static top=0;
int static n=5;
//to creating a structure and create a integer array
struct unordered_list
{
    int arr[50];
}s;
int main()
{
    int num;
    for(int i=0;i<5;i++)
    {
       scanf("%d",&s.arr[i]); //read the array elements from user
    }
    printf("If you want insert any items then PRESS-1\nIf you want delete any items then PRESS-2\nIf you want to search any items then PRESS-3\nIf you want to display the elements then PRESS-4\nIf you want to stop the compiler then PRESS-5\n");
    printf("Enter your choice\n"); //read the choice
    scanf("%d",&num);
    while(num!=5) //while loop until exit choice
    {
    if(num==1)
    {
        inserting();//inserting function calling
    }
    if(num==2)
    {
        deleting();//deleting function calling
    }
    if(num==3)
    {
        searching();//searching function calling
    }
    if(num==4)
    {
        display();//display function calling
    }
    printf("Enter your choice\n");
    scanf("%d",&num);
    }
}
//definition of inserting function
void inserting()
{
    int index,value,oldvalue;
    printf("Enter the index position and value :");
    scanf("%d%d",&index,&value); //read the position and value
    if(index>=n)
    {
       printf("STACK IS FULL"); 
    }
    else{
        top++;
       for(int i=index;i<=(5+top);i++)
       {
        oldvalue=s.arr[i];
        s.arr[i]=value;
        value=oldvalue;
       } 
    }
    
}
void deleting() //function definition
{
    int index;
    if((top+n)==0)
    {
        printf("STACK UNDERFLOW\n");
    }
    else{
    top--;
    printf("Enter the index of the deleting number :");
    scanf("%d",&index); // read position from user
    for(int i=index;i<top+n;i++)
    {
        s.arr[i]=s.arr[i+1];
    }
    }
}
//definition of searching function
void searching()
{
    int value,count=0;
     if((top+n)==0)
    {
        printf("STACK UNDERFLOW\n");
    }
    else{
        printf("Enter the searching element :");
        scanf("%d",&value);//read a value from user
        for(int i=0;i<top+n;i++)
        {
            if(s.arr[i]==value)
            {
                count++;
            }
        }
        if(count>0)
        {
            printf("Yes, Number %d is there !!\n",value);//if the value in the stack then print yes
        }
        else{
            printf("No..Number %d is not in the array\n",value);//else print no
        }
    }
}
//definition of display function
//display all elements in stack
void display()
{
    if((top+n)==0)
    {
        printf("STACK IS EMPTY\n");
    }
    else{
    for(int i=(top+n)-1;i>=0;i--){
        printf("%d\t",s.arr[i]);
    }
    printf("\n");
    }
}
