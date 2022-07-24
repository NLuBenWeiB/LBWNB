#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n, m;
long double ans = 0;
inline unsigned long long ksm(long long a, long long b, long long p)
{
    if (b == 0)
        return 1;
    long long res = ksm(a, b / 2, p);
    if (b % 2)
        return res * res % p * a % p;
    else
        return res * res % p;
}
inline long double dfs(int l, int r, long double gl)
{
    if (l >= n)
        return gl;
    if (r >= m)
        return 0;
    ans += dfs(l + 1, r, gl / 2);
    ans += dfs(l, r + 1, gl / 2);
    return 0;
}
int main()
{
    // freopen("ball.in", "r", stdin);
    // freopen("ball.out", "w", stdout);
    scanf("%d%d", &n, &m);
    dfs(0, 0, 1);
    cout << ans * ksm(2, n + m - 1, 998244353);
}