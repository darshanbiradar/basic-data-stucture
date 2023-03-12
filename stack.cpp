#include<bits/stdc++.h>
using namespace std;
int top=-1;
/*
Function name : main
return : int 0 on success
date : Jan 20,2023
Author : Darshan
*/
void push(int *s)
{
    if(top== 10)
    {
        cout<<"Overflow occured"<<endl;
        return;
    }
    cout<<"Enter the item to push"<<endl;
    int i;
    cin>>i;
    s[++top]=i;
}
int pop(int *s)
{
    if(top==-1)
    {
        cout<<"Underflow occured"<<endl;
    }
    return (s[top--]);
}
void display(int *s)
{
    
    for(int i=top;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
}
int main(){
   int stk[10],choice,item;
   for(;;)
   {
    cout<<"1 for push\n2 for pop\n3  for display\n4 for exit"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1: push(stk);
            break;
        case 2: item=pop(stk);
                cout<<"item poped is "<<item <<endl; 
                break;
        case 3:display(stk);
                break;
        case 4: exit(0);
        default : cout<<"Invalid choice"<<endl;
    }
   }
return 0;
}