#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct edge
{
    int v, w;
};
struct node
{
    int dis, u;
    bool operator>(const node &a)
        const { return dis > a.dis; }
};
vector<edge> b[maxn];
priority_queue<node, vector<node>, greater<node>> q;
int vis[maxn], dis[maxn];
inline void dijkstra(int n, int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = 2147483647;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (auto i : b[u])
        {
            int v = i.v, w = i.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}
int main()
{
    int n, m, s, u1, v1, w1;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u1, &v1, &w1);
        b[u1].push_back({v1, w1});
    }
    dijkstra(n, s);
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
}