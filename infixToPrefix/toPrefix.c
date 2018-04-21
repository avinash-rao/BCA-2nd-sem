#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define max 15

int top=0;
int s[max];
void push(char);
char pop();
int precedence(char);

void main()
{
    char infix[max],prefix[max],ch,elem;
    int i,j=0;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    strrev(infix);
    push('#');
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(isalnum(ch))
            prefix[j++]=ch;
        else if(ch==')')
            push(ch);
        else if(ch=='(')
        {
            while(s[top]!=')')
                prefix[j++]=pop();
            elem=pop();
        }
        else
        {
            while(precedence(s[top])>=precedence(ch))
                prefix[j++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#')
        prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
    printf("The prefix expression is: %s",prefix);
    getch();
}

void push(char elem)
{
    ++top;
    s[top]=elem;
}

char pop()
{
    char elem;
    elem=s[top];
    --top;
    return elem;
}

int precedence(char elem)
{
    switch(elem)
    {
        case '+': 
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '^': return 3;
        case '#': 
        case ')': return 0;
        
    }
}