#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to, cap, w;
};
vector<edge> a[1205];
int dep[1205], iter[1205];
inline void bfs(int s)
{
    memset(dep, -1, sizeof(dep));
    queue<int> que;
    dep[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < a[now].size(); i++)
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
inline int dfs(int s, int t, int f)
{
    if (s == t)
        return f;
    for (int &i = iter[s]; i < a[s].size(); i++)
    {
        edge &q = a[s][i];
        if (q.cap > 0 && dep[q.to] > dep[s])
        {
            int d = dfs(q.to, t, min(f, q.cap));
            if (d > 0)
            {
                q.cap -= d;
                a[q.to][q.w].cap += d;
                return d;
            }
        }
    }
    return 0;
}
inline int maxdd(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        bfs(s);
        if (dep[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, 2147483647)) > 0)
        {
            flow += f;
        }
    }
}
int main()
{
    int f, n, d, snum, ynum, food, drink;
    cin >> n >> f >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> snum >> ynum;
        for (int y = 1; y <= snum; y++)
        {
            cin >> food;
            a[food].push_back((edge){i + f, 1, a[i + f].size()});
            a[i + f].push_back((edge){food, 0, a[food].size() - 1});
        }
        a[i + f].push_back((edge){i + f + n, 1, a[i + f + n].size()});
        a[i + f + n].push_back((edge){i + f, 0, a[i + f].size() - 1});
        for (int y = 1; y <= ynum; y++)
        {
            cin >> drink;
            a[i + f + n].push_back((edge){drink + f + n + i, 1, a[i + f + n + drink].size()});
            a[i + f + n + drink].push_back((edge){i + f + n, 0, a[i + f + n].size() - 1});
        }
    }
    for (int p = 1; p <= f; p++)
    {
        a[0].push_back((edge){p, 1, a[p].size()});
        a[p].push_back((edge){0, 0, a[0].size() - 1});
    }
    for (int p = 1; p <= d; p++)
    {
        a[p + n + n + f].push_back((edge){n + d + f + n + 1, 1, a[n + d + f + n + 1].size()});
        a[n + d + f + n + 1].push_back((edge){p + n + n + f, 0, a[p + n + n + f].size() - 1});
    }
    cout << endl;
    for (int i = 0; i <= n + n + f + d + 1; i++)
    {
        for (int op = 0; op < a[i].size(); op++)
            cout << a[i][op].to << " ";
        cout << endl;
    }
    // cout<<maxdd(0,n + n + f + d + 1);
}