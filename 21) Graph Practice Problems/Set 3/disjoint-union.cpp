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

int n, q;
int par[100100];
int ran[100100];
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (ran[x] < ran[y])
    {
        par[x] = y;
        ran[y] += ran[x];
    }
    else
    {
        par[y] = x;
        ran[x] += ran[y];
    }
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        ran[i] = 1;
    }
    while (q--)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0)
            unite(x, y);
        else
            cout << (same(x, y)) << endl;
    }
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