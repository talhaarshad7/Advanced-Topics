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

int n, k;
int board[100][10];
int region[100][10];
int regsizes[1001];
void gravity()
{
    for (int i = 0; i < 10; i++)
    {
        int top = n - 1, bottom = n - 1;
        while (top >= 0)
        {
            while (top >= 0 && board[top][i] == 0)
                top--;
            // pr(i);
            if (top >= 0)
                board[bottom--][i] = board[top--][i];
        }
        while (bottom >= 0)
            board[bottom--][i] = 0;
    }
    // pr(5);
}
void visit(int i, int j, int r, int c)
{
    if (i >= n || i < 0 || j < 0 || j >= 10 || board[i][j] != c || region[i][j] != 0)
        return;
    region[i][j] = r;
    regsizes[r]++;
    visit(i + 1, j, r, c);
    visit(i - 1, j, r, c);
    visit(i, j + 1, r, c);
    visit(i, j - 1, r, c);
}
bool iterate()
{
    // pr(1);
    int r = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] && !region[i][j])
                visit(i, j, r++, board[i][j]);
        }
    }
    // pr(2);
    bool progress = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] && regsizes[region[i][j]] >= k)
            {
                board[i][j] = 0;
                progress = true;
            }
        }
    }
    // pr(3);
    gravity();
    // pr(6);
    while (r)
        regsizes[r--] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            region[i][j] = 0;
            // pr(i, j);
        }
    }
    // pr(7);
    return progress;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {

        string st;
        cin >> st;
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = st[j] - '0';
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (iterate())
        ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
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