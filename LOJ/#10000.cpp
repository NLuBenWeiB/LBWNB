#include <bits/stdc++.h>
using namespace std;
struct gg
{
    int s, o;
} a[1005];
bool cmp(gg a, gg b)
{
    return a.o < b.o;
}
int main()
{
    int n, ans=1, now;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].o;
    }
    sort(a + 1, a + 1 + n, cmp);
    now=a[1].o;
    for (int i = 2; i <= n; i++)
    {
        if (now <= a[i].s)
        {
            ans++;
            now=a[i].o;
        }
    }
    cout << ans;
}