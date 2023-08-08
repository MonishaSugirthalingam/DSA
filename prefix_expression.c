/* AIM : Convert infix expression into prefix expression
AUTHOR : MONISHA.S 
DATE   : 05-08-2022
*/
#include <string.h>
#include <stdio.h>
//(A+B)*(C/D*F)+(G/H+I)
//definition of addition ,subraction,multiplication,division,alpha,open pracket,close pracket and exponencial function
void add(int);
void sub(int);
void multi(int);
void divi(int);
void alpha(int);
void open_pracket(int);
void close_pracket(int);
void exponencial(int);
//declaration and initialization of variables
static int count=0,top=0;
static char copy;
//to creating a structure
struct postfix
{
    char infix[50];
    char postfix[50];
    char stack[50];
}s;
int main()
{
    scanf("%s",s.infix); //read the infix expression
    for(int i=strlen(s.infix)-1;i>=0;i--)
    {
        if(s.infix[i]>=65 && s.infix[i]<=90)
        {
            alpha(i);//invoke the alpha function
        }
        if(s.infix[i]=='+')
        {
            add(i);//invoke the addition function
        }
        if(s.infix[i]=='-')
        {
            sub(i);//invoke the subraction function
        }
        if(s.infix[i]=='*')
        {
            multi(i);//invoke the multiplication function
        }
        if(s.infix[i]=='/')
        {
            divi(i);//invoke the division function
        }
        if(s.infix[i]=='(')
        {
            open_pracket(i);//invoke the open_pracket function
        }
        if(s.infix[i]==')')
        {
            close_pracket(i);//invoke the close_pracket function
        }
        if(s.infix[i]=='^')
        {
            exponencial(i);//invoke the exponential function
        }
    }
    for(int j=0;j<count;j++)//display the postfix expression
    {
        printf("%c ",s.postfix[j]);
    }
    for(int j=top-1;j>=0;j--)
    {
        printf("%c ",s.stack[j]);
    }
    return 0;
}
//definition of alpha function
void alpha(int i)
{
    s.postfix[count]=s.infix[i];
    count++;
}
//definition of open_pracket function
void open_pracket(int i)
{
    s.stack[top]=s.infix[i];
    for(i=top-1;i>=0;i--)
    {
        if(s.stack[i]==')')
        {
            break;
        }
        s.postfix[count]=s.stack[i];
        count++;
        top--;
    }
    top--;
}
//definition of close_pracket function
void close_pracket(int i)
{
    s.stack[top]=s.infix[i];
    top++;
}
//definition of addition function
void add(int i)
{
    if(top==0)
        {
            s.stack[top]=s.infix[i];
            top++;
        }
        else
        {
            if(s.stack[top-1]!='*' && s.stack[top-1]!='/'  && s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count]=copy;
                count++;
            }
        }
}
//definition of sub function
void sub(int i)
{
    if(top==0)
        {
            s.stack[top]=s.infix[i];
            top++;
        }
        else
        {
            if(s.stack[top-1]!='*' && s.stack[top-1]!='/'  && s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count]=copy;
                count++;
            }
        }
}
//definition of multi function
void multi(int i)
{
    if(top==0)
        {
            s.stack[top]=s.infix[i];
            top++;
        }
        else
        {
            if( s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count]=copy;
                count++;
            }
        }
}
//definition of divi function
void divi(int i)
{
    if(top==0)
        {
            s.stack[top]=s.infix[i];
            top++;
        }
        else
        {
            if(s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count]=copy;
                count++;
            }
        }
}
//definition of exponencial function
void exponencial(int i)
{
    s.stack[top]=s.infix[i];
    top++;
}