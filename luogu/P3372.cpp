#include <iostream>
#include <cstdio>
using namespace std;
const ll maxn = 100005;
#define ll long long
ll a[maxn], lazy[maxn * 4], ans[maxn * 4], n, m, cz;
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
    ans[p] += ans[ls(p)] + ans[rs(p)];
}
inline void build(ll p, ll l, ll r)
{
    if (l == r)
        ans[p] = a[p];
    ll mid = (l + r) / 2;
    build(p, l, mid);
    build(p, mid + 1, r);
    push_up(p);
}
inline void xs(ll p,ll k,ll r,ll l){
    lazy[p]+=k;
    ans[p]+=k*(r-l+1); 
}
inline void push_down(ll p,ll l,ll r){
    ll mid=(r+l)/2;
    xs(p,lazy[p],mid,l);
    xs(p,lazy[p],r,mid+1);
    lazy[p]=0;
}
inline void up_date(ll nl,ll nr,ll l,ll r,ll k,ll p){
     if(nl<=l&&)
}
inline 
ll main()
{
    ll a,b,c,d,e;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
    build(1,1,n);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld", &cz);
        if (cz == 1)
        {
            scanf("%d%d%d",&a,&b,&c);
            up_date(a,b,1,n,c,1);
        }
        else if (cz == 2)
        {
            scanf("%d%d",&d,&e);
            query(d,e,1,r,1);
        }
    }
}