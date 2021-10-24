#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool isPrime(int n)
{
    //optimized again
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
    bool prime[n + 1];
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (prime[i])
            count++;
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
