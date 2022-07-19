#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
long long dp[100005], answer = 0;
bool bs[100005], used[100005];
=======
long long dp[5005], answer = 0;
bool bs[5005], used[5005];
>>>>>>> c226a08fb809908a656d0e17713339ec4aaae1d3
struct gg
{
    int ans = 0, ez = 0;
    vector<int> b;
<<<<<<< HEAD
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
        a[p].ans%=80112002;
    }
    used[p] = 1;
=======
} a[5005];
long long bfs(int p)
{
    if (a[p].ez == 0)
        return 1;
    if (a[p].ans != 0)
        return a[p].ans;
    a[p].ans = 0;
    for (int i = 0; i < a[p].ez; i++)
    {
        a[p].ans += bfs(a[p].b[i]);
    }
>>>>>>> c226a08fb809908a656d0e17713339ec4aaae1d3
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
<<<<<<< HEAD
        {
            answer+=bfs(i);
        }
=======
            answer = max(bfs(i), answer);
>>>>>>> c226a08fb809908a656d0e17713339ec4aaae1d3
    }
    cout << answer%80112002;
}