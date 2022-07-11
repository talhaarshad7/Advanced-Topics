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
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
ll mod = 1e9 + 7;
double eps = 1e-12;
#define ln "\n"
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define dbg(x) cout << #x << " = " << x << ln
#define INF 2e18

void solve()
{
    ll n;
    cin >> n;
    set<pair<int, ll>> s;
    for (int i = 0; i < n; i++)
    {
        ll x, ox;
        cin >> x;
        ox = x;
        int c = 0;
        while (x % 3 == 0)
        {
            c++;
            x /= 3;
        }
        s.insert({-c, ox});
    }
    for (auto i : s)
        cout << i.second << " ";
}
int main()
{
    fast_cin();
    long long t;
    // cin >> t;
    for (int it = 1; it <= 1; it++)
    {
        solve();
    }
    return 0;
}