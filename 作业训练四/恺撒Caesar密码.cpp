#include <iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s), s != "ENDOFINPUT")
    {
        if (s == "START" || s == "END")
            continue;
        for (auto& c : s)
            if (isalpha(c))
            {
                c -= 5;
                if (c < 'A')
                    c += 26;
            }
        cout << s << endl;
    }
    return 0;
}