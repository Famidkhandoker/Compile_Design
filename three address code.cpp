/*Write a C++ program to implement three address code. */
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int precedence(char op) {
 if (op == '+' || op == '-')
 return 1;
 if (op == '*' || op == '/')
 return 2;
 return 0;
}
string infixToPostfix(const string& exp) {
 stack<char> st;
 string postfix;
 for (char ch : exp) {
 if (isalnum(ch)) {
 postfix += ch;
 }
 else if (ch == '(') {
 st.push(ch);
 }
 else if (ch == ')') {
 while (!st.empty() && st.top() != '(') {
 postfix += st.top();
 st.pop();
 }
 if (!st.empty()) {
 st.pop();
 }
 }
 else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
 while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
 postfix += st.top();
 st.pop();
 }
 st.push(ch);
 }
 }
 while (!st.empty()) {
 postfix += st.top();
 st.pop();
 }
 return postfix;
}
void generateTAC(const string& postfix) {
 stack<string> st;
 int tempCount = 1;
 cout << "\nThree Address Code:\n";
 for (char ch : postfix) {
 if (isalnum(ch)) {
 st.push(string(1, ch));
 }
 else {
 string op2 = st.top();
 st.pop();
 string op1 = st.top();
 st.pop();
 string temp = "t" + to_string(tempCount++);
 cout << temp << " = "
 << op1 << " "
 << ch << " "
 << op2 << endl;
 st.push(temp);
 }
 }
 cout << "Result = " << st.top() << endl;
}
int main() {
 string expression;
 cout << "Enter an arithmetic expression: ";
 cin >> expression;
 string postfix = infixToPostfix(expression);
 cout << "\nPostfix Expression: " << postfix << endl;
 generateTAC(postfix);
}
