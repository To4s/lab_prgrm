//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#include<iostream>
using namespace std;

class Student {
    protected:
        string r_no;
    public:
        Student() {
            cout<<"enter roll number: ";
            cin>>r_no;
        }
        void display_r_no() {
            cout<<"roll number: "<<r_no<<endl;
        }
};

class Test: public Student {
    protected:
        int s1,s2;
    public:
        Test() {
            cout<<"enter sub1 marks: ";
            cin>>s1;
            cout<<"enter sub2 marks: ";
            cin>>s2;
        }
        void display_marks() {
            cout<<"Sub1 marks: "<<s1<<"\nSub2 marks: "<<s2<<endl;
        }
};

class Sport_Marks {
    protected:
        int sport_marks;
    public:
        Sport_Marks() {
            cout<<"enter sports marks: ";
            cin>>sport_marks;
        }
        void display_sport() {
            cout<<"Sports marks: "<<sport_marks<<endl;
        }
};

class Result : public Test, public Sport_Marks {
    protected:
        int total;
    public:
        Result() {
            total = s1+s2+sport_marks;
        }
        void display_total() {
            cout<<"total marks: "<<total<<endl;
        }
};

int main() {
    Result r;
    cout<<"\n\n\tDISPLAYING STUDENT DETAILS\n\n";
    r.Test::display_r_no();
    r.display_marks();
    r.display_sport();
    r.display_total();
    return 0;
}