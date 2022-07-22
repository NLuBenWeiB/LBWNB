#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct edge
{
    int v, w;
} op;
struct node
{
    int u, dis;
    bool operator>(const node &a)
        const { return dis > a.dis; }
};
priority_queue<node, vector<node>, greater<node>> q;
vector<edge> b[maxn];
int ans[maxn];
bool vis[maxn];
inline void dj(int n, int s)
{
    for (int i = 1; i <= n; i++)
        ans[i] = 2147483647;
    ans[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int ok = q.top().u;
        q.pop();
        if (vis[ok])
            continue;
        vis[ok] = 1;
        for (auto a : b[ok])
        {
            int v = a.v, w = a.w;
            if (ans[v] > ans[ok] + w)
            {
                ans[v] = ans[ok] + w;
                q.push({ans[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    int a1, b1, c1, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> a1 >> b1 >> c1;
        b[a1].push_back({b1,c1});
    }
    dj(n, s);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}