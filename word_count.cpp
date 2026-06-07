//Write a LEX/C++ program to count word from the sentence.
#include <iostream>
using namespace std;

int main() {
    string s;
    cout<<"Enter the sentence: ";
    getline(cin, s);

    int words = 1;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ')
            words++;
    }

    cout << "Total words = " << words;

    return 0;
}

//My Name is Famid Khandoker
// Total words = 5
