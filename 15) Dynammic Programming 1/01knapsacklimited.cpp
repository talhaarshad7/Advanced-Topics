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
int w[1001];
int p[1001];
int n, W;
int memo[1001][1001];
int dp(int i, int curw)
{
    if (i == 0 && w == 0)
        return 0;
    if (i == 0)
        return 0;
    if (memo[i][curw] != -1)
        return memo[i][curw];
    int ans = dp(i - 1, curw);
    if (w[i] <= curw)
        ans = max(ans, dp(i - 1, curw - w[i]) + p[i]); // for finite supply
    // ans = max(ans, dp(i, curw-w[i]) + p[i]); for infinite supply
    return memo[i][curw] = ans;
}
void solve()
{
    memset(memo, -1, sizeof(memo));
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> p[i];
    // this is also correct -cout << dp(n, W) << endl;
    int ans = 0;
    for (int i = 0; i <= W; i++)
        ans = max(ans, dp(n, i));
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