// Description

// You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
// Find the sum of the minimum of all subarrays possible of array A.

// Input Format

// The first line contains T, the number of test cases.
// The first line of each test case contains N, the number of integers in an array A.
// The second line of each test case contains N space-separated integers A1, A2, ..., AN.

// Output Format

// For each test case, print a single number representing the sum of the minimum of all subarrays of A.

// Constraints

// 1 ≤ T ≤ 100000
// 1 ≤ N ≤ 100000
// 1 ≤ Ai ≤ 106
// Sum of N over all test cases ≤ 5 * 105.
// It is guaranteed that all elements in an array A are distinct.

// Sample Input 1
// 5
// 3
// 1 2 3
// 2
// 1 5
// 4
// 2 3 4 10
// 8
// 1000000 1000001 1000002 1000003 1000004 1000005 1000006 1000007
// 3
// 3 1 2
// Sample Output 1
//  Copy

// 10
// 7
// 35
// 36000084
// 9
// Note

// Explanation 1:
// Min{1} + Min{1, 2} + Min{1, 2, 3} + Min{2} + Min{2, 3} + Min{3} = 1 + 1 + 1 + 2 + 2 + 3 = 10

// Explanation 2:
// Min{1} + Min{1, 5} + Min{5} = 1 + 1 + 5 = 7
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

void solve()
{
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}