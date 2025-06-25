#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> tower(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tower[i][j];
        }
    }

    vector<vector<int>> dp = tower;
    vector<vector<int>> path(n, vector<int>(n, 0)); // 记录路径选择

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (dp[i + 1][j] >= dp[i + 1][j + 1])
            {
                dp[i][j] = tower[i][j] + dp[i + 1][j]; // 选择左下方
                path[i][j] = j;
            }
            else
            {
                dp[i][j] = tower[i][j] + dp[i + 1][j + 1]; // 选择右下方
                path[i][j] = j + 1;
            }
        }
    }

    cout << dp[0][0] << endl;

    int col = 0;
    cout << tower[0][col];

    for (int i = 1; i < n; i++)
    {
        col = path[i - 1][col];
        cout << " " << tower[i][col];
    }
    cout << endl;

    return 0;
}