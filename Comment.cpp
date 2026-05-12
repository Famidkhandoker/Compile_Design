Problem 1:
Write a c/c++ program to identify weather a given line is a comment or not

Example:
Input:/* Hello World */
Output: This is a comment

Input://Hello World
Output: This is a comment

Input: Hello World
Output: This is not a comment




#include<iostream>
#include<string>
using namespace std;
int main(){
string line;
getline(cin,line);
if(line[0]=='/'&& line[1]=='/'){
    cout<<"This is a comment";
}
else if(line[0]=='/' && line[1]=='*' && line[line.length()-2]=='*' && line[line.length()-1]=='/'){
    cout<<"This is a comment";
}
else{
    cout<<"This is not a comment";
}
}
