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
bool isPrime(long long x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
vector<long long> divisors(long long x)
{
    vector<long long> ans;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i * i != x)
            {
                ans.push_back(x / i);
            }
        }
    }
    return ans;
}
vector<pair<long, long>> factors(long long x)
{
    vector<pair<long, long>> ans;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if (x > 1)
        ans.push_back({x, 1});
    return ans;
}

void solve()
{
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}