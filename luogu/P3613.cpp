#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct gg
{
    map<int,int> gz;
} a[maxn];
int main()
{
    int n, q, cz,ii,jj,kk;
    cin>>n>>q;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &cz);
        if (cz == 1)
        {
            scanf("%d%d%d",&ii,&jj,&kk);
            a[ii].gz[jj]=kk;
        }
        else
        {
            scanf("%d%d",&ii,&jj);
            printf("%d\n",a[ii].gz[jj]);
        }
    }
}