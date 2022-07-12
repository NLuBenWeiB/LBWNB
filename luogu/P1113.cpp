#include <bits/stdc++.h>
using namespace std;
int qqq[100005],maxn=-999;
bool used[100005];
struct gg
{
    int ez = 0, qz[105], len;
} a[10005];
int dp(int op)
{
    int zuida=-999;
    if (used[op] == 1)
        return qqq[op];
    if (a[op].ez == 0)
        return qqq[op];
    for (int i = 1; i <= a[op].ez; i++){
        zuida= max(dp(a[op].qz[i]),zuida);
        
    }
    qqq[op] +=zuida;
    used[op] = 1;
    return qqq[op];
}
int main()
{
    int n, qq,xh;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&xh);
        scanf("%d", &a[xh].len);
        qqq[xh] = a[xh].len;
        while (1)
        {
            scanf("%d", &qq);
            if (qq == 0)
                break;
            a[xh].ez++;
            a[xh].qz[a[xh].ez] = qq;
        }
    }
    for (int i = 1; i <= n; i++){
        qqq[i] = dp(i);
        maxn=max(qqq[i],maxn);
    }
    cout<<maxn;
}