#include <iostream>
#include <map>
using namespace std;
constexpr int N = 2010;

int n, m;
int a[N][N];
int mp[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = s[j - 1] - '0';
            if (a[i][j] == 1)
                mp[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1 && mp[j] < 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}