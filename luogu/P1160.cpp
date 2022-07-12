#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
struct T
{
    int l, r, d;
} t[maxn] = {0};
void add(int i, int k, int p)
{
    if (p == 1)
    {
        t[i].r = t[k].r;
        t[i].l = k;
        t[t[k].r].l = i;
        t[k].r = i;
    }
    else
    {
        t[i].r = k;
        t[i].l = t[k].l;
        t[t[k].l].r = i;
        t[k].l = i;
    }
}
int main()
{
    int x, k, p,m;
    cin >> n;
    t[0].r = 0;
    t[0].l = 0;
    add(0, 1, 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> k >> p;
        add(i, k, p);
    }
    cin>>m;
    while (m--)
    {
        cin >> x;
        t[x].d=1;
    }
    for(int i=t[0].r;i;i=t[i].r){
        if(t[i].d==0)
        cout<<i<<" ";
    }
}