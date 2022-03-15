#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    IOS int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        stack<int> ss;
        int dp[n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                ss.push(i);
            }
            else
            {
                if (!ss.empty())
                {
                    int t = ss.top();
                    ss.pop();
                    if (t - 1 >= 0 && s[t - 1] == ')' && dp[t - 1] != -1)
                    {
                        dp[i] = dp[t - 1];
                    }
                    else
                    {
                        dp[i] = t;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] != -1)
            {
                ans = max(ans, i - dp[i] + 1);
            }
        }
        int x = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] != -1)
            {
                if (ans == i - dp[i] + 1)
                    x++;
            }
        }
        if (ans == 0)
            x = 1;
        cout << ans << " " << x << "\n";
    }
    return 0;
}