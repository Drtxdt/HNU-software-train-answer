#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int n;

int main()
{
    cin >> n;
    while (n--)
    {
        string x, y;
        cin >> x >> y;
        ll a = 0, b = 0;
        for (int i = 0; i < x.length(); i++)
            a = a * 26 + (x[i] - 'a');
        for (int i = 0; i < y.length(); i++)
            b = b * 26 + (y[i] - 'a');
        ll t = a + b;
        string ans;
        do
        {
            int r = t % 26;
            ans.push_back(r + 'a');
            t /= 26;
        }while (t > 0);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}