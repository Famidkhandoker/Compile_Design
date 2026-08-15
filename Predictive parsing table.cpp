/*Write a C/ C++ program to implement Predictive parsing table for mini language.

Sample Input:
E -> eEx
E -> aBc
F -> fFy
G -> gGz

Sample Output:

e a f g
------------------------------------------------------------------------------
E E->eEx E->aBc
------------------------------------------------------------------------------
F F->fFy
--------------------------------------------------------------------------------
G gGz*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
struct Production {
 char lhs;
 string rhs;
};
int main() {
 int n;
 cout << "Enter number of productions: ";
 cin >> n;
 vector<Production> productions;
 set<char> nonTerminals;
 set<char> terminals;
 cout << "Enter productions (example: E->eEx):\n";
 for (int i = 0; i < n; i++) {
 string p;
 cin >> p;
 char lhs = p[0];
 string rhs = p.substr(3);
 productions.push_back({lhs, rhs});
 nonTerminals.insert(lhs);
 if (!rhs.empty()) {
 char first = rhs[0];
 if (islower(first))
 terminals.insert(first);
 }
 }
 map<char, map<char, string>> table;
 for (auto &prod : productions) {
 if (prod.rhs.empty())
 continue;
 char first = prod.rhs[0];
 if (islower(first)) {
 table[prod.lhs][first] =
 string(1, prod.lhs) + "->" + prod.rhs;
 }
 }
 cout << "\n\nPredictive Parsing Table\n\n";
 const int width = 15;
 cout << left << setw(8) << "";
 for (char t : terminals)
 cout << setw(width) << t;
 cout << "\n";
 cout << string(8 + width * terminals.size(), '-') << "\n";
 for (char nt : nonTerminals) {
 cout << left << setw(8) << nt;
 for (char t : terminals) {
 if (table[nt].count(t))
 cout << setw(width) << table[nt][t];
 else
 cout << setw(width) << "";
 }
 cout << "\n";
 cout << string(8 + width * terminals.size(), '-') << "\n";
 }
 return 0;
}
