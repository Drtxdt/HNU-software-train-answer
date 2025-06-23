#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;
int n;
int x[N], y[N];
int l, r;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i] < 0)
            l++;
        else
            r++;
    }
    if (l <= 1 || r <= 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}