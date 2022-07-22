#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
struct gg
{
    int to, cap, rew;
};
vector<gg> g[205];
int dep[maxn],iter[maxn];
inline void bfs(int s)
{
    memset(dep, -1, sizeof(dep));
    queue<int> que;
    dep[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int i = 0; i < g[v].size(); i++)
        {
            gg &e = g[v][i];
            if(e.cap>0&&dep[e.to]<0){
                dep[e.to]=dep[v]+1;
                que.push(e.to);
            }
        }
    }
}
inline void add(int from, int to, int cap)
{
    g[from].push_back((gg){to, cap, g[to].size()});
    g[to].push_back((gg){from, 0, g[from].size() - 1});
}
inline int dfs(int s, int t, int f)
{
    if (s == t)
        return f;
    for (int i = iter[s]; i < g[s].size(); i++)
    {
        gg &k = g[s][i];
        if (k.cap > 0&&dep[s]<dep[k.to])
        {
            int d = dfs(k.to, t, min(f, k.cap));
            if (d > 0)
            {
                k.cap -= d;
                g[k.to][k.rew].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int maxa(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        bfs(s);
        memset(iter, 0, sizeof(iter));
        int f;
        while(f=dfs(s,t,9999999)>0)
        flow+=f;
    }
    return flow;
}
int main()
{
    int n, m, s, t, fr, too, w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &fr, &too, &w);
        add(fr, too, w);
    }
    cout << maxa(s, t);
}