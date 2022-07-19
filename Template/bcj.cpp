#include <bits/stdc++.h>
using namespace std;
int fa[10005];
inline void makeset(int size)
{
    for (int i = 0; i < size; i++)
        fa[i] = i;
}
inline int findn(int x)
{
    if(fa[x]!=x)
    fa[x]=findn(fa[x]);
    return fa[x];
}
inline void unionset(int x,int y){
    x=findn(x);
    y=findn(y);
    fa[x]=y;
}
int main()
{
    int n, m, cz,x,y;
    cin >> n >> m;
    makeset(n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&cz,&x,&y);
        if(cz==1){  
            unionset(x,y);
        }
        if(cz==2){
            if(findn(x)==findn(y))
            printf("Y\n");
            else printf("N\n");
        }
    }
}