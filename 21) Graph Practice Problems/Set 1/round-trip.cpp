#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll mod = 1e9 + 7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int cs, ce;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
bool dfs(int v, int par)
{
    color[v] = 1;
    for (auto u : adj[v])
    {
        if (u == par)
            continue;
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        else if (color[u] == 1)
        {
            cs = u;
            ce = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cs = -1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0 && dfs(i, parent[i]))
            break;
    }
    if (cs != -1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    for (int it = 1; it <= 1; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}