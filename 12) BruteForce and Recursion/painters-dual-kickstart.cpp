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
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
int s, ra, pa, rb, pb, c;
int allowed[10][10];
bool check(int a, int b)
{
    if ((a >= 1) && (b >= 1) && (a <= s) && (b <= 2 * s - 1) && (allowed[a][b] == 0))
        return true;
    return false;
}
int getBest(int a, int b, int x, int y)
{
    vector<pair<int, int>> move1, move2;
    if (check(a, b - 1))
    {
        move1.emplace_back(make_pair(a, b - 1));
    }
    if (check(a, b + 1))
    {
        move1.emplace_back(make_pair(a, b + 1));
    }
    if (b % 2 == 0)
    {
        if (check(a - 1, b - 1))
            move1.emplace_back(make_pair(a - 1, b - 1));
    }
    else
    {
        if (check(a + 1, b + 1))
            move1.emplace_back(make_pair(a + 1, b + 1));
    }
    if (check(x, y - 1))
    {
        move2.emplace_back(make_pair(x, y - 1));
    }
    if (check(x, y + 1))
    {
        move2.emplace_back(make_pair(x, y + 1));
    }
    if (y % 2 == 0)
    {
        if (check(x - 1, y - 1))
            move2.emplace_back(make_pair(x - 1, y - 1));
    }
    else
    {
        if (check(x + 1, y + 1))
            move2.emplace_back(make_pair(x + 1, y + 1));
    }
    if (move1.empty() == true && move2.empty() == true)
        return 0;
    if (!move1.empty())
    {
        int best = -1000;
        for (auto &i : move1)
        {
            allowed[i.first][i.second] = 1;
            best = max(best, 1 - getBest(x, y, i.first, i.second));
            allowed[i.first][i.second] = 0;
        }
        return best;
    }
    else
        return -getBest(x, y, a, b);
}
void solve()
{
    cin >> s >> ra >> pa >> rb >> pb >> c;
    memset(allowed, 0, sizeof(allowed));
    allowed[ra][pa] = 1;
    allowed[rb][pb] = 1;
    for (int i = 0; i < c; i++)
    {
        int x, y;
        cin >> x >> y;
        allowed[x][y] = 1;
    }
    cout << getBest(ra, pa, rb, pb) << endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}