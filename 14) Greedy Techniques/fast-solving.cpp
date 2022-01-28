#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> ratings(n + 2);

        for (i = 1; i <= n; i++)
            cin >> ratings[i];

        ratings[0] = ratings[n + 1] = 2e9;

        vector<pair<int, int>> v;

        for (i = 1; i <= n; i++)
            v.push_back({ratings[i], i});
        sort(v.begin(), v.end());

        vector<int> minutes(n + 2, 0);

        long long ans = 0;
        for (auto z : v)
        {
            int idx = z.second;
            int give = 1;
            if (ratings[idx] > ratings[idx - 1])
                give = max(give, minutes[idx - 1] + 1);

            if (ratings[idx] > ratings[idx + 1])
                give = max(give, minutes[idx + 1] + 1);

            minutes[idx] = give;
            ans += give;
        }
        cout << ans << '\n';
    }
}