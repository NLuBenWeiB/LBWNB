#include <bits/stdc++.h>
using namespace std;
char fuck[255];
int a[255], g;
struct gg
{
    int wz, maxn = -999;
} ff;
int main()
{
    int n, k;
    cin >> fuck;
    n = strlen(fuck);
    for (int i = 0; i < n; i++)
        a[i + 1] = fuck[i] - '0';
    cin >> k;
    for (int i = 1; i < n; i++)
    {
        if (k == 0)
            break;
        if (a[i] > a[i + 1])
        {
            for (int b = i; b < n; b++)
                a[b] = a[b + 1];
            n--;
            k--;
            i = 0;
        }
    }
    while (k > 0)
    {
        ff.maxn = -999;
        for (int q = 1; q <= n; q++)
            if (a[q] > ff.maxn)
            {
                ff.maxn = a[q];
                ff.wz = q;
            }
        for (int yu = ff.wz; yu < n; yu++)
            a[yu] = a[yu + 1];
        n--;
        k--;
    }
    if(n==0)
    cout<<0;
    else
    for (int i = 1; i <= n; i++)
    {
        if (g == 0 && a[i] == 0)
            continue;
        cout << a[i];
        g = 1;
        
    }
}