#include <bits/stdc++.h>
using namespace std;
struct gg
{
    int to, cap, rew;
};
vector<gg> a[205];
bool used[2000005];
inline int dfs(int s, int to, int f)
{
    if (s == to)
    return f;
    used[s] = 1;
    for (int i = 0; i < a[s].size(); i++)
    {
        if (!used[a[s][i].to] && a[s][i].cap > 0)
        {
            int d = dfs(a[s][i].to, to, min(f, a[s][i].cap));
            if (d > 0)
            {
                a[s][i].cap -= d;
                a[a[s][i].to][a[s][i].rew].cap += d;
                return d;
            }
        }
    }
    return 0;
}
inline int max_flow(int s, int t)
{
    int flow = 0;
    while (1)
    {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, 2147483647);
        if (f == 0)
            return flow;
        flow += f;
    }
    return 0;
}
int main()
{
    int n, m, s, t, to, cw, from;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &from, &to, &cw);
        a[from].push_back((gg){to, cw, a[to].size()});
        a[to].push_back((gg){from, 0, a[from].size() - 1});
    }
    cout << max_flow(s,t);
}