//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#include<string>
using namespace std;

class Student {
    protected:
        string r_no;
    public:
        Student() {
            cout<<"roll no: ";
            cin>>r_no;
        }
        void display_rno() {
            cout<<"Roll number: "<<r_no<<endl;
        }
};

class Test : public Student{
    protected:
        int s1,s2;
    public:
        Test() {
            cout<<"sub1 marks: ";
            cin>>s1;
            cout<<"sub2 marks: ";
            cin>>s2;
        }
        void display_marks() {
            cout<<"sub1 marks: "<<s1;
            cout<<"\nsub2 marks: "<<s2<<endl;
        }
};

class Result: public Test {
    int total;
    public:
        Result() {
            total = s1+s2;
        }
        void display_total() {
            cout<<"total marks: "<<total<<endl;
        }
};

int main() {
    Result r;
    cout<<"\n\tSTUDENT DETAILS\n\n";
    r.display_rno();
    r.display_marks();
    r.display_total();
    return 0;
}