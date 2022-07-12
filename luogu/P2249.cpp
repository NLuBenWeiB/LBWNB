#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
const ll maxn = 1000005;
ll a[maxn];
ll findn(ll l, ll r, ll p)
{
    if (l == r && a[l] == p && a[l - 1] != a[l])
    {
        return l;
    }
    else if (l == r && a[l] == p && a[l - 1] == a[l])
    {
        return findn(l - 1, r - 1, p);
    }
    else if (l == r)
    {
        return -1;
    }
    ll mid = (l + r) / 2;
    if (p <=a[mid]){
        return findn(l, mid, p);
    }
    if (p > a[mid])
        return findn(mid + 1, r, p);
}
ll main()
{
    a[0] = -9999999;
    ll m, n, l;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%d", &l);
        printf("%d ", findn(1, n, l));
    }
}