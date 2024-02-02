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
        friend void search(stack&,int);
};

void search(stack& s,int key) {
    if(s.top == -1) {
        cout<<"stack is empty\n";
        return;
    }
    int i;
    for(i=0;i<=s.top;i++) {
        if(s.a[i] == key) {
            cout<<"Key data found at index "<<i+1<<endl;
            return;
        }
    }
    cout<<"Key data not found\n";
}

int main() {
    stack s;
    int choice = 0;
    while(choice != 5) {
        cout<<"\n\n1->Push\n2->Pop\n3->Display\n4->Search\n5->Exit\nEnter choice: ";
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
            case 4:
                    int key;
                    cout<<"enter key data: ";
                    cin>>key;
                    search(s,key);
        }
    }
    return 0;
}