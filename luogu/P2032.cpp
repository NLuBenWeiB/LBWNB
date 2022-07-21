#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
int a[maxn], q[maxn], num[maxn], f[maxn], s[maxn], minn = 999999;
int n, head = 1, tail = 0, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[1] = 0;
    for (int i = 2; i <= k; i++)
    {
        minn = 99999999;
        for (int b = 1; b <= i; b++)
            minn = min(a[b], minn);
        f[i] = minn;
    }
    for (int i = 1; i <= k; i++)
    printf("%d\n",f[i]);
        for (int i = 1; i < n; i++)
        {
            while (num[head] < i - k + 1 && head <= tail)
                head++;
            while (a[i] <= q[tail] && head <= tail)
                tail--;
            num[++tail] = i;
            q[tail] = a[i];
            s[i] = q[head];
        }
    for (int i = k; i < n; i++)
        printf("%d\n", s[i]);
}