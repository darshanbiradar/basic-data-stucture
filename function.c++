#include<bits/stdc++.h>
using namespace std;
void fnADD(int,int);
void fnADD(int,float);
void fnADD(float,int);
void fnADD(float,float);
void fnADD(double,double);
void fnADD(int,double);
void fnADD(double,int);

int main(){
    int a=9,b=6;
    float x=9.7,y=3.1;
    double p=5.654,q=45.8778;
    fnADD(a,b);
    fnADD(a,x);
    fnADD(y,b);
    fnADD(x,y);
    fnADD(a,p);
    fnADD(b,q);
    fnADD(p,q);
return 0;
}
void fnADD(int a,int b)
{
    cout<<a+b<<endl;
}
void fnADD(int a,float b)
{
    cout<<a+b<<endl;
}
void fnADD(float a,int b)
{
    cout<<a+b<<endl;
}
void fnADD(float a,float b)
{
    cout<<a+b<<endl;
}
void fnADD(double a,double b)
{
    cout<<a+b<<endl;
}
void fnADD(int a,double b) 
{
    cout<<a+b<<endl;
}
void fnADD(double a,int b)
{
    cout<<a+b<<endl;
}
