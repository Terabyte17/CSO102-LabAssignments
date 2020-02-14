#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char top_element();
void push(char ch);
char pop();
int precedence(char ch);
int top=-1;
int k=0;
char elem;
char popped_elem;
char stack_elem;
int prec1;
int prec2;
char element;
char infix[100],postfix[100],stack[100];
        
int main()
{
    
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++)
    {   popped_elem=0;
        top=-1;
        k=0;
        cin.getline(infix,100);
        for(int j=0;infix[j]!='\0';j++)
        {
            if(infix[j]!='(' && infix[j]!=')' && infix[j]!='+' && infix[j]!='-' && infix[j]!='*' && infix[j]!='/')
            {
                postfix[k++]=infix[j];
            }
            else if(infix[j]=='(')
            {
                stack_elem=infix[j];
                push(stack_elem);
            }
            else if(infix[j]==')')
            {
                
                while((popped_elem=pop())!='(')
                {
                    postfix[k++]=popped_elem;
                }
            }
            else
            {
                element=infix[j];
                prec1=precedence(element);
                elem=top_element();
                prec2=precedence(elem);
                if(prec1>prec2)
                {
                    push(element);
                }
                else
                {
                    while(prec2>=prec1)
                    {
                        if(elem=='#')
                        break;
                        else
                        {
                            popped_elem=pop();
                            postfix[k++]=popped_elem;
                            elem=top_element();
                            prec2=precedence(elem);
                        }
                    }
                    push(elem);
                }
            }
            
        }
        popped_elem=pop();
        while(popped_elem!='#')
        {
            postfix[k++]=popped_elem;
            popped_elem=pop();
        }
        postfix[k]='\0';
        cout<<postfix<<endl;
        
    }

    return 0;
}
char top_element()
{
    char ch;
    if(top!=-1)
    {
        return stack[top];
    }
    else 
    return '#';
}
int precedence(char ch)
{
    if(ch=='/' || ch=='*')
    return 2;
    else if(ch=='+' || ch=='-')
    return 1;
    else
    return 0;
}
void push(char ch)
{
    if(top!=99)
    {
        top++;
        stack[top]=ch;
    }
   
}
char pop()
{
    char ch;
    if(top!=-1)
    {
        ch=stack[top];
        top--;
        return ch;
    }
    else 
    return '#';
}
	