#include <bits/stdc++.h>
using namespace std;

class Distance {
    private:
        int feet;
        int inch;
    public:
        Distance(int f, int i) {
            feet = f;
            inch = i;
        }
        Distance operator+(Distance const &d) {
            int f = feet + d.feet;
            int i = inch + d.inch;
            return Distance(f + i / 12, i % 12);
        }

        
        Distance operator-(Distance const &d) {
            int f = feet - d.feet;
            int i = inch - d.inch;
            return Distance(f - i / 12, i % 12);
        }

        
        void display() {
            cout<<feet<<" feet "<<inch<<" inches"<<endl;
        }
};

int main() {
    Distance d1(5, 11);
    Distance d2(2, 6);

    
    Distance d3 = d1 + d2;
    cout <<"Distance 1 + Distance 2 = ";
    d3.display();

    
    Distance d4 = d1 - d2;
    cout << "Distance 1 - Distance 2 = ";
    d4.display();

    return 0;
}
