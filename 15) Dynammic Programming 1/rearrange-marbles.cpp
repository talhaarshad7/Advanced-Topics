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
int dp[101][101][2];
int k1, k2;
int countt(int n1, int n2, bool f)
{
    if (n1 + n2 == 0)
        return 1;
    if (dp[n1][n2][f] != -1)
        return dp[n1][n2][f];
    dp[n1][n2][f] = 0;
    if (f == 0)
    {
        for (int i = 1; i <= min(n1, k1); i++)
            dp[n1][n2][f] = dp[n1][n2][f] + countt(n1 - i, n2, 1 - f);
    }
    else
    {
        for (int i = 1; i <= min(n2, k2); i++)
            dp[n1][n2][f] = dp[n1][n2][f] + countt(n1, n2 - i, 1 - f);
    }
    return dp[n1][n2][f];
}
void solve()
{
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout << (countt(n1, n2, 0) + countt(n1, n2, 1)) << endl;
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