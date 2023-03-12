#include<bits/stdc++.h>
using namespace std;

void area(float , float , float );
void area(float );
void area(float ,float );


void area(float a, float b, float c)
{
    float s=(a+b+c)/2;
    float area1=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"area of triangle is"<<area1<<endl;
}
void area(float r)
{
    float area1=3.142*r*r;
    cout<<"The area of circle is "<<area1<<endl;   
}
void area(float a,float b)
{
    cout<<"area of rectangle is "<<a*b<<endl;
}
/*
Function name : main
return : int 0 on success
date : Jan 20,2023
Author : Darshan
*/
int main(){
    float a=8.9,b=9.9,c=5;
    area(a,b,c);
    area(a);
    area(a,b);
    
return 0;
}