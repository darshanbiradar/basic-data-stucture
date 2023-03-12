#include<bits/stdc++.h>
using namespace std;
class student{
    private:
    char *name;
    int roll_no;
    public:
      student(char *p,int r)
      {
        strcpy(name,p);
        roll_no=r;
      }
       
      void display()
      {
        cout<<"The name of the student is "<<name<<endl;
        cout<<"roll no is "<<roll_no<<endl;
      }
      
};

int main(){
    class student s("darshan",57);
 
    s.display();
   
return 0;
}