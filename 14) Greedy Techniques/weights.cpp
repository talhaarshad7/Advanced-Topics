#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<long long> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());

        arr.push_back(LLONG_MAX);
        if (arr[0] != 1)
        {
            cout << "1\n";
            continue;
        }

        long long sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum + 1 < arr[i + 1])
            {
                cout << sum + 1 << '\n';
                break;
            }
        }
    }