//Write a LEX/C++ program to identify token.
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string line, token;

    cout << "Enter a sentence: ";
    getline(cin, line);

    stringstream ss(line);

    while (ss >> token) {
        cout << token << endl;
    }

    return 0;
}

//on the otherhand

#include <iostream>
using namespace std;

int main() {
    string token;

    cout << "Enter tokens: ";

    while(cin >> token) {
        cout << token << endl;
    }

    return 0;
}

//Enter tokens: int a = 10
//int
//a
//=
//10

