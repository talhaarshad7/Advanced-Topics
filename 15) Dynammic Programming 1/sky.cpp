#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

int dp[101][101][11];

signed main()
{
    IOS int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n, q, c;
        cin >> n >> q >> c;
        for (int p = 0; p <= c; ++p)
        {
            for (int i = 0; i <= 100; ++i)
            {
                for (int j = 0; j <= 100; ++j)
                {
                    dp[i][j][p] = 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            int x, y, s;
            cin >> x >> y >> s;
            dp[x][y][s]++;
        }
        for (int p = 0; p <= c; ++p)
        {
            for (int i = 0; i <= 100; ++i)
            {
                for (int j = 0; j <= 100; ++j)
                {
                    dp[i][j][p] += dp[i - 1][j][p] + dp[i][j - 1][p] - dp[i - 1][j - 1][p];
                }
            }
        }
        while (q--)
        {
            int t, x1, y1, x2, y2;
            cin >> t >> x1 >> y1 >> x2 >> y2;
            int ans = 0;
            for (int i = 0; i <= c; ++i)
            {
                int cur = (i + t) % (c + 1);
                ans += (dp[x2][y2][i] - dp[x1 - 1][y2][i] - dp[x2][y1 - 1][i] + dp[x1 - 1][y1 - 1][i]) * cur;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}