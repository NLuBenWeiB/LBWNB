#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxn=100005;
int n,m,k,t,grg,ans;
map<int,int> gr;
struct pp
{
    int t,gj;
}h;
queue<pp> op;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    scanf("%d%d",&t,&k);
    while (op.size()!=0)
    {
        h=op.front();
        if(h.t<=t-86400){
        gr[h.gj]--;
        if(gr[h.gj]==0)
        ans--;
        op.pop();    
        }
        else break;
        continue;
    }
    for(int gg=1;gg<=k;gg++){
        scanf("%d",&grg);
        gr[grg]++;
        if(gr[grg]==1)
        ans++;
        h.t=t;
        h.gj=grg;
        op.push(h);
    }
    printf("%d\n",ans);
    }
}