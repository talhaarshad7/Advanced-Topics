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
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
struct ST
{
    int msum, rsum, lsum, tsum;
    ST(int msum = 0, int rsum = 0, int lsum = 0, int tsum = 0) : msum(msum), rsum(rsum), lsum(lsum), tsum(tsum) {}
};
ST operator+(const ST &A, const ST &B)
{
    ST temp;
    temp.msum = max(A.rsum + B.lsum, max(A.msum, B.msum));
    temp.lsum = max(A.tsum + B.lsum, A.lsum);
    temp.rsum = max(B.tsum + A.rsum, B.rsum);
    temp.tsum = A.tsum + B.tsum;
    return temp;
}
struct segtree
{
    vector<ST> tree;
    segtree(int n = 100100)
    {
        tree.resize(n * 4);
    }
    void update(int i, int l, int r, int pos, int val)
    {
        // cout << 1 << endl;
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            int x = max(0, val);
            tree[i] = ST(x, x, x, val);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * i, l, mid, pos, val);
        update(2 * i + 1, mid + 1, r, pos, val);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    ST query(int i, int l, int r, int lq, int rq)
    {
        if (l > rq || r < lq)
            return ST();
        if (l >= lq && r <= rq)
            return tree[i];
        int mid = (l + r) >> 1;
        return query(i << 1, l, mid, lq, rq) + query(i << 1 | 1, mid + 1, r, lq, rq);
    }
};

void solve()
{
    int n, q;
    cin >> n;
    segtree T(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        T.update(1, 0, n - 1, i, x);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        // pr(i);
        int ch;
        cin >> ch;
        if (ch == 0)
        {
            int pos, val;
            cin >> pos >> val;
            T.update(1, 0, n - 1, pos-1, val);
        }
        else if (ch == 1)
        {
            int l, r;
            cin >> l >> r;
            if(l==r)
            cout<<
            cout << T.query(1, 0, n - 1, l-1, r-1).msum << endl;
        }
    }
}
int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}