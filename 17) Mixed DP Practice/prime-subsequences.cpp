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
int dp[1230][1230];
void solve()
{
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<int> v;
    for (auto i : m)
    {
        v.push_back(i.second);
    }
    for (int i = 0; i < v.size(); i++)
        dp[i][0] = 1;
    dp[0][1] = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j <= v.size(); j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j]) % mod;
            dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * v[i]) % mod) % mod;
        }
    }
    int ans[v.size() + 1];
    ans[0] = 1;
    for (int i = 1; i <= v.size(); i++)
        ans[i] = (ans[i - 1] + dp[v.size() - 1][i]) % mod;
    if (k <= v.size())
        cout << ans[k] << endl;
    else
        cout << ans[v.size()] << endl;
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