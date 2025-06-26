#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
constexpr int N = 2e3 + 10;
constexpr ll INF = 1e18;

int n, m;
ll w;
int a[N][N];
ll d_start[N][N], d_end[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int sx, int sy, ll dist[N][N])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = INF;
    queue<pair<int, int>> q;
    if (a[sx][sy] == -1) return;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (a[nx][ny] == -1) continue;
            if (dist[nx][ny] > dist[x][y] + w)
            {
                dist[nx][ny] = dist[x][y] + w;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    bfs(1, 1, d_start);
    bfs(n, m, d_end);

    ll ans = d_start[n][m];

    vector<pair<int, int>> channels;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] > 0)
                channels.emplace_back(i, j);

    ll min_s = INF, min_e = INF;
    for (auto [x, y] : channels)
    {
        if (d_start[x][y] != INF)
            min_s = min(min_s, d_start[x][y] + a[x][y]);
    }
    for (auto [x, y] : channels)
    {
        if (d_end[x][y] != INF)
            min_e = min(min_e, d_end[x][y] + a[x][y]);
    }

    if (min_s != INF && min_e != INF)
        ans = min(ans, min_s + min_e);

    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}