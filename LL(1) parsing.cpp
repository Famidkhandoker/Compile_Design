/*Write a program to implement LL(1) parsing for the following grammar
A->aCa
C->bC
C->€
Sample Input: abba
Sample Output:
Stack Input
A$ abba$
aCa$ abba$
Ca$ bba$
bCa$ bba$
Ca$ ba$
bCa$ ba$
Ca$ a$
a$ a$
$ $*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter input string: ";
    cin >> input;
    input += "$";
    stack<char> st;
    st.push('$');
    st.push('A');
    int ip = 0;
    cout << "\nStack\t\tInput\n";
    cout << "-----------------------------\n";
    while (!st.empty()) {
        string stackContent;
        stack<char> temp = st;
        while (!temp.empty()) {
            stackContent += temp.top();
            temp.pop();
        }
        string remainingInput = input.substr(ip);
        cout << stackContent << "\t\t" << remainingInput << endl;
        char top = st.top();
        char current = input[ip];
        if (top == '$' && current == '$') {
            cout << "\nString accepted!\n";
            return 0;
        }
        if (top == 'a' || top == 'b' || top == '$') {
            if (top == current) {
                st.pop();
                ip++;
            } else {
                cout << "\nString rejected!\n";
                return 0;
            }
        }
        else if (top == 'A') {
            st.pop();
            if (current == 'a') {
                st.push('a');
                st.push('C');
                st.push('a');
            } else {
                cout << "\nString rejected!\n";
                return 0;
            }
        }
        else if (top == 'C') {
            st.pop();
            if (current == 'b') {
                st.push('C');
                st.push('b');
            }
            else if (current == 'a') {
            }
            else {
                cout << "\nString rejected!\n";
                return 0;
            }
        }
    }
    cout << "\nString rejected!\n";
    return 0;
}
