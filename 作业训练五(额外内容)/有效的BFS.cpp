#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int N = 2e5 + 10;
int n;
vector<int> edges[N];
int a[N];
int parent[N];

void build_parent()
{
    queue<int> q;
    q.push(a[1]);
    parent[a[1]] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : edges[u])
        {
            if (parent[v] == 0 && v != parent[u])
            {
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (a[1] != 1)
    {
        cout << "No\n";
        return 0;
    }

    build_parent();

    queue<int> q;
    q.push(a[1]);
    for (int i = 2; i <= n; i++)
    {
        int current = a[i];
        int p = parent[current];
        while (!q.empty() && q.front() != p)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << "No\n";
            return 0;
        }
        q.push(current);
    }
    cout << "Yes\n";
    return 0;
}