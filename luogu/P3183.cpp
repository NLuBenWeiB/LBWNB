#include <bits/stdc++.h>
using namespace std;
long long dp[100005], answer = 0;
bool bs[100005], used[100005];
struct gg
{
    int ans = 0, ez = 0;
    vector<int> b;
} a[100005];
long long bfs(int p)
{

    if(used[p]==1)
        return a[p].ans;
    a[p].ans = 0;
    if (a[p].ez == 0 && bs[p] != 0)
        return 1;
    for (int i = 0; i < a[p].ez; i++)
    {
        a[p].ans += bfs(a[p].b[i]);
    }
    used[p] = 1;
    return a[p].ans;
}
int main()
{
    int n, m, s, d;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s, &d);
        bs[d] = 1;
        a[s].b.push_back(d);
        a[s].ez++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (bs[i] == 0)
        {
            answer+=bfs(i);
        }
    }
    cout << answer;
}