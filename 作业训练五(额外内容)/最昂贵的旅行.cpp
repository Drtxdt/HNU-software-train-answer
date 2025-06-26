#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int N = 1e3 + 10, M = 1e4 + 10;
typedef pair<int, int> pii;
vector<pii> edges[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    vector<int> costs(n, 0);
    vector<bool> visited(n, false);
    queue<int> q;

    // 从0号城市开始
    q.push(0);
    visited[0] = true;
    costs[0] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto& neighbor : edges[current])
        {
            int next = neighbor.first;
            int cost = neighbor.second;

            if (!visited[next])
            {
                visited[next] = true;
                costs[next] = costs[current] + cost;
                q.push(next);
            }
        }
    }

    int max_cost = 0;
    for (int i = 1; i < n; i++)
    {
        if (costs[i] > max_cost)
        {
            max_cost = costs[i];
        }
    }

    cout << max_cost << endl;

    return 0;
}