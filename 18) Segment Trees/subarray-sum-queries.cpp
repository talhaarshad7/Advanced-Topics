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
struct ST
{
    int msum, rsum, lsum, tsum;
    ST(int msum = 0, int rsum = 0, int lsum = 0, int tsum = 0) : msum(msum), rsum(rsum), lsum(lsum), tsum(tsum) {}
};
ST operator+(const ST &A, const ST &B)
{
    ST temp;
    temp.msum = max(A.rsum + B.lsum, max(A.msum, B.msum));
    temp.lsum = max(A.tsum + B.lsum, A.lsum);
    temp.rsum = max(B.tsum + A.rsum, B.rsum);
    temp.tsum = A.tsum + B.tsum;
    return temp;
}
struct segtree
{
    vector<ST> tree;
    segtree(int n = 100100)
    {
        tree.resize(n * 4);
    }
    void update(int i, int l, int r, int pos, int val)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            int x = max(0, val);
            tree[i] = ST(x, x, x, val);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * i, l, mid, pos, val);
        update(2 * i + 1, mid + 1, r, pos, val);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    int query()
    {
        return tree[1].msum;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    segtree T(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        T.update(1, 0, n - 1, i, x);
    }
    for (int i = 0; i < q; i++)
    {
        int pos, val;
        cin >> pos >> val;
        pos--;
        T.update(1, 0, n - 1, pos, val);
        cout << T.query() << endl;
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