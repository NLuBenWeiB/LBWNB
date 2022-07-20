#include <bits/stdc++.h>
using namespace std;
bool used[2000][2000];
int dp[2000][2000];
inline int cj(int m, int n)
{
    if (n == 0)
        return 0;
    if (m == 0)
        return 1;
    if(used[m][n]==1)
    return dp[m][n];
    used[m][n]=1;
    dp[m][n]=cj(m, n - 1) + cj(m - 1, n - 1);
    return dp[m][n];
}
int main()
{
    int t, k, c = 0, g = 0, a1, b1;
    cin >> t >> k;
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d", &a1, &b1);
        for (int f = 0; f <= b1; f++)
            for (int o = 1; o <= f; o++)
            {
                c = cj(o, f);
                if (c!=0&& c % k == 0)
                    g++;
            }
    cout << g << endl;
    g = 0;
    }
    
}