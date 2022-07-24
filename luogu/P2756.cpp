#include <bits/stdc++.h>
using namespace std;
int dep[105], iter[105], n, m, a1, b1;
struct gg
{
    int to, cap, rew;
};
vector<gg> fxy[105];
inline void bfs(int s)
{
    memset(dep, -1, sizeof(dep));
    queue<int> que;
    que.push(s);
    dep[s] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < fxy[now].size(); i++)
            if (dep[fxy[now][i].to] < 0 && fxy[now][i].cap > 0)
            {
                dep[fxy[now][i].to] = dep[now] + 1;
                que.push(fxy[now][i].to);
            }
    }
}
inline int dfs(int s, int to, int f)
{
    if (s == to)
        return f;
    for (int &i = iter[s]; i < fxy[s].size(); i++)
    {
        if (fxy[s][i].cap > 0 && dep[fxy[s][i].to] > dep[s])
        {
            int d = dfs(fxy[s][i].to, to, min(fxy[s][i].cap, f));
            if (d > 0)
            {
                fxy[s][i].cap -= d;
                fxy[fxy[s][i].to][fxy[s][i].rew].cap += d;
                return d;
            }
        }
    }
    return 0;
}
inline int max_flow(int s, int t)
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
            flow += f;
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    while (1)
    {
        scanf("%d%d", &a1, &b1);
        if (a1 == -1 && b1 == -1)
            break;
        fxy[a1].push_back((gg){b1, 1, fxy[b1].size()});
        fxy[b1].push_back((gg){a1, 0, fxy[a1].size() - 1});
    }
    for (int i = 1; i <= n; i++)
    {
        fxy[0].push_back((gg){i, 1, fxy[i].size()});
        fxy[i].push_back((gg){0, 0, fxy[0].size() - 1});
    }
    for (int i = n + 1; i <= m; i++)
    {
        fxy[i].push_back((gg){m + 1, 1, fxy[m + 1].size()});
        fxy[m + 1].push_back((gg){i, 0, fxy[i].size() - 1});
    }
    int jh, hj;
    printf("%d\n", max_flow(0, m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int b = 0; b < fxy[i].size(); b++)
            if(fxy[fxy[i][b].to][fxy[i][b].rew].cap>=1)
            cout<<i<<" "<<fxy[i][b].to<<endl;
    }
}