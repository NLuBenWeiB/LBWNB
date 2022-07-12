#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, m, cnt;
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
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
    }
    return x * f;
}
struct Edge
{
    int to, w, next;
} edge[maxn];
int head[maxn];
void intt()
{
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    cnt = 0;
}
void add_edge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int main()
{
    n = read();
    m = read();
    int u, v, w;
    intt();
    for (int i = 1; i <= m; i++)
    {
        u = read();
        v = read();
        w = read();
        add_edge(u, v, w);
    }
}