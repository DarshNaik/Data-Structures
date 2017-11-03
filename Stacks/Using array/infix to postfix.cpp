/* NEED HELP PROGRAM NOT GIVING CORRECT POSTFIX EXPRESSION */


#include <iostream>
#include <ctype.h>
using namespace std;
char stack[50];
int top=-1;

void push(char el)
{
    stack[++top]=el;
}
char pop()
{
    return stack[--top];
}



int priority(char e)
{
    switch(e)
    {
        case '=' : return 0;
        
        case '(' : return 1;
        
        case '+' : 
        case '-' : return 2;
        
        case '*' :
        case '/' : return 3;
    }
}

int main()
{
    int i=0,k=0;
    char infix[50],ch,p[50],el;
    cin>>infix;
    push('=');
    while((ch=infix[i++])!= '\0')
    {
        if(ch=='(') push(ch);
        else{
            if(isalnum(ch)) p[k++]=ch;
            else
            {
                if(ch==')')
                {
                    while(stack[top]!='(')
                        p[k++]=pop();
                    el=pop();
                }
                else
                {
                    while(priority(stack[top])>=priority(ch))
                        p[k++]=pop();
                    push(ch);
                }
            }
        }
    }
    while(stack[top]!='=')
        p[k++]=pop();
    p[k]='\0';
    cout<<"\n"<<p;
    return 0;
}
