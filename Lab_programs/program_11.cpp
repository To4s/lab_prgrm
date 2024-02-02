//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#define size 10
using namespace std;

class queue {
    int a[10],front,rear;
    public:
        queue() {
            front = 0;
            rear = -1;
        }
        void enqueue(int data) {
            if(rear == size-1) {
                cout<<"Queue is full\n";
                return;
            }
            a[++rear] = data;
        }
        void dequeue() {
            if(rear<front) {
                cout<<"Queue is empty\n";
                return;
            }
            front++;
        }
        void display() {
            if(rear<front) {
                cout<<"Queue is empty\n";
                return;
            }
            for(int i=front;i<=rear;i++) {
                cout<<"a["<<i+1<<"]: "<<a[i]<<endl;
            }
        }
};

int main() {
    int choice = 0;
    queue q;
    while(choice!=4) {
        cout<<"\n\n1->enqueue\n2->dequeue\n3->display\n4->exit\n\nenter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                int x;
                cout<<"enter number to be added to queue: ";
                cin>>x;
                q.enqueue(x);
                break;
            case 2:
                cout<<"dequeueing....\n";
                q.dequeue();
            case 3:
                cout<<"\n\nDISPLAYING CONTENTS OF QUEUE\n\n";
                q.display();
        }
    }
    return 0;
}