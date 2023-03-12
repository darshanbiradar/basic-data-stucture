#include<bits/stdc++.h>
using namespace std;

class distance 
{
    private: int feet;
            int inch;
    public: 
       
         distance(int f,int i)
         {
            feet =f;
            inch =i;
         }
         distance()
         {
            feet=0;
            inch=0;
         }
        distance operator+(distance const &d1)
        {
            int f= feet + d1.feet;
            int i= inch + d1.inch;
            return distance(f+i/12 , i%12);
        }
       
        distance operator-(distance  const &d1)
        {
            int i= inch - d1.inch;
            int f=  feet - d1.feet;
            return distance(f-i/12,i%12);
        }
        void display()
        {
            cout<<"feet"<<feet<<"inches"<<inch<<endl;
        }
       
       
};
int main(){
   class distance d1(3,6);
    class distance d2(6,7);
    class distance d3;
       d3= d1 + d2;
    class distance d4;
    d4= d1 - d2;
    d3.display();
    d4.display();
return 0;
}
//write a c++ program which contains a class called distance with inch and feet then do the following operations initilization of 2 objects then addition of 2 distances 3 sub of 2 distance 4 is display?  
//c code to add 2 numbers? 

