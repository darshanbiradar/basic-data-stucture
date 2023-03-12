#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int stk[30],top;
}stack;
void push(stack *s,int ele)
{
    s->stk[++(s->top)]=ele;
}
int pop(stack *s)
{
    return s->stk[(s->top)--];
}
int eval(int op1,char op,int op2)
{
    switch(op)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '/':
            return op1/op2;
        case '*':
            return op1*op2;
    }
}
int main()
{
    stack s;
    s.top=-1;
    char ch,op,postfix[30];
    int i=0,op1,op2;
    printf("Enter the valid posfix expression :");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        ch=postfix[i++];
        if(isdigit(ch))
            push(&s,ch-'0');
        else{
            op2=pop(&s);
            op1=pop(&s);
            push(&s,eval(op1,ch,op2));
        }
    }
    printf("%d \n",pop(&s));
    
return 0;
}