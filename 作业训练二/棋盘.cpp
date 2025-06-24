//遵守CC 4.0 BY SA协议，本文转载自Cons.W --Drtxdt注
#include <iostream>

using namespace std;

int main()
{
    int n, maxSize = 1, cnt = 0;
    char tmp;
    cin >> n;
    int dp[n][n], arr[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            arr[i][j] = tmp - '0';
            if (tmp == '1')
            {
                dp[i][j] = 1;
                cnt++;
            }
            else dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (arr[i - 1][j - 1] == 1 && arr[i][j] == 1)
            {
                int k = i - 2, l = j - 2, xbound = i - dp[i - 1][j - 1], ybound =
                        j - dp[i - 1][j - 1], cnt1 = 1, cnt2 = 0;
                while (k >= xbound && l >= ybound)
                {
                    if (arr[k][j] == 0 || arr[i][l] == 0) break;
                    k -= 2;
                    l -= 2;
                    cnt1 += 2;
                }
                k = i - 1, l = j - 1;
                while (k >= xbound && l >= ybound)
                {
                    if (arr[k][j] == 1 || arr[i][l] == 1)break;
                    k -= 2;
                    l -= 2;
                    cnt2 += 2;
                }
                if (cnt2 > 0) dp[i][j] = max(cnt1, cnt2);
                else dp[i][j] = 1;
                if (dp[i][j] > maxSize)
                {
                    maxSize = dp[i][j];
                    cnt = 1;
                }
                else if (dp[i][j] == maxSize) cnt++;
            }
        }
    }
    cout << maxSize << " " << cnt;
    return 0;
}