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
int a[101][101];
int dp[101][101][12];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            a[i + 1][j + 1] = c - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    for (int j = 1; j <= m; j++)
    {
        int t = a[n][j] % k;
        dp[n][j][t] = a[n][j];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int l = 0; l < k; l++)
            {
                if (j > 1 && dp[i + 1][j - 1][l] >= 0)
                {
                    int t = dp[i + 1][j - 1][l] + a[i][j];
                    if (t > dp[i][j][t % k])
                        dp[i][j][t % k] = t;
                }
                if (j < m && dp[i + 1][j + 1][l] >= 0)
                {
                    int t = dp[i + 1][j + 1][l] + a[i][j];
                    if (t > dp[i][j][t % k])
                        dp[i][j][t % k] = t;
                }
            }
        }
    }
    int ans = -1;
    for (int j = 1; j <= m; j++)
        ans = max(dp[1][j][0], ans);
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