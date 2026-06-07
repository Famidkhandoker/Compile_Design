//Write a C/C++ program to recognize valid and invalid identifier.

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if((s[0]>='A'&&s[0]<='Z')||(s[0]>='a'&&s[0]<='z')||s[0]=='_')
        cout<<"Valid Identifier";
    else
        cout<<"Invalid Identifier";
}

//1name
//Invalid Identifier
