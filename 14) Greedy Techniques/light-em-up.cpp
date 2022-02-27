Copy
#include <bits/stdc++.h>
    using namespace std;

int main()
{
    int t, i, j;

    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> n >> k;
        vector<int> A(n);
        bool zero = 0;
        for (i = 0; i < n; i++)
        {
            cin >> A[i];
            if (A[i] == 0)
                zero = 1;
        }

        if (k == 0)
        {
            if (zero)
                cout << "-1\n";
            else
                cout << "0\n";
            continue;
        }

        vector<bool> change(n + 1, 0);
        int ans = 0;
        bool flip = 0, ok = 1;

        for (i = 0; i < n; i++)
        {
            flip ^= change[i];
            if ((A[i] ^ flip) == 0)
            {
                if (i + k - 1 < n)
                {
                    ans++;
                    flip ^= 1;
                    change[i + k] = change[i + k] ^ 1;
                }
                else
                    ok = 0;
            }
        }

        if (!ok)
            ans = -1;
        cout << ans << "\n";
    }
}