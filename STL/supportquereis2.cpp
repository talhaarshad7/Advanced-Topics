//optimised version 1
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
struct myStructure
{
    multiset<int, greater<int>> m1, m2;
    int k, sum;
    myStructure(int kk)
    {
        k = kk;
        sum = 0;
    }
    void add(int x)
    {
        if (m1.size() < k)
        {
            sum += x;
            m1.insert(x);
        }
        else
        {
            sum += x;
            m1.insert(x);
            int c = *(m1.rbegin());
            m2.insert(c);
            m1.erase(m1.find(c));
            sum -= c;
        }
    }
    void remove(int x)
    {
        if (m2.find(x) != m2.end())
        {
            m2.erase(m2.find(x));
        }
        else if (m1.find(x) != m1.end())
        {
            sum -= x;
            m1.erase(m1.find(x));
            if (!m2.empty())
            {
                int c = *(m2.begin());
                m1.insert(c);
                sum += c;
                m2.erase(m2.find(c));
            }
        }
        return;
    }
    int getSum()
    {
        return sum;
    }
};
void solve()
{
    int q, k;
    cin >> q >> k;
    myStructure st(k);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            st.add(x);
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            st.remove(x);
        }
        else if (t == 3)
        {
            char ch;
            cin >> ch;
            cout << st.getSum() << endl;
        }
    }
}
int main()
{
    fast_cin();
    ll t;
    //cin >> t;
    for (int it = 1; it <= 1; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
