#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int a[maxn], ans[maxn], num[maxn];
inline void csh()
{
    for (int i = 1; i <= maxn - 5; i++)
    {
        a[i] = i;
        ans[i] = 0;
        num[i] = 1;
    }
}
inline int findn(int x)
{
    if (a[x] == x)
        return x;
    int fn = findn(a[x]);
    ans[x] += ans[a[x]];
    return a[x] = fn;
}
int main()
{
    int t, x, y;
    char cz;
    cin >> t;
    csh();
    for (int i = 1; i <= t; i++)
    {
        cin >> cz;
        scanf("%d%d", &x, &y);
        int fx = findn(x), fy = findn(y);
        if (cz == 'M')
        {
            ans[fx] += num[fy];
            a[fx] = fy;
            num[fy] += num[fx];
            num[fx] = 0;
        }
        if (cz == 'C')
        {
            if (fx != fy)
                cout << -1 << endl;
            else
                cout << abs(ans[y] - ans[x]) - 1 << endl;
        }
    }
}