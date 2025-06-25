//转载自 通心粉丝 --Drtxdt注
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n != 0)
    {
        string s;
        cin >> s;

        int l_st, r_st;
        if (n % 2 == 0)
        {
            l_st = n / 2 - 1;
            r_st = n / 2;
            int mini = n - 1;
            for (; r_st <= n - 1; r_st++, l_st++)
            {

                int j = l_st;
                int i = r_st;
                int flag = 1;
                for (; i <= n - 1; i++, j--)
                {
                    if (s[j] != s[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    mini = l_st + 1 - (n - r_st);
                    break;
                }

                flag = 1;
                i = r_st + 1;
                j = l_st;
                for (; i <= n - 1; i++, j--)
                {
                    if (s[j] != s[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    mini = l_st + 1 - (n - r_st - 1);
                    break;
                }
            }
            cout << mini << '\n';
        }
        else if (n % 2 != 0)
        {
            int cen = n / 2;
            int l = cen - 1;
            int r = cen + 1;
            int flag = 1;
            for (; r <= n - 1; r++, l--)
            {
                if (s[r] != s[l])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << 0 << '\n';
                continue;
            }

            l_st = n / 2;
            r_st = n / 2 + 1;
            int mini = n - 1;

            for (; r_st <= n - 1; r_st++, l_st++)
            {
                int j = l_st;
                int i = r_st;

                int flag = 1;
                for (; i <= n - 1; i++, j--)
                {
                    if (s[j] != s[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    mini = l_st + 1 - (n - r_st);
                    break;
                }

                flag = 1;
                i = r_st + 1;
                j = l_st;
                for (; i <= n - 1; i++, j--)
                {
                    if (s[j] != s[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    mini = l_st + 1 - (n - r_st - 1);
                    break;
                }
            }
            cout << mini << '\n';
        }
    }
}