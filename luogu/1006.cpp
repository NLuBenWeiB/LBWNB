#include <bits/stdc++.h>
using namespace std;
int n, m,map1[55][55], dp[55][55][55][55];
int main()
{
    cin >> n>>m;
    for (int i = 1; i <= n; i++)
        for (int b = 1; b <= m; b++)
            cin >> map1[i][b];
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= m; b++)
            for (int c = 1; c <= n; c++)
                for (int d = 1; d <= m; d++)
                {
                    dp[a][b][c][d] = max(max(dp[a - 1][b][c - 1][d], dp[a - 1][b][c][d - 1]), max(dp[a][b - 1][c - 1][d], dp[a][b - 1][c][d - 1])) + map1[a][b] + map1[c][d];
                    if(a==c&&b==d)
                    dp[a][b][c][d]-=map1[a][b];
                }
    cout << dp[n][m][n][m];
}