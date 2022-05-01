#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;

vector<pair<int, int>> graph[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    ll dist[n + 1];
    bool marked[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
        marked[i] = false;
    }

    priority_queue<pair<ll, int>> q;

    dist[1] = 0;
    q.push({0, 1});

    while (!q.empty())
    {
        int u = q.top().second;
        // ll w = -q.top().first;

        q.pop();

        if (marked[u])
            continue;
        marked[u] = true;

        for (auto it : graph[u])
        {
            int v = it.first;
            ll c = it.second;
            if (dist[v] > dist[u] + c)
            {
                dist[v] = dist[u] + c;
                q.push({-dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}