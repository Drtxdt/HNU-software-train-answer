#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    int mid = (n - 1) / 2;
    int r = mid, c = mid;
    grid[r][c] = 1;

    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int num = 2;
    int step = 1;
    int count = 0;
    int dir_index = 0;

    while (num <= n * n)
    {
        for (int i = 0; i < step; i++)
        {
            r += dr[dir_index];
            c += dc[dir_index];


            if (r >= 0 && r < n && c >= 0 && c < n)
            {
                grid[r][c] = num;
                num++;
            }


            if (num > n * n) break;
        }


        dir_index = (dir_index + 1) % 4;
        count++;


        if (count % 2 == 0)
        {
            step++;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0) cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}