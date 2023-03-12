#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int q[30],top;
}stack;
void push(stack *s,char ch)
{
    s->q[++(s->top)]=ch;
}
char pop(stack *s)
{
    return s->q[(s->top)--];
}
int precdence(char op)
{
    switch (op)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '/':
    case '*':
        return 3;
    }
}
int main()
{
    stack s;
    s.top=-1;
    int i=0,j=0;
    char postfix[30],infix[30],ch,c;
    printf("Enter a valid infix expression :");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i++];
        if(ch=='(')
            push(&s,ch);
        else if(isalpha(ch) || isdigit(ch))
         postfix[j++]=ch;
        else if(ch==')')
        {
            while((c=pop(&s))!='(')
                postfix[j++]=c;
        }
        else
        {
            while ((precdence(ch)<=precdence(s.q[s.top]))&& s.top!=-1)
                postfix[j++]=pop(&s);
            push(&s,ch);
        }
    }
    while(s.top!=-1)
        postfix[j++]=pop(&s);
    postfix[j]='\0';
    printf("the evaluvated postfix is %s\n",postfix);
return 0;
}