#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define ll long long
const ll maxn = 100005;
ll a[maxn * 4], ans[maxn * 4];
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
inline ll ls(ll p)
{
    return p * 2;
}
inline ll rs(ll p)
{
    return p * 2 + 1;
}
inline void push_up(ll p)
{
    ans[p] = max(ans[ls(p)], ans[rs(p)]);
}
inline void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        ans[p] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}
ll query(ll q_x, ll q_y, ll l, ll r, ll p)
{
    ll res = -999;
    if (q_x <= l && r <= q_y)
        return ans[p];
    ll mid = (l + r) >> 1;
    if (q_x <= mid)
        res = max(res, query(q_x, q_y, l, mid, ls(p)));
    if (q_y > mid)
        res = max(res, query(q_x, q_y, mid + 1, r, rs(p)));
    return res;
}
int main()
{
    ll n, m, l1, r1;
    n = read();
    m = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        l1 = read();
        r1 = read();
        printf("%lld\n", query(l1, r1, 1, n, 1));
    }
}