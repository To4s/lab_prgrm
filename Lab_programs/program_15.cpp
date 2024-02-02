//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

void swap(int& a,int& b) {
    int temp = b;
    b = a;
    a = temp;
}

class num_array {
    int n;
    int a[100];
    public:
        num_array() {
            cout<<"enter size of array: ";
            cin>>n;
            for(int i=0;i<n;i++) {
                cout<<"a["<<i+1<<"]: ";
                cin>>a[i];
            }
        }
        void sort() {
            cout<<"sorting array...\n\n";
            for(int i = 0 ; i<n-1; i++) {
                for(int j = 0 ; j<n-i-1; j++) {
                    if(a[j]>a[j+1]) {
                        swap(a[j],a[j+1]);
                    }
                }
            }
        }
        void display() {
            for(int i=0;i<n;i++) {
                cout<<"a["<<i+1<<"]: "<<a[i]<<endl;
            }
            cout<<"\n\n";
        }
        void binary_search(int key) {
            int low=0,high=n-1,mid;
            while(low<=high) {
                mid=(low+high/2);
                if(a[mid] == key) {
                    cout<<"key found at index "<<mid+1<<endl;
                    return;
                }
                if(a[mid] > key) {
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            cout<<"key not found\n";
        }        
};

int main() {
    num_array x;
    cout<<"array before sorting:\n";
    x.display();
    x.sort();
    cout<<"\n\narray after sorting:\n";
    x.display();
    int key;
    cout<<"\n\nenter key data to be searched: ";
    cin>>key;
    x.binary_search(key);
    return 0;
}