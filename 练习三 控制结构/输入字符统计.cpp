#include <iostream>
using namespace std;

int n;
char ch;
int upper, lower, number, other;
int ans;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> ch;
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
        else if (isdigit(ch))
        {
            number++;
            ans += ch - '0';
        }
        else
            other++;
    }
    cout << upper << " " << lower << " " << number << " " << other << endl;
    if (ans)
        cout << ans << endl;
    return 0;
}