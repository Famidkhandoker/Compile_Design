/*Write a C++ program to remove single Line comment from the input file (input.txt)
source program.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile(R"(C:\Users\BUBT\Documents\code\input.txt)");
    ofstream outputFile(R"(C:\Users\BUBT\Documents\code\output.txt)");

    if (!inputFile)
    {
        cout << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error: Cannot create output.txt" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        size_t pos = line.find("//");

        if (pos != string::npos)
        {
            line = line.substr(0, pos);
        }

        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Single-line comments removed successfully." << endl;

    return 0;
}

