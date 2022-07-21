#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define maxn 500005
using namespace std;
vector<int> v[maxn], w[maxn];
int fa[maxn][31], cost[maxn][31], dep[maxn];
int n, m, b, c, s;
struct gg
{
    vector<int> son, xd;
} a[maxn];
bool used[maxn];
inline void build(int p)
{
    for (int i = 0; i < a[p].xd.size(); i++)
        if (used[a[p].xd[i]] != 1)
        {
            a[p].son.push_back(a[p].xd[i]);
            used[a[p].xd[i]] = 1;
        }
    for (int i = 0; i < a[p].son.size(); i++)
        build(a[p].son[i]);
}
inline void dfs(int root,int from){
       fa[root][0]=from;
       dep[1];
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &b, &c);
        a[b].xd.push_back(c);
        a[c].xd.push_back(b);
    }
    build(s);
    dfs(s,0);
}