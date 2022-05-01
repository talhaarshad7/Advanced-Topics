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
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cerr << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}
int n, m;
bool grid[1010][1010];
queue<pair<int, int>> mon, a;
int disa[1010][1010];
int dismon[1010][1010];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void solve()
{
    cin >> n >> m;
    memset(grid, false, sizeof(grid));

    memset(dismon, -1, sizeof(dismon));
    memset(disa, -1, sizeof(disa));
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = true;
            if (st[j] == '#')
                grid[i][j] = false;
            if (st[j] == 'M')
            {
                mon.push({i, j});
                dismon[i][j] = 0;
            }
            if (st[j] == 'A')
            {
                a.push({i, j});
                disa[i][j] = 0;
            }
        }
    }
    while (!mon.empty())
    {
        auto t = mon.front();
        mon.pop();
        int x = t.first;
        int y = t.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (grid[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m && dismon[nx][ny] == -1)
            {
                dismon[nx][ny] = dismon[x][y] + 1;
                mon.push({nx, ny});
            }
        }
    }
    while (!a.empty())
    {
        auto t = a.front();
        a.pop();
        int x = t.first;
        int y = t.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (grid[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m && disa[nx][ny] == -1)
            {
                disa[nx][ny] = disa[x][y] + 1;
                a.push({nx, ny});
            }
        }
    }
    int finx = -1, finy = -1, findist = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] && disa[i][0] >= 0 && (disa[i][0] < dismon[i][0]))
        {
            finx = i;
            finy = 0;
            findist = min(findist, disa[i][0]);
        }
        if (grid[i][m - 1] && disa[i][m - 1] >= 0 && (disa[i][m - 1] < dismon[i][m - 1]))
        {
            finx = i;
            finy = m - 1;
            findist = min(findist, disa[i][m - 1]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] && disa[0][i] >= 0 && (disa[0][i] < dismon[0][i]))
        {
            finx = 0;
            finy = i;
            findist = min(findist, disa[0][i]);
        }
        if (grid[n - 1][i] && disa[n - 1][i] >= 0 && (disa[n - 1][i] < dismon[n - 1][i]))
        {
            finx = n - 1;
            finy = i;
            findist = min(findist, disa[n - 1][i]);
        }
    }
    // debmat(disa, n, m);
    if (finx == -1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << findist << endl;
    }
}
int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    for (int it = 1; it <= 1; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}