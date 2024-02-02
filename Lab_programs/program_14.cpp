//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

void search(int a[],int key) {
    for(int i=0;i<sizeof(a);i++) {
        if(a[i] == key) {
            cout<<"key found at index "<<i+1<<endl;
            return;
        }
    }
    cout<<"key not found\n";
}

int main() {
    int n,key;
    cout<<"enter size of array: ";
    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++) {
        cout<<"\na["<<i+1<<"]: ";
        cin>>a[i];
    }
    cout<<"\n\nenter key: ";
    cin>>key;
    search(a,key);
    return 0;
}