//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

class test {
    int a,b;
    public:
        test() {
            a=3;
            b=4;
        }
        void display() {
            cout<<"\n\tDISPLAYING CONTENTS OF INSTANCE OF TEST CLASS\na = "<<a<<"\nb = "<<b<<"\n\n";
        }
        test operator-() {
            test t;
            t.a = -a;
            t.b = -b;
            return t;
        }
};

int main() {
    test t1;
    t1.display();
    test t2 = -t1;
    t2.display();
    return 0;
}