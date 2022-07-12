#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 100000;
map<char, int> op, lp, rp;
struct gg
{
    char bs, rs, ls;
    int fx, rsx, lsx, xh;
} a[100000];
int findg(int n)
{
    for (int i = 1; i <= n; i++)
        if (op[a[i].bs] == 0)
            return a[i].xh;
}
void findn(int p,int n)
{
    cout << a[p].bs;
    if (a[p].ls != '*')
    {
        for(int i = 1; i <= n; i++)
        {
            if (a[i].bs == a[p].ls)
            {
                findn(i,n);
                break;
            }
        }
    }
    if (a[p].rs != '*')
    {
        for(int i = 1; i <= n; i++)
        {
            if (a[i].bs == a[p].rs)
            {
                findn(i,n);
                break;
            }
        }
    }
}
int main()
{
    int n, gen;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        op['a' + i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].bs >> a[i].ls >> a[i].rs;
        a[i].xh = i;
        op[a[i].ls] = i;
        op[a[i].rs] = i;
    }
    gen = findg(n);
    findn(gen,n);
}
