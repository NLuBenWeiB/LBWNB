#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
typedef pair<int, int> pii;
struct gg
{
    int x, y;
} a[maxn], b[maxn];
int res1[maxn], res2[maxn];
int n;
bool cmp(gg a, gg b)
{
    return a.x < b.x;
}
inline void calc(gg *t, int m, int *res)
{
    priority_queue<pii, vector<pii>, greater<pii>> lq;
    priority_queue<int, vector<int>, greater<int>> wq;
    for (int i = 1; i <= n; i++)
        wq.push(i);
    for (int i = 1; i <= m; i++)
    {
        while (!lq.empty() && t[i].x >= lq.top().first)
        {
            wq.push(lq.top().second);
            lq.pop();
        }
        if (wq.empty())
            continue;
        int dest = wq.top();
        wq.pop();
        res[dest]++;
        lq.push(make_pair(t[i].y, dest));
    }
    for (int i = 1; i <= n; i++)
        res[i] += res[i - 1];
}
int main()
{
    int m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= m1; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    for (int i = 1; i <= m2; i++)
        scanf("%d%d", &b[i].x, &b[i].y);
    sort(a + 1, a + 1 + m1, cmp);
    sort(b + 1, b + 1 + m2, cmp);
    calc(a, m1, res1);
    calc(b, m2, res2);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, res1[i] + res2[n - i]);
    }
    cout << ans << endl;
    return 0;
}