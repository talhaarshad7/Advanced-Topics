#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool isPrime(int n)
{
    int c = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                c += 1;
            else
                c += 2;
        }
    }
    if (c == 2)
        return true;
    else
        return false;
}
void solve()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
            count += 1;
    }
    cout << count << endl;
}
int main()
{
    int testcase;
    //   cin>>testcase;
    testcase = 1;
    while (testcase--)
        solve();
}