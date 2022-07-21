#include <bits/stdc++.h>
using namespace std;
int n, a[500005], m, cz, x, k, ans[2000005];
map<int, int> xg;
inline void push_up(int p)
{
    ans[p] = ans[p * 2] + ans[p * 2 + 1];
}
inline void build(int l, int r, int p)
{
    if (l == r)
    {
        xg[l] = p;
        ans[p] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    push_up(p);
}
inline void wh(int x, int k)
{
    if (x == 1)
        return;
    ans[x] += k;
    if (x % 2 == 1)
        wh((x - 1) / 2, k);
    else
        wh(x / 2, k);
}
inline int cx(int l, int r, int nl, int nr, int p)
{
    int ans1 = 0;
    if (nl <= l && nr >= r)
        return ans[p];
    int mid = (l + r) / 2;
    if (nl <= mid)
        ans1 += cx(l, mid, nl, nr, p * 2);
    if (nr > mid)
        ans1 += cx(mid + 1, r, nl, nr, p * 2 + 1);
    return ans1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(0, n, 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &cz, &x, &k);
        if (cz == 1)
            wh(xg[x], k);
        if (cz == 2)
            cout << cx(0, n, x, k, 1) << endl;
    }
}