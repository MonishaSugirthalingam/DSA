#include <string.h>
#include <stdio.h>
#include <ctype.h>
//(A+B)*(C/D*F)+(G/H+I)
//definition of addition ,subraction,multiplication,division,alpha,open pracket,close pracket and exponencial function
void add(int);
void sub(int);
void multi(int);
void divi(int);
void alpha(char digit[]);
void open_pracket(int);
void close_pracket(int);
void exponencial(int);
void digits(int);
void multiplication();
void addition();
void subraction();
void division();
void expo();
//declaration and initialization of variables
static int count=0,top=0,count1=0,count2=0;
static char copy;
//to creating a structure
struct postfix
{
    char infix[50];
    char postfix[50][10];
    char stack[50];
    char result[10];
}s;
int main()
{
    int a=0,b=0,len,sum=0,power=1;
    char tempcopy[5],temp[10][10];
    scanf("%s",s.infix); //read the infix expression
    for(int i=0;i<strlen(s.infix);i++)
    {
        if(isdigit(s.infix[i])>0)
        {
            for(int j=i;j<strlen(s.infix);j++)
            {
                if(isdigit(s.infix[j])==0)
                {
                    break;
                }
                else
                {
                    temp[a][b]=s.infix[j];
                    i++;
                    b++;
                }
            }
            strcpy(tempcopy,temp[a]);
            a++;
            b=0;
            alpha(tempcopy);//invoke the alpha function
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
    for(int i=0;i<count;i++)
    {
       if(isdigit(s.postfix[i][0]))
        {
            if(strlen(s.postfix[i])>1) //if length of the str[i] id greater than one then it will be a digit
            {
            len=strlen(s.postfix[i]); //find the length of the digit
            for(int j=len-1;j>=0;j--)
            {
                sum=sum+((int)s.postfix[i][j]-48)*power; //convert the string into integer
                power=power*10;
            }
            digits(sum);//calling the digits function to evaluate the expression
            power=1;
            sum=0;
            }
            else //if the length is one then also convert the character into digit
            {
                int a=(int)s.postfix[i][0]-48;
                digits(a);
            }
        }
        if(s.postfix[i][0]=='*')
        {
            multiplication(); //to invoke the multy function
        }
        if(s.postfix[i][0]=='/')
        {
            division(); //to invoke the division function
        }
        if(s.postfix[i][0]=='+')
        {
            addition();//to invoke the add function
        }
        if(s.postfix[i][0]=='-')
        {
            subraction();//to invoke the sub function
        }
        if(s.postfix[i][0]=='^')
        {
            expo();//to invoke the expo function
        }
    }
    for(int i=top-1;i>=0;i--)
    {
      if(s.stack[i]=='*')
        {
            multiplication(); //to invoke the multy function
        }
        if(s.stack[i]=='/')
        {
            division(); //to invoke the division function
        }
        if(s.stack[i]=='+')
        {
            addition();//to invoke the add function
        }
        if(s.stack[i]=='-')
        {
            subraction();//to invoke the sub function
        }
        if(s.stack[i]=='^')
        {
            expo();//to invoke the expo function
        }
    }
    printf("Given Infix Expression %s \n\n",s.infix);
    printf("Infix to Postfix Expression\n\n");
    for(int j=0;j<count;j++)//display the postfix expression
    {
        printf("%c ",s.postfix[j]);
    }
    for(int j=top-1;j>=0;j--)
    {
        printf("%c ",s.stack[j]);
    }
    printf("Evaluation of postdfix Expression\n\n");
    for(int i=0;i<count2;i++)
    {
      printf("%d ",s.result[i]) ; 
    }
    return 0;
}
//definition of alpha function
void alpha(char *digit)
{
    strcpy(s.postfix[count],digit);
    count++;
}
//definition of open_pracket function
void open_pracket(int i)
{
    s.stack[top]=s.infix[i];
    
    top++;
}
//definition of close_pracket function
void close_pracket(int i)
{
    s.stack[top]=s.infix[i];
    for(i=top-1;i>=0;i--)
    {
        if(s.stack[i]=='(')
        {
            break;
        }
        s.postfix[count][0]=s.stack[i];
        count++;
        top--;
    }
    top--;
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
            if(s.stack[top-1]!='*' && s.stack[top-1]!='/' && s.stack[top-1]!='-' && s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count][0]=copy;
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
            if(s.stack[top-1]!='*' && s.stack[top-1]!='/' && s.stack[top-1]!='+' && s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count][0]=copy;
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
            if(s.stack[top-1]!='/' && s.stack[top-1]!='^')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count][0]=copy;
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
            if(s.stack[top-1]!='^' && s.stack[top-1]!='*')
            {
                s.stack[top]=s.infix[i];
                top++;
            }
            else
            {
                copy=s.stack[top-1];
                s.stack[top-1]=s.infix[i];
                s.postfix[count][0]=copy;
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
void digits(int num) //to store the digits in stack
{
    s.result[count2]=num;
    count2++;
}
void multiplication() //to compute the multiplication
{
    int m=s.result[count2-2]*s.result[count2-1];
    count2=count2-2;
    s.result[count2]=m;
    count2++;
}
void division()//to compute the division
{
    int d=s.result[count2-2]/s.result[count2-1];
    count2=count2-2;
    s.result[count2]=d;
    count2++;
}
void subraction()//to compute the subraction
{
    int su=s.result[count2-2]-s.result[count2-1];
    count2=count2-2;
    s.result[count2]=su;
    count2++;
}
void addition()//to compute the addition
{
    int a=s.result[count2-2]+s.result[count2-1];
    count2=count2-2;
    s.result[count2]=a;
    count2++;
}
void expo()//to compute the exponential
{
    int e=1;
    int fac=0;
    while(fac<s.result[count2-1])
    {
        e=e*s.result[count2-2];
        fac++;
    }
    count2=count2-2;
    s.result[count2]=e;
    count2++;
}