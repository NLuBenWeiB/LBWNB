#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
int n;
map<int, int> op;
int main()
{
    int xh, m, cx,xih;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&xh);
        op[i] = xh;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&xih);
        cout << op[xih]<<endl;
    }
}