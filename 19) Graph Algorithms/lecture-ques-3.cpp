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


vector<string> arr;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int n, m;
vector<vector<int>> dist;
vector<vector<pair<int,int>>> par;
bool check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#')
    return 1;
    return 0;
}
void ppath(pair<int,int> en)
{
    if(en==make_pair(-1,-1))
    return;
    ppath(par[en.first][en.second]);
    cout<<en.first<<" "<<en.second<<endl;
}
void bfs(pair<int,int> st)
{
    queue<pair<int,int>> q;
    dist[st.first][st.second]=0;
    par[st.first][st.second]={-1,-1};
    q.push(st);
    while(!q.empty())
    {
        auto pos=q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            if(check(pos.first+dx[k],pos.second+dy[k])&&
                     dist[pos.first+dx[k]][pos.second+dy[k]]>dist[pos.first][pos.second]+1)
                {
                    dist[pos.first + dx[k]][pos.second + dy[k]] = dist[pos.first][pos.second] + 1;
                    par[pos.first + dx[k]][pos.second + dy[k]] = {pos.first,pos.second};
                    q.push({pos.first + dx[k], pos.second + dy[k]});
                }
        }
    }
}

void solve()
{
    cin>>n>>m;
    arr.clear();
    arr.resize(n);
    dist=vector<vector<int>>(n,vector<int>(m,1e9));
    par=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m,{0,0}));
    for(int i=0;i<n;i++)
    cin>>arr[i];

    pair<int,int> st,en;
    cin>>st.first>>st.second;
    cin>>en.first>>en.second;
    bfs(st);
    // pr(dist);
    pr(arr);
    cout<<dist[en.first][en.second]<<endl;
    pr(st,en);
    pr(dist[en.first]);
    ppath(en);
}
int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t=1;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}