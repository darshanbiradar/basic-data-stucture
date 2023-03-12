#include<bits/stdc++.h>
using namespace std;
class STACK{
    private:
    int stk[10];
    int top=-1;
    public:
     void push(int item)
     {
       if(top==9)
       {
        cout<<"Overflow occured"<<endl;
        return ;
       }
        stk[++top]=item;
     }
     void pop()
     {
        if(top == -1)
        {
            cout<<"Underflow occured"<<endl;
            return;
        }
        cout<<"Element poped"<<stk[top--]<<endl;
     }
     void display()
     {
        for(int i=top;i>=0;i--)
          cout<<stk[i]<<endl;

     }
};
int main(){
    class STACK s[10];
    s->push(5);
    s->push(6);
    s->push(8);
    s->push(5);
    s->push(6);
    
    s->display();
    s->pop();
    s->display();
    
return 0;
}