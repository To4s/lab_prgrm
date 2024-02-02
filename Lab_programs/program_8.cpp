//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>
using namespace std;

int precedence(char c) {
    switch(c) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

string to_post(string s) {
    stack<char> st;
    string result;
    for(char c : s) {
        if(isalpha(c) || isdigit(c)) {
                result+=c;
        }
        else if(c=='(') {
            st.push(c);
        }
        else if(c==')') {
            while(st.top()!='(') {
                result+= st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c=='^') {
            st.push(c);
        }
        else {
            while(!st.empty() && precedence(c) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string exp;
    cout<<"Enter Expression: ";
    cin>>exp;
    string result = to_post(exp);
    cout<<"\n\nPostfix expression: "<<result<<endl;
    return 0;
}