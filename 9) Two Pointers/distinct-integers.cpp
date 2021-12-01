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
int freq[1000100];
int cnt = 0;
void insert(int x)
{
    freq[x]++;
    if (freq[x] == 1)
        cnt++;
}
void remove(int x)
{
    freq[x]--;
    if (freq[x] == 0)
        cnt--;
}
int countAtMostK(int a[], int n, int k)
{
    int head = -1;
    int tail = 0;
    int ans = 0;
    while (tail < n)
    {
        while ((head + 1) < n && ((cnt < k && freq[a[head + 1]] == 0) || (cnt <= k && freq[a[head + 1]] > 0)))
        {
            head++;
            insert(a[head]);
        }
        ans += head - tail + 1;
        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            remove(tail);
            tail++;
        }
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = countAtMostK(a, n, k);
    for (int i = 0; i < 1000100; i++)
        freq[a[i]] == 0;
    cnt = 0;
    // ans -= countAtMostK(a, n, k - 1);
    cout << ans << endl;
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