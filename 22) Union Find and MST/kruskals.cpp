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

struct UnionFind
{
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = i, rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] < rank[yroot])
            {
                rank[yroot] += rank[xroot];
                parent[xroot] = yroot;
            }
            else
            {
                rank[xroot] += rank[yroot];
                parent[yroot] = xroot;
            }
        }
        set_size -= 1;
    }
    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
            parent[i] = i, rank[i] = 1;
    }
    int size()
    {
        return set_size;
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
            cout << i << " => " << parent[i] << endl;
    }
};
vector<pair<int, int>> g[100100];
void solve()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    UnionFind uf(n);
    vector<pair<int, pair<int, int>>> edgelist;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        // g[a].push_back({b,c});
        edgelist.push_back({c, {a, b}});
    }
    int mst_cost = 0, cnt = 0;
    sort(edgelist.begin(), edgelist.end());
    for (auto v : edgelist)
    {
        int x = v.second.first;
        int y = v.second.second;
        if (uf.find(x) != uf.find(y))
        {
            cnt++;
            mst_cost += v.first;
            uf.merge(x, y);
        }
    }
    if (cnt != n - 1)
    {
        cout << "NO Solution not connected" << endl;
        return;
    }
    cout << mst_cost << endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}