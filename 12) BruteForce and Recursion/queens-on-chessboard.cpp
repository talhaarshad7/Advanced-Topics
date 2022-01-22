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

vector<int> placed;
int ans;
map<pair<int, int>, int> m;
void rec(int row)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        bool safe = 1;
        if (m[make_pair(row, col)] > 0)
        {
            safe = 0;
        }
        else
        {
            for (int prow = 0; prow < row; prow++)
            {
                int pcol = placed[prow];
                if (col == pcol || abs(row - prow) == abs(col - pcol))
                    safe = 0;
            }
        }
        if (safe)
        {
            placed.push_back(col);
            rec(row + 1);
            placed.pop_back();
        }
    }
}

void solve()
{
    vector<string> s;
    for (int i = 0; i < 8; i++)
    {
        string st;
        cin >> st;
        s.push_back(st);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (s[i][j] == '*')
            {
                m[make_pair(i, j)]++;
            }
        }
    }
    rec(0);
    cout << ans << endl;
}
int main()
{
    fast_cin();
    ll t;

    //cout << "Case #" << it+1 << ": ";
    solve();

    return 0;
}