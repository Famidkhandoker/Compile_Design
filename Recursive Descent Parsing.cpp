/*Write a program to implement Recursive Descent Parsing for the following grammar
E->TE’
E’->+TE’ | €
T-> FT’
T’-> *FT’|€
F -> (E) | a

Sample input: a+a*a
Sample output: String is accepted

Sample input: a/a*a
Sample output: String is not accepted*/


#include <stdio.h>
#include <string.h>
char input[100];
int pos = 0;
int E();
int Eprime();
int T();
int Tprime();
int F();
int E() {
 if (T()) {
 return Eprime();
 }
 return 0;
}
int Eprime() {
 if (input[pos] == '+') {
 pos++;
 if (T()) {
 return Eprime();
 }
 return 0;
 }
 return 1;
}
int T() {
 if (F()) {
 return Tprime();
 }
 return 0;
}
int Tprime() {
 if (input[pos] == '*') {
 pos++;
 if (F()) {
 return Tprime();
 }
 return 0;
 }
 return 1;
}
int F() {
 if (input[pos] == 'a') {
 pos++;
 return 1;
 }
 if (input[pos] == '(') {
 pos++;
 if (E() && input[pos] == ')') {
 pos++;
 return 1;
 }
 }
 return 0;
}
int main() {
 printf("Enter the string: ");
 scanf("%s", input);
 pos = 0;
 if (E() && input[pos] == '\0') {
 printf("String is accepted\n");
 } else {
 printf("String is not accepted\n");
 }
 return 0;
}

