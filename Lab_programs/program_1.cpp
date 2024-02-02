//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

class Class2;

class Class1 {
    int a;
    public:
        Class1() {
            a = 6;
        }
        friend void swap(Class1&,Class2&);
};

class Class2 {
    int b;
    public:
        Class2() {
            b = 9;
        }
        friend void swap(Class1&,Class2&);
};

void swap(Class1& c1,Class2& c2) {
    int temp;
    cout<<"Before swapping\ndata member of class 1 = "<<c1.a<<"\ndata member of class 2 = "<<c2.b<<endl;
    temp = c1.a;
    c1.a = c2.b;
    c2.b = temp;
    cout<<"Before swapping\ndata member of class 1 = "<<c1.a<<"\ndata member of class 2 = "<<c2.b<<endl;
}

int main() {
    Class1 c1;
    Class2 c2;
    swap(c1,c2);
    return 0;
}