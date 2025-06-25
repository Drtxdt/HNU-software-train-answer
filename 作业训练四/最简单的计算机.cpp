#include <iostream>
using namespace std;

int m1, m2, r1, r2, r3;

void solution(const char& x)
{
    if (x == 'A')
        r1 = m1;
    else if (x == 'B')
        r2 = m2;
    else if (x == 'C')
        m1 = r3;
    else if (x == 'D')
        m2 = r3;
    else if (x == 'E')
        r3 = r1 + r2;
    else
        r3 = r1 - r2;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        m1 = a;
        m2 = b;
        string s;
        cin >> s;
        for (const auto &c : s)
            solution(c);
        cout << m1 << "," << m2 << endl;
    }
    return 0;
}