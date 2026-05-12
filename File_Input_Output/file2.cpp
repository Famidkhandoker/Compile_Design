#include<iostream>
#include<fstream>
using namespace std;
int main(){
ifstream inputFile("input.txt");
ofstream outputFile("comment.txt");
string line;
while(getline(inputFile,line)){
    if(line[0]=='/'&& line[1]=='/'){
        outputFile<<line<<endl;
    }
     else if(line[0]=='/'&& line[1]=='*'&&line[line.length()-2]=='*'&& line[line.length()-1]=='/'){
        outputFile<<line<<endl;
    }
}
inputFile.close();
outputFile.close();
cout<<"Comment extracted Successfully";
return 0;
}
