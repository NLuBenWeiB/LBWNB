#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1005;
int n,m,a[maxn][maxn],ans[maxn][maxn];
int read(){
    int x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if(c=='-')
        f=-1;
        c=getchar();
    } 
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
    }
    return x*f;
}
int road(int p){
    
}
int main(){
    n=read();
    m=read();
    int oo,pp,qq;
    for(int i=1;i<=m;i++){
        oo=read();
        pp=read();
        qq=read();
        a[oo][pp]=qq;
        a[pp][oo]=qq;
    }
    printf("%d",road(1));
}