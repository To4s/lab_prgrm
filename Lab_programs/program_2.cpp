//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

class comp {
    int x,y;
    public:
        comp() {
            cout<<"inside default constructor\nEnter real part: ";
            cin>>x;
            cout<<"Enter imaginary part: ";
            cin>>y;
        }
        comp(int a,int b) {
            cout<<"inside parameterized constructor\n";
            x = a;
            y = b;
        }
        void display() {
            cout<<"\n\tDISPLAYING COMPLEX NUMBER\n\nReal part: "<<x<<"\nImaginary part: "<<y<<"\n\n";
        }
        comp operator+(comp& a) {
            comp s;
            s.x = x+a.x;
            s.y = y+a.y;
            return s;
        }
};

int main() {
    comp a;
    comp b(3,5);
    comp s = a+b;
    a.display();
    b.display();
    s.display();
    return 0;
}