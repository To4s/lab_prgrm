//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#include<math.h>
using namespace std;

class geofig {
    protected:
        float area;
    public:
        virtual void display() = 0;
};

class rect : public geofig {
    private:
        float l,b;
    public:
        rect() {
            cout<<"\tObject of class rectangle created\n\n";
            cout<<"enter length: ";
            cin>>l;
            cout<<"enter breadth: ";
            cin>>b;
        }
        void display() {
            area = l*b;
            cout<<"\n\n\tDISPLAYING DETAILS OF OBJECT REPRESENTING A RECTANGLE\n\nSides of rectangle:\n";
            cout<<"length: "<<l;
            cout<<"\nbreadth: "<<b<<endl;
            cout<<"\nArea of rectangle: "<<area<<"\n\n";
        }
};

class tri : public geofig {
    private:
        float a[3],s;
    public:
        tri() {
            s = 0;
            cout<<"\tObject of class triangle created\n\n";
            for(int i=0;i<3;i++) {
                cout<<"enter length of side "<<i+1<<": ";
                cin>>a[i];
                s += a[i]; 
            }
            s /= 2;
        }
        void display() {
            area = sqrt(s*(s-a[0])*(s-a[1])*(s-a[2]));
            cout<<"\n\n\tDISPLAYING DETAILS OF OBJECT REPRESENTING A TRIANGLE\n\nSides of triangle:\n";
            for(int i=0;i<3;i++) {
                cout<<"length of side "<<i+1<<" of given triangle: "<<a[i]<<endl;
            }
            cout<<"\nArea of triangle: "<<area<<"\n\n";
        }
};

int main() {
    rect r;
    geofig* point = &r;
    point->display();
    tri t;
    point = &t;
    point->display();
    return 0;
}