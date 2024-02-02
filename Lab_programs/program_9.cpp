//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

class stack {
    int n,top;
    int a[10];
    public:
        stack() {
            cout<<"Enter size of stack: ";
            cin>>n;
            top = -1;
        }
        void push(int x) {
            if(top == n-1) {
                cout<<"stack is full\n";
            }
            else {
                a[++top] = x;
            }
        }
        void pop() {
            if(top == -1) {
                cout<<"stack is empty\n";
                return;
            }
            top--;
        }
        void display() {
            if(top == -1) {
                cout<<"stack is empty\n";
            }
            else {
                cout<<"\n\n\tELEMENTS OF STACK\n\n";
                for(int i=0;i<=top;i++) {
                    cout<<"a["<<i+1<<"]: "<<a[i]<<endl;
                }
            }
        }
};



int main() {
    stack s;
    int choice = 0;
    while(choice != 4) {
        cout<<"\n\n1->Push\n2->Pop\n3->Display\n4->Exit\nEnter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                    int x;
                    cout<<"enter element to be pushed into stack: ";
                    cin>>x;
                    s.push(x);
                    break;
            case 2:
                    cout<<"popping element....\n";
                    s.pop();
                    break;
            case 3:
                    cout<<"displaying elements of stack...\n";
                    s.display();
                    break;
        }
    }
    return 0;
}