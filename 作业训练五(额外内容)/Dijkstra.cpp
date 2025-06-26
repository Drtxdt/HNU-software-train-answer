#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

constexpr int N = 1e5 + 10;
constexpr LL INF = 1e17;

vector<pair<int, int>> edges[N];
LL dist1[N];
LL dist2[N];
bool st[N];

int n, m;

void dijkstra(LL dist[], int start)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        st[i] = false;
    }
    dist[start] = 0;

    priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
    heap.push({0, start});

    while (!heap.empty())
    {
        auto [d_val, u] = heap.top();
        heap.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto [v, w] : edges[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                heap.push({dist[v], v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        // 无向图，边存两次
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }


    dijkstra(dist1, 1);

    if (dist1[n] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    dijkstra(dist2, n);

    vector<int> path;
    int current = 1;
    path.push_back(1);

    while (current != n)
    {
        int min_node = n + 10;
        for (auto [v, w] : edges[current])
            if (dist1[current] + w + dist2[v] == dist1[n])
                if (v < min_node)
                    min_node = v;
        if (min_node == n + 10)
        {
            cout << -1 << endl;
            return 0;
        }
        current = min_node;
        path.push_back(current);
    }

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}