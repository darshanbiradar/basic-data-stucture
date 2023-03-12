#include<iostream>
using namespace std;
class hello{
    private:
    int x;
    int b;
    public:
      void set(int a)
      {
        x=a;
      }
      int get()
      {
        return x;
      }
    friend void xys(hello &x);
       
};
void xys(hello &ob)
{
    ob.x=6;
    cout<<"From friend x="<<ob.get()<<endl;
}
int main(){
    class hello X;
    X.set(7);
    cout<<X.get()<<endl;
    xys(X);
    
return 0;
}