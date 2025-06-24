#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pa(n + 1, 0), pb(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pa[i] = pa[i - 1] + (s[i - 1] == 'a');
        pb[i] = pb[i - 1] + (s[i - 1] == 'b');
    }

    vector<int> sa(n + 1, 0);
    sa[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sa[i] = sa[i + 1] + (s[i] == 'a');
    }

    vector<int> maxB(n + 1, 0);
    maxB[n] = pb[n] + sa[n]; 
    for (int j = n - 1; j >= 0; j--)
    {
        maxB[j] = max(maxB[j + 1], pb[j] + sa[j]);
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, pa[i] - pb[i] + maxB[i]);
    }

    cout << ans << endl;
    return 0;
}