//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

class list {
    node* head;
    public:
        list() {
            head = NULL;
        }
        void insert_front(int d) {
            node *newnode = new node;
            newnode->data = d;
            newnode->link = head;
            head = newnode;
        }
        void insert_rear(int d) {
            node *newnode = new node;
            node *cur = head;
            newnode->data = d;
            newnode->link = NULL;
            if(head == NULL) {
                head = newnode;
                return;
            }
            while(cur->link!=NULL) {
                cur=cur->link;
            }
            cur->link=newnode;
        }

        void del_front() {
            if(head == NULL) {
                cout<<"empty list\n";
                return;
            }
            head = head->link;
        }
        void del_rear() {
            node *prev = new node;
            node *cur = new node;
            if(head==NULL) {
                cout<<"empty list\n";
                return;
            }
            cur = head;
            if(cur->link==NULL) {
                head = NULL;
                return;
            }
            while(cur->link!=NULL) {
                prev=cur;
                cur=cur->link;
            }
            prev->link = NULL;
            delete cur;
        }
        void search_n_del(int x) {
            node *prev = new node;
            node *check = head;
            while(check->data != x) {
                prev = check;
                check = check->link;
            }
            if(check->data != 0) {
                cout<<"element not found\n";
                return;
            }
            prev->link = check->link;
            delete check;
            cout<<"found and deleted\n";
        }
        void display() {
            if(head==NULL) {
                cout<<"empty list\n";
                return;
            }
            node *check = head;
            int i=0;
            while(check != NULL) {
                
                cout<<"a["<<++i<<"]: "<<check->data<<endl;
                check = check->link;
            }

        }
};

int main() {
    int choice = 0;
    list l;
    cout<<"\n\nLIST CREATED\n\n";
    int x,y;
    while(choice!=7) {
        cout<<"\n\n1->insert to front of list\n2->insert to rear of list\n3->delete front element of list\n4->delete rear element of list\n5->delete a specific value from list\n6->display contents of list\n7->exit program\n\nenter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"enter number to be added to front of list: ";
                cin>>x;
                l.insert_front(x);
                break;
            case 2:
                 cout<<"enter number to be added to rear of list: ";
                 cin>>y;
                 l.insert_rear(y);
                 break;
            case 3:
                cout<<"deleting front element of list...\n";
                l.del_front();
                break;
            case 4:
                cout<<"deleting rear element of list...\n";
                l.del_rear();
                break;
            case 5:
                cout<<"enter number to be deleted: ";
                cin>>x;
                l.search_n_del(x);
                break;
            case 6:
                cout<<"\n\n\tDISPLAYING CONTENTS OF LIST\n\n";
                l.display();
                break;
        }
    }
    return 0;
}