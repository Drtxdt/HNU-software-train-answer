#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(a);
    sort(b.begin(), b.end(), greater<int>());
    map<int, int> mp;
    int cur = 0;


    for (int i = 0; i < n; i++)
    {
        if (i == 0 || b[i] != b[i - 1])
        {
            cur++;
            mp[b[i]] = cur;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << mp[a[i]];
    }
    cout << endl;
    return 0;
}