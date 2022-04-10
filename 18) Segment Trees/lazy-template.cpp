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
struct node
{
    int sum, maxr, lazy;
    node()
    {
        sum = 0;
        maxr = 0;
        lazy = 0;
    }
};
node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.maxr = max(a.maxr, b.maxr);
    return temp;
}
#define MAXN 100100
node t[4 * MAXN];

void push(int id, int l, int r)
{
    if (t[id].lazy)
    {
        t[id].sum = t[id].lazy * (r - l + 1);
        t[id].maxr = t[id].lazy;
        if (l != r)
        {
            t[id << 1].lazy = t[id].lazy;
            t[id << 1 | 1].lazy = t[id].lazy;
        }
        t[id].lazy = 0;
    }
}
void update(int id, int l, int r, int lq, int rq, int v)
{
    push(id, l, r);
    if (lq > r || l > rq)
        return;
    if (lq <= l && r <= rq)
    {
        t[id].lazy = v;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, lq, rq, v);
    update(id << 1 | 1, mid + 1, r, lq, rq, v);
    t[id] = merge(t[id << 1], t[id << 1 | 1]);
}
node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (lq > r || l > rq)
        return node();
    if (lq <= l && r <= rq)
        return t[id];
    int mid = (l + r) >> 1;
    return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

void solve()
{
    update(1, 0, 9, 0, 5, 3);
    update(1, 0, 9, 6, 9, 4);
    node x = query(1, 0, 9, 3, 6);
    cout << x.sum << " " << x.maxr << endl;
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