/* AIM : Evaluate the postfix expression
AUTHOR : MONISHA.S
DATE   : 10.08.22
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//declaration of each function
void digits(int);
void multy();
void division();
void add();
void sub();
void expo();
//to creating structure
struct postfix_evaluation
{
    int stack[10];
}s;
//to declaration and definition of count2 variable
int static count2=0;
int main()
{
    char string[100],str[50][50],temp[20];
    int i=0,start=0,end=-1,a=0,b=0,count=0,len;
    fgets(temp,sizeof temp,stdin); //read the input
    len=strlen(temp); // find the length of the postfix expression
    temp[len-1]='\0'; //remove the newline from the input
    strcat(string,temp);//copy the input from temp variable and store it in string variable
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]==' ')
        {
            start=end+1;//if condition is satisfied then start is index of space
            end=i;//end is i
            for(i=start;i<end;i++)
            {
                str[a][b]=string[i]; //store the characters in two d array
                b++;
            }
            a++;
            b=0;
            count++;
        }
        
    }
    for(i=end+1;i<strlen(string);i++) //loop for last character (or) string [operator or oparant]
    {
        str[a][b]=string[i];
        b++;
    }
    count++;
    int sum=0;
    int power=1;
    for(i=0;i<count;i++)
    {
        if(isdigit(str[i][0]))
        {
            if(strlen(str[i])>1) //if length of the str[i] id greater than one then it will be a digit
            {
            len=strlen(str[i]); //find the length of the digit
            for(int j=len-1;j>=0;j--)
            {
                sum=sum+((int)str[i][j]-48)*power; //convert the string into integer
                power=power*10;
            }
            digits(sum);//calling the digits function to evaluate the expression
            power=1;
            sum=0;
            }
            else //if the length is one then also convert the character into digit
            {
                int a=(int)str[i][0]-48;
                digits(a);
            }
        
        }
        if(str[i][0]=='*')
        {
            multy(); //to invoke the multy function
        }
        if(str[i][0]=='/')
        {
            division(); //to invoke the division function
        }
        if(str[i][0]=='+')
        {
            add();//to invoke the add function
        }
        if(str[i][0]=='-')
        {
            sub();//to invoke the sub function
        }
        if(str[i][0]=='^')
        {
            expo();//to invoke the expo function
        }
    }
    for(int j=0;j<count2;j++) //display the answer
    {
        printf("%d ",s.stack[j]);
    }
    return 0;
}
void digits(int num) //to store the digits in stack
{
    s.stack[count2]=num;
    count2++;
}
void multy() //to compute the multiplication
{
    int m=s.stack[count2-2]*s.stack[count2-1];
    count2=count2-2;
    s.stack[count2]=m;
    count2++;
}
void division()//to compute the division
{
    int d=s.stack[count2-2]/s.stack[count2-1];
    count2=count2-2;
    s.stack[count2]=d;
    count2++;
}
void sub()//to compute the subraction
{
    int su=s.stack[count2-2]-s.stack[count2-1];
    count2=count2-2;
    s.stack[count2]=su;
    count2++;
}
void add()//to compute the addition
{
    int a=s.stack[count2-2]+s.stack[count2-1];
    count2=count2-2;
    s.stack[count2]=a;
    count2++;
}
void expo()//to compute the exponential
{
    int e=1;
    int fac=0;
    while(fac<s.stack[count2-1])
    {
        e=e*s.stack[count2-2];
        fac++;
    }
    count2=count2-2;
    s.stack[count2]=e;
    count2++;
}