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

string solve()
{
    int n, d;
    cin >> n >> d;
    string ans = "";
    if (n == 0)
    {
        return "0";
    }
    else if (n % d == 0)
    {
        return to_string(n / d);
    }
    else
    {
        bool isNeg = false;
        if (d < 0)
            isNeg ^= 1;
        if (n < 0)
            isNeg ^= 1;
        if (isNeg)
            ans = "-";
        n = abs(n);
        d = abs(d);
        int dig = n / d;
        n %= d;
        ans += to_string(dig);
        if (n == 0)
            cout << ans << endl;
        ans += ".";
        unordered_map<int, int> decpos;
        int recpos = -1;
        while (true)
        {
            if (n == 0)
            {
                return ans;
            }
            long long temp = n * 10;
            if (decpos.find(n) != decpos.end())
            {
                recpos = decpos[n];
                break;
            }
            decpos[n] = ans.length();
            int intPart = temp / d;
            ans += to_string(intPart);
            n = temp % d;
        }
        if (recpos != -1)
        {
            return ans.substr(0, recpos) + "(" + ans.substr(recpos, ans.length() - recpos) + ")";
        }
        return ans;
    }
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}
