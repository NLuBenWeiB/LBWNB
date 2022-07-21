#include <iostream>
using namespace std;
int dp[12][12][12][12], a[12][12], n, x, y, z;
int main()
{
    cin >> n >> x >> y >> z;
    while (x != 0 || y != 0 || z != 0)
    {
        a[x][y] = z;
        cin >> x >> y >> z;
    }
    for (int i = 1; i <= n; i++)
        for (int u = 1; u <= n; u++)
            for (int g = 1; g <= n; g++)
                for (int f = 1; f <= n; f++)
                {
                    dp[i][u][g][f] = max(max(dp[i - 1][u][g - 1][f], dp[i - 1][u][g][f - 1]), max(dp[i][u - 1][g - 1][f], dp[i][u - 1][g][f - 1])) + a[i][u] + a[g][f];
                    if (i == g && f == u)
                        dp[i][u][g][f] -= a[i][u];
                }
    cout << dp[n][n][n][n];
}