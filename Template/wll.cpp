#include <bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
struct edge
{
    ll to, cap, rew;
};
vector<edge> a[1205];
ll dep[1205], iter[1205];
inline void bfs(re ll s)
{
    memset(dep, -1, sizeof(dep));
    queue<ll> que;
    dep[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        re ll now = que.front();
        que.pop();
        for (re ll i = 0; i < a[now].size(); i++)
        {
            edge &e = a[now][i];
            if (e.cap > 0 && dep[e.to] < 0)
            {
                dep[e.to] = dep[now] + 1;
                que.push(e.to);
            }
        }
    }
}
inline ll dfs(re ll s,re ll t,re ll f)
{
    if (s == t)
        return f;
    for (ll &i = iter[s]; i < a[s].size(); i++)
    {
        edge &q = a[s][i];
        if (q.cap > 0 && dep[q.to] > dep[s])
        {
            ll d = dfs(q.to, t, min(f, q.cap));
            if (d > 0)
            {
                q.cap -= d;
                a[q.to][q.rew].cap += d;
                return d;
            }
        }
    }
    return 0;
}
inline ll maxdd(re ll s,re ll t)
{
    re ll flow = 0;
    for (;;)
    {
        bfs(s);
        if (dep[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        re ll f;
        while ((f = dfs(s, t, 2147483647)) > 0)
        {
            flow += f;
        }
    }
}
int main()
{
    re ll n, m, s, t, fr, to, ca;
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (re ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &fr, &to, &ca);
        a[fr].push_back((edge){to, ca, a[to].size()});
        a[to].push_back((edge){fr, 0, a[fr].size()-1});
    }
    printf("%lld", maxdd(s, t));
}