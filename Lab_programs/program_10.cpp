//note that to make this work on vscode 2010, include header file conio.h and call function getch() before the return 0 line

#include<iostream>
#include<string>
#include<ctype.h>
#include<math.h>
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

//Same thing as before, converts prefix to postfix expression

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

//to solve postfix expression

float op(float op2,char c, float op1) {
    switch(c) {
        case '+': return op2+op1;
        case '*': return op2*op1;
        case '-': return op2-op1;
        case '/': return op2/op1;
        case '^': return pow(op2,op1);
    }
}

float solve_post(string s) {
    stack<float> st;
    for(char c : s) {
        if(isdigit(c)) {
            st.push((float)c - 48);
        }
        else {
            float op1 = st.top();
            st.pop();
            float op2 = st.top();
            st.pop();
            float n = op(op2,c,op1);
            st.push(n);
        }
    }
    return st.top();
}


int main() {
    string exp;
    cout<<"Enter Expression(infix): ";
    cin>>exp;
    exp = to_post(exp);
    cout<<"\n\nPostfix expression: "<<exp<<endl;
    float answer = solve_post(exp);
    cout<<"\n\nSolution to given expression: "<<answer<<endl;
    return 0;
}