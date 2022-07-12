#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
int a[maxn], op = -999, q = -999;
int ss(int p, int s)
{
    if (a[p * 2] != 0)
        op = max(op, ss(a[p * 2], s + 1));
    if (a[p * 2 + 1] != 0)
        q = max(q, ss(a[p * 2 + 1], s + 1));
    if (a[p * 2 + 1] == 0 && a[p * 2] == 0)
        return s;
    return max(op, q);
}
int main()
{
    int n, qq, wx;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> qq >> wx;
        a[i * 2] = qq;
        a[i * 2 + 1] = wx;
    }
    cout << ss(1, 1);
}