#include<bits/stdc++.h>
using namespace std;
class shape{
    protected:
     int width,height;
     public:
     shape()
     {
        width=height=0;
     }
     shape(int x,int y)
     {
        width=y;
        height=x;
     }
     virtual void area(){}
};
class rectangle:public shape{
    int r;
    public:
    rectangle()
    {
        r=0;
    }
    rectangle(int a,int b):shape(a,b)
    {

    }
    void area(){
        r=width*height;
        cout<<"area of recatngle is "<<r<<endl;
    }
};
class triangle:public shape{
float t;
public:
triangle()
{
    t-0;
}
triangle(int a,int b):shape(a,b){}
void area()
{
    t=0.5*width*height;
    cout<<"area of triangle :"<<t<<endl;
}
};
void calculate(shape *s)
{
    s->area();
}
int main(){
    rectangle r(5,6);
    calculate(&r);
    triangle T(100,200);
    calculate(&T);
return 0;
}