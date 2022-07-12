#include <iostream>
#include <queue>
#include <map>
using namespace std;
int dp[518028], n, ans, minn = 9999999, lj[518028];
bool used[518028];
queue<int> op;
map<int, int> ll, xhh;
struct
{
    int xh, jm;
} a[518028];
void dfs(int p)
{
    used[p] = 1;
    if (ll[p] != 0 && used[ll[p]] != 1)
    {
        op.push(ll[p]);
        lj[ll[p]] = lj[p] + 1;
    }
    if (a[p * 2].xh != 0 && used[a[p * 2].xh] != 1)
    {
        op.push(a[p * 2].xh);
        lj[a[p * 2].xh] = lj[p] + 1;
    }
    if (a[p * 2 + 1].xh != 0 && used[a[p * 2 + 1].xh] != 1)
    {
        op.push(a[p * 2 + 1].xh);
        lj[a[p * 2 + 1].xh] = lj[p] + 1;
    }
    ans += a[p].jm * lj[p];
    while (!op.empty())
    {
        int now = op.front();
        op.pop();
        dfs(now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= 204; i++)
    {
        ll[i] = 0;
        a[i].xh = 0;
    }
    a[1].xh = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].jm >> a[i * 2].xh >> a[i * 2 + 1].xh;
        ll[a[i * 2 + 1].xh] = i;
        ll[a[i * 2].xh] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        lj[i] = 0;
        dfs(i);
        dp[i] = ans;
        for (int ppp = 0; ppp <= 205; ppp++)
        {
            used[ppp] = 0;
            lj[ppp] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        minn = min(minn, dp[i]);
    cout << minn;
}