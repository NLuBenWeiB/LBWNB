#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int INF = 2147483647;
int n, m, cnt, head[maxn];
int d[maxn];
bool used[maxn];
struct Edge
{
    int to, w, next;
} edge[maxn];
void intt()
{
    for (int i = 1; i <= n; i++)
    {
        head[i] = -1;
        used[i] = 0;
        d[i] = INF;
    }
    cnt = 0;
}
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
void add_edge(int u, int v, int wi)
{
    edge[cnt].to = v;
    edge[cnt].w = wi;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dijkstra(int s)
{
    int minn, pos;
    while (1)
    {
        minn = INF;
        pos = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!used[i] && minn > d[i])
            {
                minn = d[i];
                pos = i;
            }
        }
        if (pos == -1)
            break;
        used[pos] = true;
        for (int i = head[pos]; i != -1; i = edge[i].next)
        {
            int t = edge[i].to;
            if (!used[t] && d[t] > (d[pos] + edge[i].w))
                d[t] = d[pos] + edge[i].w;
        }
    }
}
int main()
{
    int s;
    n = read();
    m = read();
    s = read();
    intt();
    d[s] = 0;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        u = read();
        v = read();
        w = read();
        add_edge(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}