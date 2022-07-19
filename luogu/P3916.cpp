#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100005;
inline int read()
{
    register int x = 0, f = 1;
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
inline void qwrite(register int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
        qwrite(x);
    }
    else
    {
        if (x > 9)
            qwrite(x / 10);
        putchar(x % 10 + '0');
    }
}
struct gg
{
    int to = -1, next = -1;
} a[maxn];
int head[maxn], dp[maxn];
inline void addg(register int from, register int to, register int i)
{
    a[i].next = head[from];
    head[from] = i;
    a[i].to = to;
}
inline void fin(register int p, register int from)
{
    if (dp[p] < from)
        dp[p] = from;
    for (int i = head[p]; i != -1; i = a[i].next)
        if (dp[a[i].to] < from)
            fin(a[i].to, from);
}
int main()
{
    memset(head, -1, sizeof(head));
    register int n, m, a1, b1;
    n = read();
    m = read();
    for (register int i = 1; i <= m; i++)
    {
        a1 = read();
        b1 = read();
        addg(b1, a1, i);
    }
    for (register int i = 1; i <= n; i++)
        dp[i] = i;
    for (register int i = n; i >= 1; i--)
        fin(i, i);
    for (register int i = 1; i <= n; i++)
        cout << dp[i] << " ";
}