#include <bits/stdc++.h>
using namespace std;
int dep[10000],f[10000][10000];
inline void ycl(int u, int father)
{
    dep[u]=dep[father]+1;
    for(int i=0;i<=19;i++)
    f[u][i+1]=f[f[u][i]][i];
    for(int e){
        
    }
}
int main()
{
}