#include<iostream>
using namespace std;

int main()
{

    char nonTerminal[] = {'A', 'B', 'C', 'D'};

    string production[4][2] =
    {
        {"eAX", "jhk"},
        {"aBp", ""},
        {"fdCy", ""},
        {"gDz", ""}
    };

    // First set
    for (int i = 0; i < 4; i++)
    {
        cout << "FIRST(" << nonTerminal[i] << ")={";
        bool first = true;

        for (int j = 0; j < 2; j++)
        {
            if (production[i][j] != "")
            {
                if (!first)
                    cout << ",";
                cout << production[i][j][0];
                first = false;
            }
        }
        cout << "}" << endl;
    }

    cout << endl;

    // Follow set
    for (int i = 0; i < 4; i++)
    {
        cout << "FOLLOW(" << nonTerminal[i] << ")={";

        if (i == 0)
            cout << "$,";

        for (int j = 0; j < 2; j++)
        {
            string s = production[i][j];

            for (int k = 0; k <(int)s.length() - 1; k++)
            {
                if (s[k] == nonTerminal[i])
                {
                    cout << s[k + 1];
                    break;
                }
            }
        }

        cout << "}" << endl;
    }

    return 0;
}
