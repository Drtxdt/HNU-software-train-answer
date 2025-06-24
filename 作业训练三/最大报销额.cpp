#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    double Q;
    int N;
    while (cin >> Q >> N && N != 0)
    {
        vector<int> valid_bills;
        int maxV = min(static_cast<int>(Q * 100 + 0.5), 3000000);

        for (int i = 0; i < N; i++)
        {
            int m;
            cin >> m;
            double total = 0.0;
            bool valid = true;
            int totalCents = 0;

            for (int j = 0; j < m; j++)
            {
                string item;
                cin >> item;
                size_t pos = item.find(':');
                if (pos == string::npos)
                {
                    valid = false;
                    continue;
                }

                char type = item[0];
                string priceStr = item.substr(pos + 1);
                double price = stod(priceStr);
                int cents = static_cast<int>(price * 100 + 0.5);

                if (type != 'A' && type != 'B' && type != 'C')
                {
                    valid = false;
                }

                if (cents > 60000)
                {
                    valid = false;
                }

                total += price;
                totalCents += cents;
            }

            if (total > 1000.0)
            {
                valid = false;
            }

            if (totalCents > 100000)
            {
                valid = false;
            }

            if (valid)
            {
                valid_bills.push_back(totalCents);
            }
        }

        vector<int> dp(maxV + 1, 0);
        int maxReimburse = 0;

        for (int bill : valid_bills)
        {
            for (int j = maxV; j >= bill; j--)
            {
                if (dp[j - bill] + bill > dp[j])
                {
                    dp[j] = dp[j - bill] + bill;
                    if (dp[j] > maxReimburse)
                    {
                        maxReimburse = dp[j];
                    }
                }
            }
        }

        printf("%.2f\n", maxReimburse / 100.0);
    }
    return 0;
}