#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (cin >> N && N != 0)
    {
        int M = N * (N - 1) / 2;
        vector<int> b(M);
        for (int i = 0; i < M; i++)
            cin >> b[i];

        multiset<int> base_ms(b.begin(), b.end());
        vector<int> ans;
        bool found = false;

        for (int k = 2; k < M; k++)
        {
            int t = b[0] + b[1] - b[k];
            if (t % 2 != 0) continue;

            int a0 = t / 2;
            if (a0 < 0) continue;

            int a1 = b[0] - a0;
            int a2 = b[1] - a0;
            if (a1 < 0 || a2 < 0) continue;
            if (a1 + a2 != b[k]) continue;

            multiset<int> ms = base_ms;
            auto it = ms.find(b[0]);
            if (it == ms.end()) continue;
            ms.erase(it);

            it = ms.find(b[1]);
            if (it == ms.end()) continue;
            ms.erase(it);

            it = ms.find(b[k]);
            if (it == ms.end()) continue;
            ms.erase(it);

            vector<int> current = {a0, a1, a2};
            bool valid = true;

            for (int idx = 3; idx < N; idx++)
            {
                if (ms.empty())
                {
                    valid = false;
                    break;
                }
                int next_val = *ms.begin() - a0;
                if (next_val < 0)
                {
                    valid = false;
                    break;
                }

                for (int j : current)
                {
                    int sum_val = j + next_val;
                    it = ms.find(sum_val);
                    if (it == ms.end())
                    {
                        valid = false;
                        break;
                    }
                    ms.erase(it);
                }
                if (!valid) break;
                current.push_back(next_val);
            }

            if (valid && ms.empty())
            {
                ans = current;
                found = true;
                break;
            }
        }

        if (found)
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}