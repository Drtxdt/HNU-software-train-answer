#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T& x)
{
    x = 0;
    char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

constexpr int MAXN = 5e3;
int n, a, b, f[MAXN + 5], lps[MAXN + 5][MAXN + 5];
char s[MAXN + 5];

int main()
{
    read(n), read(a), read(b);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            lps[i][j] = s[i] == s[j] ? lps[i - 1][j - 1] + 1 : 0; 
    memset(f, 0x3f, sizeof (f));
    f[0] = 0; 
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + a;
        for (int j = 1; j < i; ++j)
            f[i] = min(f[i], f[max(i - lps[i][j], j)] + b); 
    }
    write(f[n]);
    putchar('\n');
    return 0;
}