#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 2e5 + 10;
int n, m;
int a[N];
vector<int> edges[N];
int ans = 0;

void dfs(int u, int parent, int current_streak, int max_streak)
{
    int new_max = max(max_streak, current_streak);
    if (new_max > m)
        return;
    bool is_leaf = true;
    for (int v : edges[u])
    {
        if (v != parent)
        {
            is_leaf = false;
            int next_streak = a[v] ? (current_streak + 1) : 0;
            dfs(v, u, next_streak, max(new_max, next_streak));
        }
    }
    if (is_leaf)
        ans++;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int initial_streak = a[1] ? 1 : 0;
    dfs(1, -1, initial_streak, initial_streak);
    cout << ans << endl;
    return 0;
}