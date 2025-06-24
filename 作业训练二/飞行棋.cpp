#include <iostream>
#include <string>
using namespace std;

constexpr int MAXN = 210;

int g[MAXN];
int n, a, b, c;

int main()
{
    while (cin >> n >> a >> b >> c)
    {
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s == "N")
            {
                g[i] = -1;
            }
            else
            {
                g[i] = stoi(s.substr(1));
            }
        }

        int lele = 0, yueyue = 0;
        long long dice = (1LL * a * c + b) % 6 + 1;
        bool flag = true;
        bool gameOver = false;

        while (!gameOver)
        {
            if (flag)
            {
                int next = lele + dice;
                if (next >= n)
                {
                    next = 2 * (n - 1) - next;
                }
                while (g[next] != -1)
                    next = g[next];
                if (next == n - 1)
                {
                    cout << "Lele" << endl;
                    gameOver = true;
                    break;
                }
                if (next > 0 && next == yueyue)
                {
                    yueyue = 0;
                }
                lele = next;
                dice = (1LL * a * dice + b) % 6 + 1;
                flag = false;
            }
            else
            {
                int next = yueyue + dice;
                if (next >= n)
                {
                    next = 2 * (n - 1) - next;
                }
                while (g[next] != -1)
                {
                    next = g[next];
                }
                if (next == n - 1)
                {
                    cout << "Yueyue" << endl;
                    gameOver = true;
                    break;
                }
                if (next > 0 && next == lele)
                {
                    lele = 0;
                }
                yueyue = next;
                dice = (1LL * a * dice + b) % 6 + 1;
                flag = true; 
            }
        }
    }
    return 0;
}