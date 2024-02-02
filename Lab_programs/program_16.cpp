//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
using namespace std;

void swap(int& a,int& b) {
    int temp = b;
    b = a;
    a = temp;
}

class arr {
    int a[100];
    int n;
    public:
        arr() {
            cout<<"enter size of array: ";
            cin>>n;
            for(int i = 0 ; i<n ; i++) {
                cout<<"a["<<i+1<<"]: ";
                cin>>a[i];
            }
        }
        void display() {
            for(int i=0;i<n;i++) {
                cout<<"a["<<i+1<<"]: "<<a[i]<<endl;
            }
            cout<<"\n\n";
        }
        void select_sort() {
            int min;
            int n_min;
            for(int i = 0;i<n-1;i++) {
                min = i;
                for(int j = i;j<n;j++) {
                    if(a[i]>a[j]) {
                        n_min = j;
                    }
                }
                swap(a[min],a[n_min]);
            }
        }
};

int main() {
    arr obj;
    cout<<"before sorting:\n";
    obj.display();
    obj.select_sort();
    cout<<"after sorting:\n";
    obj.display();
    return 0;
}