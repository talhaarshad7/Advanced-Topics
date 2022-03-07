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
int done[51][51];
int arr[501];
int n, x, y, z;
int memo[51][51][51];
int dp(int l, int r, int xx)
{
    if (l == r)
    {
        if (arr[l] == x)
            return 0;
        else
            return 1e9;
    }
    if (done[l][r])
        return memo[l][r][xx];
    for (int i = 0; i < 50; i++)
        memo[l][r][xx] = 1e9;
    for (int mid = l; mid < r; mid++)
    {
        for (int fs = 0; fs < 50; fs++)
        {
            for (int ls = 0; ls < 50; ls++)
            {
                memo[l][r][fs * x + ls * y + z] = min(memo[l][r][(fs * x + ls * y + z) % 50], dp(l, mid, fs) + dp(mid + 1, r, ls) + ls * fs)
            }
        }
    }
    done[l][r] = 1;
    return memo[l][r][xx];
}
void solve()
{
    cin >> n >> x >> y >> z;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int ans = 1e9;
    for (int i = 0; i < 50; i++)
    {
        ans = min(ans, dp(0, n - 1, i));
    }
    cout << ans << endl;
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