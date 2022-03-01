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

void solve()
{
    int n, k;
    string st;
    cin >> n >> k;
    cin >> st;
    string s[3];
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            s[0] += 'R';
        else if (i % 3 == 1)
            s[0] += 'G';
        else
            s[0] += 'B';
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            s[1] += 'G';
        else if (i % 3 == 1)
            s[1] += 'B';
        else
            s[1] += 'R';
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            s[2] += 'B';
        else if (i % 3 == 1)
            s[2] += 'R';
        else
            s[2] += 'G';
    }
    int ans = INT_MAX;
    for (int j = 0; j <= 2; j++)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = 0;
            if (st[i] != s[j][i])
                a[i] = 1;
        }
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        ans = min(ans, a[k - 1]);
        for (int i = k; i < n; i++)
            ans = min(ans, a[i] - a[i - k]);
    }
    cout << ans << endl;
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