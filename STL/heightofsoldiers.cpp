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

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int left[n];
    int right[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<pair<int, int>> s1, s2;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (!s1.empty() && s1.top().first > arr[i])
        {
            count += s1.top().second;
            s1.pop();
        }
        left[i] = count;
        s1.push({arr[i], count});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 1;
        while (!s2.empty() && s2.top().first >= arr[i])
        {
            count += s2.top().second;
            s2.pop();
        }
        right[i] = count;
        s2.push({arr[i], count});
    }
    for (int i = 0; i < n; i++)
        cout << left[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << right[i] << " ";
    cout << endl;

    int ans[n] = {};
    for (int i = 0; i < n; i++)
    {
        ans[left[i] + right[i] - 2] = max(ans[left[i] + right[i] - 2], arr[i]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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