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
int a[100100];
int check1(int x)
{
    return a[x - 1] < a[x];
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int lo = 1, hi = n - 1;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check1(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    while (q--)
    {
        int lo1 = 0, hi1 = ans - 1, lo2 = ans, hi2 = n - 1;
        int k;
        cin >> k;
        while (lo1 <= hi1)
        {
            int mid = (lo1 + hi1) / 2;
            int ans1 = -1;
            if (a[mid] == k)
            {
                cout << mid + 1 << " ";
                lo1 = mid + 1;
            }
            else if (a[mid] > k)
            {
                hi1 = mid - 1;
            }
            else
            {
                lo1 = mid + 1;
            }
        }
        while (lo2 <= hi2)
        {
            int mid = (lo2 + hi2) / 2;
            if (a[mid] == k)
            {
                cout << mid + 1 << " ";
                break;
            }
            else if (a[mid] > k)
            {
                lo2 = mid + 1;
            }
            else
            {
                hi2 = mid - 1;
            }
        }
        cout << endl;
    }
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