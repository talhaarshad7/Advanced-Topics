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
int ans = 0;
bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void calc(int cur, int totalLen, int curLen, int a, int b)
{
    if (curLen == (totalLen + 1) / 2)
    {
        int temp = cur;
        vector<int> d;
        while (temp)
        {
            d.push_back(temp % 10);
            temp /= 10;
        }
        temp = cur;
        for (int i = (totalLen % 2); i < (int)d.size(); i++)
        {
            temp *= 10;
            temp += d[i];
        }
        if (temp >= a && temp <= b && isPrime(temp))
            ans++;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        cur *= 10;
        cur += i;
        calc(cur, totalLen, curLen + 1, a, b);
        cur /= 10;
    }
    return;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int len = 0;
    int temp = b;
    while (temp)
    {
        len++;
        temp /= 10;
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            calc(j, i, 1, a, b);
        }
    }
    cout << ans << endl;
}
int main()
{
    fast_cin();
    ll t;
    for (int it = 1; it <= 1; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}