#include <iostream>
using namespace std;

int n;
int ans = 1;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ans = (ans + 1) * 2;
    }
    cout << ans << endl;
}