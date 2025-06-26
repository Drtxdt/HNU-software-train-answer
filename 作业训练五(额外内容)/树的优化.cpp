#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 200020;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

struct edge
{
    int to, nxt, val;
} e[N];

int n;
int head[N], cnt, ans;
int a[N], sz[N];

inline void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

inline void add_edge(int u,int v,int d)
{
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    e[cnt].val = d;
    head[u] = cnt;
}

inline void dfs1(int u,int f)
{
    sz[u] = 1; 
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

inline void dfs2(int u,int f,int sum)
{
    if (sum > a[u])
    {
        ans += sz[u];
        return;
    }
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == f) continue;
        dfs2(v, u, max(0ll, sum + e[i].val));
    }
}

signed main()
{
    init();
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 2; i <= n; i++)
    {
        int x = read(), y = read();
        add_edge(i, x, y);
        add_edge(x, i, y);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << ans;
}