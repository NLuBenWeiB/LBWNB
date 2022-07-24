#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int a[maxn], ansn = 99999999;
inline int dfs(int s, int t, int ans)
{
    if (s == t)
        return ans;
    for (int i = 1; i <= a[s]; i++)
        if (s + i <= t)
            ansn = min(ansn, dfs(s + i, t, ans + 1));
    return ansn;
}
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    int n, q, start, over, sc;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= q; i++)
    {
        ansn=99999999;
        scanf("%d%d%d", &start, &over, &sc);
        dfs(start, over, 0);
        cout <<ansn<< endl;
    }
}