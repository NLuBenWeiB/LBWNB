#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
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
        c = getchar();
    }
    return x * f;
}
struct gg
{
    int arrive, leave;
} a[maxn], b[maxn];
priority_queue<int, vector<int>, greater<int>> l;
inline bool cmp(gg p, gg q)
{
    return p.arrive < q.arrive;
}
inline int findn(int n, int m1, int ans)
{
    if (n == 0)
        return 0;
    for (int i = 1; i <= m1; i++)
    {
        if (!l.empty() && a[i].arrive > l.top())
        {
            n++;
            l.pop();
        }
        if (n > 0)
        {
            l.push(a[i].leave);
            ans++;
            n--;
        }
    }
    return ans;
}
inline int findw(int n, int m2, int ans)
{
    if (n == 0)
        return 0;
    for (int i = 1; i <= m2; i++)
    {
        if (!l.empty() && b[i].arrive > l.top())
        {
            n++;
            l.pop();
        }
        if (n > 0)
        {
            l.push(b[i].leave);
            ans++;
            n--;
        }
    }
    return ans;
}
int main()
{
    register int n, m1, m2, ans = 0, answer = 0;
    n = read();
    m1 = read();
    m2 = read();
    for (int i = 1; i <= m1; i++)
    {
        a[i].arrive = read();
        a[i].leave = read();
    }
    for (int i = 1; i <= m2; i++)
    {
        b[i].arrive = read();
        b[i].leave = read();
    }
    sort(a + 1, a + 1 + m1, cmp);
    sort(b + 1, b + 1 + m2, cmp);
    for (int i = 0; i <= n; i++)
    {
        ans = 0;
        ans += findn(i, m1, 0);
        while (!l.empty())
            l.pop();
        ans += findw(n - i, m2, 0);
        while (!l.empty())
            l.pop();
        answer = max(ans, answer);
    }
    printf("%d", answer);
}