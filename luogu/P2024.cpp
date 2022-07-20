#include <bits/stdc++.h>
using namespace std;
const int maxn = 900005;
int a[maxn], ans = 0;
inline int read()
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
inline int findn(int x)
{
    if (a[x] != x)
    a[x]=findn(a[x]);
    return a[x];
}
inline int hb(int x, int y)
{
    int fx = findn(a[x]), fy = findn(a[y]);
    a[fx] = fy;
}
int main()
{
    int n, k, cz, x, y;
    n = read();
    k = read();
    for (int i = 1; i <= 3 * n; i++)
        a[i] = i;
    for (int i = 1; i <= k; i++)
    {
        cz = read();
        x = read();
        y = read();
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (cz == 1)
        {
            if (findn(x + n) == findn(y) || findn(x + 2 * n) == findn(y))
            {
                ans++;
                continue;
            }
            hb(x, y);
            hb(x+n,y+n);
            hb(x+2*n,y+2*n);
        }
        else if (cz == 2)
        {
            if(x==y){
                ans++;
                continue;
            }
           if(findn(x)==findn(y)||findn(x+2*n)==findn(y)){
            ans++;
            continue;
           }
           hb(x,y+2*n);
           hb(x+2*n,y+n);
           hb(x+n,y);
        }
    }
    cout << ans;
}