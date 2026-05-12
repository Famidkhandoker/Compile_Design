Problem 2:
Write a c/c++ program to identify valid keywords
Example:

Input: int
Output:This is a keyword

Input:while
Output:This is a keyword

Input: abc
output:This is not a keyword



#include<iostream>
#include<string>
using namespace std;
int main(){
string word;
string keywords[]={"int","float","char","double","if","else","while","for","return","class"};
int size=10;
bool iskeyword =false;
cout<<"Enter a valid Keyword: ";
cin>>word;

for(int i=0;i<size;i++){
    if(word==keywords[i]){
        iskeyword=true;
        break;
    }
}
if(iskeyword==true){
    cout<<word << " is a valid keyword."<<endl;
}
else{
     cout<<word << " is NOT a valid keyword."<<endl;
}
}
