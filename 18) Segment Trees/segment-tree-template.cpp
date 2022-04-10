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
// change node structure
struct node
{
    int min;
    int cnt;
    node(int m = 1e9, int c = 0)
    {
        min = m;
        cnt = c;
    }
};
int a[100100];
node t[400400];
// change merge logic
node merge(node a, node b)
{
    if (a.min == b.min)
    {
        return node(a.min, a.cnt + b.cnt);
    }
    else if (a.min > b.min)
        return b;
    else
        return a;
}
void build(int id, int l, int r)
{
    // leaf condition-might change
    if (l == r)
    {
        t[id] = node(a[l], 0);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}
void update(int id, int l, int r, int pos, int val)
{
    // ignore if:   pos     l------r       pos
    if (l > pos || r < pos)
        return;
    // leaf condition-might change
    // if :     l----pos-----r then check when equal
    if (l == r)
    {
        a[l] = val;
        t[id] = node(val, 0);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}
node query(int id, int l, int r, int lq, int rq)
{
    // ignore if: lq----|rq|    l-------r     |lq|-----rq
    if (l > rq || r < lq)
        return node(1e9, 0);
    if (l >= lq && r <= rq) // lq<=l<=r<=rq
        return t[id];
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}

void solve()
{
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