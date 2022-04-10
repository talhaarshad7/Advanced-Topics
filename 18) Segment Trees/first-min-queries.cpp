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
int a[100100];
int t[400400];
void build(int i, int l, int r)
{
    if (l == r)
    {
        t[i] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = max(t[2 * i], t[2 * i + 1]);
}
int query(int i, int l, int r, int x)
{
    if (t[i] > x)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (t[2 * i] >= x)
        return query(2 * i, l, mid, x);
    if (t[2 * i] >= x)
        return query(2 * i, mid + 1, r, x);
}
void update(int i, int l, int r, int pos, int x)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        t[i] -= x;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * i, l, mid, pos, x);
    update(2 * i + 1, mid + 1, r, pos, x);
    t[i] = max(t[2 * i], t[2 * i + 1]);
}
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        int ans = query(1, 0, n - 1, x);
        if (ans != -1)
        {
            update(1, 0, n - 1, ans, x);
        }
        cout << ans + 1 << endl;
    }
}
int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}