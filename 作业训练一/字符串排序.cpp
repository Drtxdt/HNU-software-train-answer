#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 110;

struct node
{
    string s;
    int x{};
    int idx{};

    bool operator<(const node& b) const
    {
        if (x == b.x)
        {
            return idx < b.idx;
        }
        return x < b.x;
    }
} a[N];

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].s;
        a[i].x = 0;
        a[i].idx = i;


        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i].s[j] > a[i].s[k])
                    a[i].x++;
            }
        }
    }
    sort(a, a + m);


    for (int i = 0; i < m; i++)
    {
        cout << a[i].s << endl;
    }
    return 0;
}