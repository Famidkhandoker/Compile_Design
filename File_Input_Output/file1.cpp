Write a C++ program that performs the following tasks:

Create a file named "input.txt".
Write multiple lines into the file, including:
Normal text lines
Single-line comments starting with //
Multi-line style comments in a single line using /* ... */
Open the file "input.txt" in read mode.
Read the file line by line.
Extract only the comment lines:
Lines starting with //
Lines starting with /* and ending with */
Write the extracted comment lines into another file named "comment.txt".
Display a success message after completion.





#include<iostream>
#include<fstream>
using namespace std;
int main(){
ofstream file("input.txt");

file<<"Hello World\n";
file<<"//How are you?\n";
file<<"What are you doing\n";
file<<"/*Who are you*/\n";
file<<"Hi Famid Khandoker\n";

file.close();
cout<<"Successfully";
return 0;

}
