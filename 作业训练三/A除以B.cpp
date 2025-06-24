#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], b, c[N];
int la, lc;

int sub(int c[], const int a[], int b)
{
    long long t = 0;
    for(int i = la - 1; i >= 0; i--)
    {
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }
    while(lc > 1 && c[lc - 1] == 0)
        lc--;
    return t;
}

int main()
{
    string x;
    cin >> x;
    cin >> b;
    la = x.size();
    lc = la;
    for (int i = 0; i < la; i++)
        a[la - 1 - i] = x[i] - '0';
    int r = sub(c, a, b);
    for (int i = lc - 1; i >= 0; i--)
        cout << c[i];
    cout << " " << r << endl;
    return 0;
}