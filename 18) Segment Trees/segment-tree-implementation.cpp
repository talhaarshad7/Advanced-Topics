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
void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = t[2 * id] + t[2 * id + 1];
}
void update(int id, int l, int r, int pos, int val)
{
    // cout << "update" << endl;
    if (l > pos || r < pos)
        return;
    if (l == r)
    {
        t[id] = val;
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = t[2 * id] + t[2 * id + 1];
}
int query(int id, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return 0;
    if (l >= lq && r <= rq)
    { // lq<=l<=r<=rq
        return t[id];
    }
    int mid = (l + r) / 2;
    return query(2 * id, l, mid, lq, rq) + query(2 * id + 1, mid + 1, r, lq, rq);
}
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n - 1, pos - 1, val);
        }
        else if (ch == 2)
        {
            int lq, rq;
            cin >> lq >> rq;
            cout << query(1, 0, n - 1, lq - 1, rq - 1) << endl;
        }
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