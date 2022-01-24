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

inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % mod);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a)
{
    a %= mod;
    if (a < 0)
        a += mod;
    int b = mod, u = 0, v = 1;
    while (a)
    {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0)
        u += mod;
    return u;
}

const int N = 200010;

int fact[N];

void pre()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    return;
}
int prime[10000001];
void pre2()
{
    for (int i = 2; i < 10000001; i++)
        prime[i] = i;
    for (int i = 2; i < 10000001; i++)
    {
        if (prime[i] == i)
        {
            for (int j = 2 * i; j < 10000001; j += i)
            {
                if (prime[j] == j)
                    prime[j] = i;
            }
        }
    }
}
void solve()
{
    pre2();
    int n;
    cin >> n;
    unordered_map<int, int> m1;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        unordered_map<int, int> m2;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            while (x > 1)
            {
                m2[prime[x]]++;
                x /= prime[x];
            }
        }
        if (i == 0)
            m1 = m2;
        else
        {
            for (auto it : m1)
            {
                m1[it.first] = min(m1[it.first], m2[it.first]);
            }
        }
    }
    int ans = 1;
    for (auto i : m1)
    {
        ans = mul(ans, power(i.first, i.second));
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