#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> poly;
    int n, m;
    while (cin >> n >> m, n != 0 || m != 0)
        poly[n] += m;
    while (cin >> n >> m, n != 0 || m != 0)
        poly[n] += m;
    if (!poly.empty())
    {
        auto it = poly.end();
        do
        {
            --it;
            if (it->second != 0)
            {
                cout << it->first << " " << it->second << endl;
            }
        }
        while (it != poly.begin());
    }

    return 0;
}