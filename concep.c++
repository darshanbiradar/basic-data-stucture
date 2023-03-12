#include<bits/stdc++.h>
using namespace std;
class student{
protected: 
 char name[20];
 int reg,age;
 public:
   student();
   ~student();
   void getdata();
   
};
student::student()
{

}
student::~student()
{

}
void student::getdata()
{
    cout<<"Enter the name"<<endl;
    cin>>name;
    cout<<"Enter the age "<<endl;
    cin>>age;
    cout<<"Enter the reg"<<endl;
    cin>>reg;
}
class ugstudent:public student{
    private:
    int sem,fee,sti;
    public:
    ugstudent();
    ~ugstudent();
    void getugdata();
    void givesem();
};
ugstudent:: ugstudent()
{

}
ugstudent::~ugstudent()
{

}
void ugstudent::getugdata()
{
    getdata();
    cout<<"Semester";
    cin>>sem;
    cout<<"fee";
    cin>>fee;
    cout<<"stipend";
    cin>>sti;
}
int main(){
    ugstudent ug1;
    ug1.getugdata();

return 0;
}