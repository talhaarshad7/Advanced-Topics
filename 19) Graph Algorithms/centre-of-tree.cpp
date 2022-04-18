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

int n;
vector<vector<int>> g;
vector<int> dis;
vector<int> par;

void dfs(int nn, int pp, int dd)
{
    dis[nn] = dd;
    par[nn] == pp;
    for (auto v : g[nn])
    {
        if (v != pp)
            dfs(v, nn, dd + 1);
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    dis.resize(n + 1);
    par.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int max1 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dis[max1] < dis[i])
            max1 = i;
    }
    dfs(max1, 0, 0);
    int max2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dis[max2] < dis[i])
            max2 = i;
    }
    int temp = max2;
    vector<int> path;
    while (temp != 0)
    {
        path.push_back(temp);
        temp = par[temp];
    }
    cout << dis[max2] << endl;
    // cout<<path.size()-1<<endl; is also the diameter
    if (path.size() % 2 == 0)
    {
        int centre1 = path[path.size() / 2];
        int centre2 = path[(path.size() - 1) / 2];
    }
    else
    {
        int centre = path[(path.size() / 2) + 1];
    }
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