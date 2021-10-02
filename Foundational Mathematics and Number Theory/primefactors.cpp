#include <bits/stdc++.h>
using namespace std;
vector<long long> getPrimeFactors(long long n)
{
    vector<long long> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n /= 2;
    }
    for (int i = 3; i < sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
        ans.push_back(n);
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> factors = getPrimeFactors(n);
    for (auto i : factors)
        cout << i << " ";
}