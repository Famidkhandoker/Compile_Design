//Write a C/C++ program to identify valid keywords.
#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;

    if(word=="int" || word=="float" || word=="char" ||
       word=="if" || word=="else" || word=="while")
        cout << "Valid Keyword";
    else
        cout << "Not a Keyword";

    return 0;
}

//float
//Valid Keyword
