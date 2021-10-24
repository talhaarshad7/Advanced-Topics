// Description

// Your class teacher wrote N integers on the board. One of your classmates was being mischievous, he replaced the N integers with all possible subset sums of the array when the teacher was not in the class.
// Suppose that the integers on the board were [2,1] then the subsets will be: {}, {2}, {1}, {2,1} and the subset sums will be: {0,2,1,3}.
// Your task is to rebuild the original array given by your teacher.

// Input Format

// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
// The first line of each test case contains one integer N - the number of elements in the initial array.
// The second line of each test case contains 2N space-separated integers, the new values on the board.

// Output Format

// For each test case, print N space-separated integers in non-decreasing order.
// It is guaranteed that a solution always exists.

// Constraints

// 1 ≤ T ≤ 50
// 1 ≤ N ≤ 15
// 0 ≤ Ai ≤ 1015

// Sample Input 1
// 3

// 2

// 0 1 2 3

// 3

// 0 1 3 4 5 6 8 9

// 3

// 0 1 1 1 2 2 2 3

// Sample Output 1
//  Copy

// 1 2

// 1 3 5

// 1 1 1

// Note

// In the first test case of the example, the original array is [1,2] which has the following subset - {}, {1}, {2}, {1,2}. Their respective sums are 0,1,2,3.

// In the third test case of the example, the original array is [1,1,1] which has the following subset - {}, {1}, {1}, {1}, {1,1}, {1,1}, {1,1}, {1,1,1}. Their respective sums are 0,1,1,1,2,2,2,3.

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
    int n;
    cin >> n;
    n = n << 1;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans;
    vector<long long> subsums;
    map<int, int> sums;
    sums[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (sums[arr[i]])
            sums[arr[i]]--;
        else
        {
            ans.push_back(arr[i]);
            vector<long long> temp;
            for (auto j : subsums)
            {
                temp.push_back(j + arr[i]);
                sums[j + arr[i]]++;
            }
            for (auto j : temp)
            {
                subsums.push_back(j);
            }
            subsums.push_back(arr[i]);
        }
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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