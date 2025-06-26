//CG有问题，必须保留7位小数，不能多也不能少
#include <cstdio>
#include <vector>
using namespace std;
constexpr int N = 1e5 + 10;
double f[N];
vector<int> E[N];

void dfs(int u, int fa)
{
    int cnt = 0;
    for (int i = 0; i < E[u].size(); i++)
    {
        int v = E[u][i];
        if (v == fa) continue;
        dfs(v, u);
        f[u] += (f[v] + 1.0);
        cnt++;
    }
    if (cnt) f[u] /= (double)cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs(1, 0);
    printf("%.7lf", f[1]);
    return 0;
}