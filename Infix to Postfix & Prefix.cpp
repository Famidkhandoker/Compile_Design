// Write a C++ program to convert an Infix to Postfix/Prefix Expression using stack.
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

// Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for(char c : s) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(st.top()) >= prec(c)) {
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

// Infix to Prefix (easy trick)
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for(char &c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string exp;
    cout << "Enter Infix Expression: ";
    cin >> exp;

    cout << "Postfix: " << infixToPostfix(exp) << endl;
    cout << "Prefix: " << infixToPrefix(exp) << endl;

    return 0;
}

//Enter Infix Expression: A+B*C
//Postfix: ABC*+
//Prefix: +A*BC
