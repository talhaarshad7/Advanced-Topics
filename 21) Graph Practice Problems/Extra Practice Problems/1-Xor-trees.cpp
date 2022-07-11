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
vector<vector<int>> adj;
int n;
vector<int> ans;
vector<int> init;
int dfs(int curr, int f, int g, int pre)
{
    if (f ^ init[curr])
    {
        f ^= 1;
        ans.push_back(curr);
    }
    for (auto u : adj[curr])
    {
        if (u != pre)
        {
            dfs(u, g, f, curr);
        }
    }
}

void solve()
{
    // pr(1);
    cin >> n;
    // pr(n);
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        // pr(i);
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // pr(i);
        adj[y].push_back(x);
    }

    // pr(adj);
    init.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> init[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        init[i] ^= x;
    }
    dfs(1, 0, 0, 0);
    int nn = ans.size();
    cout << nn << endl;
    // pr(init);
    for (int i = 0; i < nn; i++)
        cout << ans[i] << endl;
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