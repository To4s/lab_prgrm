//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

class c_queue {
    int a[10],front,rear,count,size;
    public:
        c_queue() {
            cout<<"enter size: ";
            cin>>size;
            front = 0;
            count = 0;
            rear = -1;
        }
        void enqueue(int x) {
            if(count == size) {
                cout<<"queue is full\n";
                return;
            }
            rear = (rear+1)%size;
            a[rear] = x;
            count++;
        }
        void dequeue() {
            if(count == 0) {
                cout<<"queue is empty\n";
                return;
            }
            count--;
            front = (front+1)%size;
        }
        void display() {
            if(count == 0) {
                cout<<"queue is empty\n";
                return;
            }
            int j=front;
            for(int i=0;i<count;i++) {
                cout<<"a["<<i+1<<"]: "<<a[j]<<endl;
                j = (j+1)%size;
            }
        }
};

int main() {
    int choice = 0;
    c_queue q;
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