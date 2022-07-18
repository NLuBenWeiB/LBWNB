#include <bits/stdc++.h>
using namespace std;
int a[105][105], dp[105][105], zy[10] = {0, -1, 0, 1, 0};
int sx[10] = {0, 0, -1, 0, 1},maxn=-999;
int r, c;
bool used[105][105];
int dp1(int h, int l)
{
    if(used[h][l]==1)
    return dp[h][l];
    if(a[h+1][l]>a[h][l]&&a[h][l+1]>a[h][l]&&a[h-1][l]>a[h][l]&&a[h][l-1]>a[h][l])
    return dp[h][l];
    for (int i = 1; i <= 4; i++)
    {
        if (l + zy[i] >= 1 && l + zy[i] <= c && h + sx[i] >= 1 && h + sx[i] <= r && a[h + sx[i]][l + zy[i]] < a[h][l])
            dp[h][l] = max(dp1(h + sx[i], l + zy[i])+1, dp[h][l]);
    }
    used[h][l]=1;
    return dp[h][l];
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        a[i][0] = 999999;
    for (int i = 1; i <= c; i++)
        a[0][i] = 999999;
    for (int i = 1; i <= c; i++)
        a[r][i] = 999999;
    for (int i = 1; i <= r; i++)
        a[i][c] = 999999;
    for (int i = 1; i <= r; i++)
        for (int b = 1; b <= c; b++)
            scanf("%d", &a[i][b]);
    for (int i = 1; i <= r; i++)
        for (int b = 1; b <= c; b++){
        dp[i][b] = dp1(i, b);
        maxn=max(maxn,dp[i][b]);    
        }
    cout<<maxn+1;
}