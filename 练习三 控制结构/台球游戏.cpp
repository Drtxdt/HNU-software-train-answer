#include <iostream>
using namespace std;

int n;
char op;
int ans;


int main()
{
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 'r')
        {
            int a;
            cin >> a;
            ans += a;
        }
        else if (op == 'y')
            ans += 2;
        else if (op == 'g')
            ans += 3;
        else if (op == 'c')
            ans += 4;
        else if (op == 'b')
            ans += 5;
        else if (op == 'p')
            ans += 6;
        else if (op == 'B')
            ans += 7;
    }
    cout << ans << endl;
    return 0;
}