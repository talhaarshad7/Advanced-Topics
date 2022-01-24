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
int n, k;
int cw, cb;
int w[10], b[10];
void count()
{
    cw = cb = 0;
    for (int i = 1; i <= n; i += 2)
    {
        if (i == n)
        {
            cw++;
            w[cw] = i;
        }
        else
        {
            cw++;
            w[cw] = i;
            cw++;
            w[cw] = i;
        }
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (i == n)
        {
            cb++;
            b[cb] = i;
        }
        else
        {
            cb++;
            b[cb] = i;
            cb++;
            b[cb] = i;
        }
    }
}
int b1[30][30], b2[30][30];
void solve()
{
    count();
    memset(b1, 0, sizeof(b1));
    memset(b2, 0, sizeof(b2));
    cin >> n >> k;
    b1[0][0] = 1;
    for (int i = 1; i <= cw; i++)
    {
        for (int j = 0; j <= w[i]; j++)
        {
            b1[i][j] = b1[i - 1][j] + b1[i - 1][j - 1] * (w[i] - (j - 1));
        }
    }
    b2[0][0] = 1;
    for (int i = 1; i <= cb; i++)
    {
        for (int j = 0; j <= b[i]; j++)
        {
            b2[i][j] = b2[i - 1][j] + b2[i - 1][j - 1] * (b[i] - (j - 1));
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += (b1[cw][i] * b2[cb][k - i]);
    }
    cout << ans << endl;
}
int main()
{
    fast_cin();
    for (int it = 1; it <= 1; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}