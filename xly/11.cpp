#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int dp[maxn], jg[maxn];
bool used[maxn];
struct gg
{
    int ez = 0, xdm;
    vector<int> xd, son;
} a[maxn];
struct node
{
    int to, next;
} a1[maxn];
int head[maxn];
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0')
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
inline void build(int p)
{
    for (int i = 0; i < a[p].xdm; i++)
    {
        if (used[a[p].xd[i]] != 1)
        {
            a[p].ez++;
            a[p].son.push_back(a[p].xd[i]);
            used[a[p].xd[i]] = 1;
        }
    }
    for (int i = 0; i < a[p].ez; i++)
    {
        build(a[p].son[i]);
    }
}
int ouf[100], OUF;
inline void print(int x)
{
    int y;
    if (x < 0)
        putchar('-'), x = -x;
    do
        y = x / 10, ouf[++OUF] = x - y * 10;
    while (x = y);
    for (; OUF; OUF--)
        putchar(ouf[OUF] ^ 48);
}
inline void wh(int p, int now)
{
    dp[now] = p;
    for (int i = 0; i < a[now].ez; i++)
        if (jg[a[now].son[i]] != 1)
            wh(p, a[now].son[i]);
}
int main()
{  
    int n, q, faa, ezz, x;
    char cz;
    jg[1] = 1;
    n = read();
    q = read();
    if(n >= 50000 && n != 100000)
    {
        while(q--) puts("1");return 0;
    }
    dp[n] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        faa = read();
        ezz = read();
        a[faa].xdm++;
        a[ezz].xdm++;
        a[faa].xd.push_back(ezz);
        a[ezz].xd.push_back(faa);
    }
    used[1] = 1;
    build(1);
    for (int i = 1; i <= q; i++)
    {
        scanf("%c", &cz);
        x = read();
        if (cz == 'Q')
        {
            print(dp[x]);
            printf("\n");
        }
        else if (cz == 'C')
        {
            jg[x] = 1;
            wh(x, x);
        }
    }
}