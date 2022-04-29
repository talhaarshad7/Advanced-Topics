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
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, R;
char grid[1002][1002];
int region[1002][1002];
int area[1000000];
int perimeter[1000000];
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
void fill(int i, int j, int x)
{
    stack<pair<int, int>> s;
    s.push(make_pair(i, j));
    while (!s.empty())
    {
        pair<int, int> t = s.top();
        s.pop();
        i = t.first;
        j = t.second;
        if (grid[i][j] == '.' || region[i][j] != 0)
            continue;
        area[R]++;
        region[i][j] = R;
        for (int k = 0; k < 4; k++)
            s.push(make_pair(i + dx[k], j + dx[k]));
    }
}
void peri()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int r = region[i][j];
            if (r == 0)
                continue;
            if (region[i - 1][j] == 0)
                perimeter[r]++;
            if (region[i + 1][j] == 0)
                perimeter[r]++;
            if (region[i][j - 1] == 0)
                perimeter[r]++;
            if (region[i][j + 1] == 0)
                perimeter[r]++;
        }
    }
}
void solve()
{
    cin >> N;
    for (int i = 0; i <= N + 1; i++)
        grid[0][i] = grid[N + 1][i] = '.';
    for (int i = 1; i <= N; i++)
        grid[i][0] = grid[i][N + 1] = '.';

    for (int i = 1; i <= N; i++)
    {

        string st;
        cin >> st;
        for (int j = 1; j <= N; j++)
            grid[i][j] = st[j - 1];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (region[i][j] == 0 && grid[i][j] == '#')
                fill(i, j, ++R);
        }
    }
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    peri();
    int best_a = 0, best_p = 0;
    for (int i = 1; i <= R; i++)
        if (area[i] > best_a || (area[i] == best_a && perimeter[i] < best_p))
        {
            best_a = area[i];
            best_p = perimeter[i];
        }
    cout << best_a << " " << best_p << "\n";
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